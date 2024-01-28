#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "../include/Volunteer.h"
#include "../include/Customer.h"
#include "../include/Action.h"
#include "../include/WareHouse.h"
#include "../include/Order.h"
#include "../include/FileHandler.h"
#include <iostream>



WareHouse::WareHouse(const string &configFilePath):isOpen(false), customerCounter(0), volunteerCounter(0), orderCounter(0){
    this->setup(configFilePath);
}

SoldierCustomer WareHouse::dummyCustomer = SoldierCustomer(-1,"",-1,-1);
CollectorVolunteer WareHouse::dummyVolunteer = CollectorVolunteer(-1,"",-1);
Order WareHouse::dummyOrder = Order(-1,-1,-1);

const vector<Order*>& WareHouse::getOrders(int o_status) const {
    if(o_status == 0)
        return pendingOrders;
    if(o_status == 1)
        return inProcessOrders;
    return completedOrders;

} 

const vector<Volunteer*>& WareHouse::getVolunteers() const{
    return volunteers;
}

const vector<Customer*>& WareHouse::getCustomers() const{
    return customers;
}
void WareHouse::addOrder(Order* order){
    pendingOrders.push_back(order);

}
void WareHouse::addCustomer(Customer* customer){
    customers.push_back(customer);
}
void WareHouse::addVolunteer(Volunteer* volunteer){
    volunteers.push_back(volunteer);
}
void WareHouse::addAction(Action* action){
    actions.push_back(action);
}

const vector<Action*>& WareHouse::getActions() const {
    return actions;
}
Customer& WareHouse::getCustomer(int customerId) const {
    for (Customer* c : customers) {
        if (c != nullptr && c->getId() == customerId) {
            return *c; 
        }
    }
    return dummyCustomer; //customer not found so we create a fake customer with id -1;

}
Volunteer& WareHouse::getVolunteer(int volunteerId) const {
    for (Volunteer* v : volunteers) {
        if (v != nullptr && v->getId() == volunteerId) {
            return *v; 
        }
    }
    return dummyVolunteer; //volunteer not found

}


Order& WareHouse::getOrder(int orderId) const{
    for (Order* o : pendingOrders) {
        if (o != nullptr && o->getId() == orderId) {
            return *o; 
        }
    }
    for (Order* o : inProcessOrders) {
        if (o != nullptr && o->getId() == orderId) {
            return *o; 
        }
    }
    for (Order* o : completedOrders) {
        if (o != nullptr && o->getId() == orderId) {
            return *o; 
        }
    }
    
    return dummyOrder; //order not found
}

void WareHouse::start(){   
    Action* action;
    string input; 
    while(isOpen){
        cout << ">>>>> ";
        getline(cin, input);
        //testing
        cout <<"Input - "  + input << endl;
        Action* action = parseInputToAction(input); 
        action->act(*this);  
    }
}

void WareHouse::eraseVolunteer(Volunteer* v){
    auto it = std::find(volunteers.begin(), volunteers.end(), v);
    if (it != volunteers.end()) {
        volunteers.erase(it);
        delete v;
    }
    
}

bool WareHouse::moveOrderForward(Order* o, int fromList, int toList){
    vector<Order*>* curr_vector;
    vector<Order*>* next_vector;
    //testing
    std::cout<< "Order moving forward  - \n" + std::to_string(o->getId()) << std::endl;  
    switch (fromList){
        case 0:
            curr_vector = &pendingOrders;
            break;
        case 1:
            curr_vector = &inProcessOrders;
            break;
        default: //cant be moved from the last vector
            return false; 
    }
    switch (toList){
        case 0:
            next_vector = &pendingOrders;
            break;
        case 1:
            next_vector = &inProcessOrders;
            break;
        case 2:
            next_vector = &completedOrders;
            break;
        default: 
            return false; 
    }
    int ordersPlace = -1;
    for(int i = 0; i < curr_vector->size(); i++){
        if((*curr_vector)[i] == o){
            ordersPlace = i;
        }
    }
    if(ordersPlace != -1){
        curr_vector->erase(curr_vector->begin() + ordersPlace);
        next_vector->push_back(o);
        return true;
    }
    return false;
}


void WareHouse::close(){
    string result = "";
    for(Order* o : pendingOrders){
        result += o->toString() + "\n";
    }
    for(Order* o : inProcessOrders){
        result += o->toString() + "\n";
    }
    for(Order* o : completedOrders){
        result += o->toString() + "\n";
    }
    isOpen = false;
    this->~WareHouse();
}

void WareHouse::setup(const string& path){
    FileHandler file(path);
    file.FileToWordsMatrix();

    vector<vector<string>>& words = file.getWords();

    for(vector<string> line : words){
        int start_index = 0;
        for(int i = 0; i < line.size(); i++){
            if(line[i].size() == 0) continue;
            if(line[i][0] >= 'a' && line[i][0] <= 'z'){
                start_index = i;
                if(line.size() - start_index < 3)
                    start_index = 0;
                break;
            }
        }
        if(start_index == 0) continue;
        if(line[start_index] == "customer"){
            if(line.size() - start_index < 5){//not enough params
                continue;
            }
            string name = line[start_index+1];
            int distance = stoi(line[start_index+3]);
            int max_orders = stoi(line[start_index+4]);
            if(line[start_index+2] == "soldier"){
                customers.push_back(new SoldierCustomer(customerCounter++,name,distance,max_orders));
            }
            if(line[start_index+2] == "civilian"){
                customers.push_back(new CivilianCustomer(customerCounter++,name,distance,max_orders));
            }
        }

        if(line[start_index] == "volunteer"){
            string name = line[start_index + 1];
            if(line[start_index + 2] == "collector"){
                if(line.size() - start_index < 4) continue;
                int cooldown = stoi(line[start_index + 3]);
                volunteers.push_back(new CollectorVolunteer(volunteerCounter++,name,cooldown));
            }


            if(line[start_index + 2] == "limited_collector"){
                if(line.size() - start_index < 5) continue;
                int cooldown = stoi(line[start_index + 3]);
                int max_orders = stoi(line[start_index + 4]);
                volunteers.push_back(new LimitedCollectorVolunteer(volunteerCounter++,name,cooldown,max_orders));
            }


            if(line[start_index + 2] == "driver"){
                if(line.size() - start_index < 5) continue;
                int max_distance = stoi(line[start_index + 3]);
                int d_per_step = stoi(line[start_index + 4]);
                volunteers.push_back(new DriverVolunteer(volunteerCounter++,name,max_distance,d_per_step));
            }


            if(line[start_index + 2] == "limited_driver"){
                if(line.size() - start_index < 6) continue;
                int max_distance = stoi(line[start_index + 3]);
                int d_per_step = stoi(line[start_index + 4]);
                int max_orders = stoi(line[start_index + 5]);
                volunteers.push_back(new LimitedDriverVolunteer(volunteerCounter++,name,max_distance,d_per_step,max_orders));
            }
        }
    }
}

void WareHouse::open(){
    isOpen = true;
    cout << "The warehouse is open!" << endl;
}

Action* WareHouse::parseInputToAction(string input){
    vector<string> totalInput;
    string token;
    size_t start = 0, end = 0;

    while ((end = input.find(" ", start)) != string::npos) {
        token = input.substr(start, end - start);
        totalInput.push_back(token);
        start = end + 1;
    }

    totalInput.push_back(input.substr(start));  
    
    string action = totalInput[0];

    //testing
    cout <<"action - "  + action << endl;
    if(action == "step" && totalInput.size() > 1){
        return new SimulateStep(std::stoi(totalInput[1]));
    }
    else if(action == "restore"){
        return new RestoreWareHouse();
    }
    else if(action == "backup"){
        return new BackupWareHouse();
    }
    else if(action == "close"){
        return new Close();
    }
    else if(action == "log"){
        return new PrintActionsLog();
    }
    else if(action == "volunteerStatus" && totalInput.size() > 1){
        return new PrintVolunteerStatus(std::stoi(totalInput[1]));
    }
    else if(action == "orderStatus" && totalInput.size() > 1){
        return new PrintOrderStatus(std::stoi(totalInput[1]));
    }
    else if(action == "customerStatus" && totalInput.size() > 1){
        return new PrintCustomerStatus(std::stoi(totalInput[1]));
    }
    else if(action == "customer" && totalInput.size() > 4){
        return new AddCustomer(totalInput[1], totalInput[2], std::stoi(totalInput[3]), std::stoi(totalInput[4]));
    }
    else if(action == "order" && totalInput.size() > 1){
        return new AddOrder(std::stoi(totalInput[1]));
    }

    return nullptr;    
}
bool WareHouse::getOpeness() const{
    return isOpen;
}
void WareHouse::incrementID(int i){
    if(i == 0){
        customerCounter++;
        return;
    }
    if(i == 1){
        orderCounter++;
        return;
    }
    volunteerCounter++;
    return;
}
int WareHouse::getCounters(int i) const {
    if(i == 0){
        
        return customerCounter;
    }
    if(i == 1){
        
        return orderCounter;
    }
    
    return volunteerCounter;
}


WareHouse::WareHouse(const WareHouse& other){
    
    isOpen = other.getOpeness();
    customerCounter = other.getCounters(0);
    volunteerCounter = other.getCounters(1);

    //Copy Actions
    for (const auto& action : other.getActions()) {
        actions.push_back(action->clone()); 
    }

    //Copy Volunteers
    for (const auto& volunteer : other.getVolunteers()) {
        volunteers.push_back(volunteer->clone()); 
    }

    //Copy Customers
    for (const auto& customer : other.getCustomers()) {
        customers.push_back(customer->clone()); 
    }

    //Copy Orders
    for (const auto& order : other.getOrders(0)) {
        pendingOrders.push_back(order->clone()); 
    }
    for (const auto& order : other.getOrders(1)) {
        inProcessOrders.push_back(order->clone()); 
    }
    for (const auto& order : other.getOrders(2)) {
        completedOrders.push_back(order->clone()); 
    }
    
    
}

 WareHouse& WareHouse::operator=(WareHouse&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        //Cleaning up this wearehouse to avoid memory leaks.
        this->~WareHouse();

        //Transfer data.
        isOpen = other.isOpen;
        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;
        actions = std::move(other.actions);
        volunteers = std::move(other.volunteers);
        pendingOrders = std::move(other.pendingOrders);
        inProcessOrders = std::move(other.inProcessOrders);
        completedOrders = std::move(other.completedOrders);
        customers = std::move(other.customers);

        other.customerCounter = 0;
        other.volunteerCounter = 0;
        

        return *this;
}

WareHouse::~WareHouse() {
        
        for (auto action : actions) {
            delete action;
        }

        
        for (auto volunteer : volunteers) {
            delete volunteer;
        }

        auto deleteOrders = [](const std::vector<Order*>& orders) {
            for (auto order : orders) {
                delete order;
            }
        };
        deleteOrders(pendingOrders);
        deleteOrders(inProcessOrders);
        deleteOrders(completedOrders);

        for (auto customer : customers) {
            delete customer;
        }
}


WareHouse* WareHouse::clone() const{
    return new WareHouse(*this);
}

string WareHouse::customerStatus(int customerID) const{
    Customer& c = getCustomer(customerID);
    string result = "CustomerID: " + std::to_string(c.getId()) + "\n";
    for(Order* o : pendingOrders){
        if(o->getCustomerId() == c.getId()){
            result += "OrderID:" + std::to_string(o->getId()) + "\n" +
            "OrderStatus: " + o->statusToString() + "\n";
        }
    }
    for(Order* o : inProcessOrders){
        if(o->getCustomerId() == c.getId()){
            result += "OrderID:" + std::to_string(o->getId()) + "\n" +
            "OrderStatus: " + o->statusToString() + "\n";
        }
    }
    for(Order* o : completedOrders){
        if(o->getCustomerId() == c.getId()){
            result += "OrderID:" + std::to_string(o->getId()) + "\n" +
            "OrderStatus: " + o->statusToString() + "\n";
        }
    }
    int ordLeft = (c.getMaxOrders() - c.getNumOrders());
    result += "numOrdersLeft: " + std::to_string(ordLeft) + "\n";
    return result;
}