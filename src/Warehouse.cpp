#include <string>
#include <vector>

using namespace std;

#include "../include/Volunteer.h"
#include "../include/Customer.h"
#include "../include/Action.h"
#include "../include/WareHouse.h"
#include "../include/Order.h"

WareHouse(const string &configFilePath);


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


void WareHouse::open(){
    isOpen = true;
}