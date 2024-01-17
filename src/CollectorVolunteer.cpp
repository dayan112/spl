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
    if (timeLeft > 0) 
        timeLeft--;
        
    return timeLeft == 0;
}

bool CollectorVolunteer::hasOrdersLeft() const {
    return true; //Not limited volunteer, always true
}

bool CollectorVolunteer::canTakeOrder(const Order &order) const {
    return activeOrderId == NO_ORDER && hasOrdersLeft() && timeLeft == 0;
}

void CollectorVolunteer::acceptOrder(const Order &order) {
    timeLeft = coolDown;
    activeOrderId = order.getId();
}

string CollectorVolunteer::toString() const {
    string result = "VolunteerID: " + to_string(getId()) + "\n"
                    + "isBusy: " + to_string(isBusy()) + "\n"
                    + "OrderId: " + to_string(getActiveOrderId()) + "\n"
                    + "timeLeft: " + to_string(timeLeft) + "\n"
                    + "ordersLeft: ";
        
    return result;
   
}