#include "../include/Volunteer.h"
using namespace std;
#include <iostream>


CollectorVolunteer::CollectorVolunteer(int id, string name, int coolDown) 
    : Volunteer(id, name), coolDown(coolDown), timeLeft(0) {}

CollectorVolunteer* CollectorVolunteer::clone() const {
    return new CollectorVolunteer(*this);
}

void CollectorVolunteer::step() {
    if(timeLeft > 0 ){
        if(decreaseCoolDown()){
            completedOrderId = activeOrderId;
            cout << getName() + " has finished proccessing order number - " + to_string(getActiveOrderId()) << endl;
            activeOrderId = NO_ORDER;
        }
    }
}

int CollectorVolunteer::getCoolDown() const { return coolDown;}

int CollectorVolunteer::getTimeLeft() const {  return timeLeft;}

bool CollectorVolunteer::decreaseCoolDown() {
    //testing
    cout << to_string(getId()) + " <- volunteer cd is " + to_string(timeLeft) << endl;
    if (timeLeft > 0) 
        timeLeft--;
    
        
    return timeLeft == 0;
}

bool CollectorVolunteer::hasOrdersLeft() const {
    return true; //Not limited volunteer, always true
}

bool CollectorVolunteer::canTakeOrder(const Order &order) const {
    return activeOrderId == NO_ORDER && hasOrdersLeft() && timeLeft == 0 && order.getStatus() == OrderStatus::PENDING;
}

void CollectorVolunteer::acceptOrder(const Order &order) {
    timeLeft = coolDown;
    activeOrderId = order.getId();
}

string CollectorVolunteer::toString() const {
    string active_ord = activeOrderId == NO_ORDER ? "None" : to_string(activeOrderId);
    string result = "VolunteerID: " + to_string(getId()) + "\n"
                    + "isBusy: " + to_string(isBusy()) + "\n"
                    + "OrderId: " + active_ord + "\n"
                    + "timeLeft: " + to_string(timeLeft) + "\n"
                    + "ordersLeft: No Limit\n";
        
    return result;
   
}