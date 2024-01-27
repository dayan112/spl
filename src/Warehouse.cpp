#include <string>
#include <vector>

using namespace std;

#include "Volunteer.h"
#include "Customer.h"
#include "Action.h"
#include "WareHouse.h"
#include "Order.h"
#include "FileHandler.h"

WareHouse::WareHouse(const string &configFilePath){
    this->setup(configFilePath);
    this->open();
}



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
    customers.push_back(order);
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
    //Here is the main loop, 
    //We need to stimulateSteps (from action) here and make the warehouse work
    //todo

}

void eraseVolunteer(Volunteer* v){
    for(int i = 0; i < volunteers.size(); i++){
        if(volunteers[i] == v){
            volunteers.erase(i);
            delete v;
            break;
        }
    }
}

bool moveOrderForward(Order* o, int fromList, int toList){
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
    //Need to destruct everything here. 
    //Destructor for all 3 orders.
    //Destructor for all customers.
    //Destructor for all volunteers.
    //Destructor for all actions.
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
}