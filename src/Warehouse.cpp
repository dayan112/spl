#include <string>
#include <vector>

using namespace std;

#include "../include/Volunteer.h"
#include "../include/Customer.h"
#include "../include/Action.h"
#include "../include/WareHouse.h"
#include "../include/Order.h"

WareHouse::WareHouse(const string &configFilePath);//todo


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
void WareHouse::addVolunteer(Action* volunteer){
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
    return Customer(-1,"",-1, -1); //customer not found

}
Volunteer& WareHouse::getVolunteer(int volunteerId) const {
    for (Volunteer* v : volunteers) {
        if (v != nullptr && v->getId() == volunteerId) {
            return *v; 
        }
    }
    return Volunteer(-1,""); //volunteer not found

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
    
    return Order(-1,-1,-1); //order not found
}

void WareHouse::start(){    
    while(isOpen){
        getline(cin, input)
        Action* action = parseInputToAction(input);
        action->act():  
    }
}

void WareHouse::eraseVolunteer(Volunteer* v){
    for(int i = 0; i < volunteers.size(); i++){
        if(volunteers[i] == v){
            volunteers.erase(i);
            delete v;
            break;
        }
    }
}

bool WareHouse::moveOrderForward(Order* o, int fromList, int toList){
    vector<Order*> curr_vector;
    vector<Order*> next_vector;
    switch (fromList){
        case 0:
            curr_vector = pendingOrders;
            break;
        case 1:
            curr_vector = inProcessOrders;
            break;
        default: //cant be moved from the last vector
            return false; 
    }
    switch (toList){
        case 0:
            next_vector = pendingOrders;
            break;
        case 1:
            next_vector = inProcessOrders;
            break;
        case 2:
            next_vector = completedOrders;
            break;
        default: 
            return false; 
    }
    int ordersPlace = -1;
    for(int i = 0; i < curr_vector.size(); i++){
        if(curr_vector[i] == o){
            ordersPlace = i;
        }
    }
    if(ordersPlace != -1){
        curr_vector.erase(ordersPlace);
        next_vector.push_back(o);
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
        for(int i = 0; i < line.size()){
            if(line[i].size() == 0) continue;
            if(line[i][o] >= 'a' & line[i][o] <= 'z'){
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

    switch (action){
        case "step":
            if()
            return new SimulateStep::SimulateStep((int)totalInput[1]);
        case "order":
            return new AddOrder::AddOrder((int)totalInput[1]);
        case "customer":
            return new AddCustomer::AddCustomer(totalInput[1], totalInput[2], (int)totalInput[3], (int)totalInput[4]);
        case "customerStatus":
            return new PrintCustomerStatus::PrintCustomerStatus((int)totalInput[1]);
        case "orderStatus":
            return new PrintOrderStatus::PrintOrderStatus((int)totalInput[1]);
        case "volunteerStatus":
            return new PrintVolunteerStatus::PrintVolunteerStatus((int)totalInput[1]);
        case "log":
            return new PrintActionsLog::PrintActionsLog();
        case "close":
            return new Close::Close();
        case "backup":
            return new BackupWareHouse::BackupWareHouse();
        case "restore":
            return new RestoreWareHouse::RestoreWareHouse();        
        default:
            break;
    }
}
bool WareHouse::getOpeness(){
    return isOpen;
}

int getCounters(int i){
    if(i = 0){
        return customerCounter;
    }
    return volunteerCounter;
}


WareHouse::WareHouse(WareHouse& other){
    
    isOpen = other->getOpeness();
    customerCounter = other->getCounters(0);
    volunteerCounter = other->getCounters(1);

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


WareHouse* WareHouse::clone(){
    return new WareHouse(*this);
}