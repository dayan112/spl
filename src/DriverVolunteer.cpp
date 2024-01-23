#include "../include/Volunteer.h"
using namespace std;



DriverVolunteer::DriverVolunteer(int id, string name, int maxDistance, int distancePerStep) 
    : Volunteer(id, name), maxDistance(maxDistance), distancePerStep(distancePerStep) {}

DriverVolunteer* DriverVolunteer::clone() const {
    return new DriverVolunteer(*this);
}

int DriverVolunteer::getDistanceLeft() const {return distanceLeft;}
int DriverVolunteer::getMaxDistance() const {return maxDistance;}
int DriverVolunteer::getDistancePerStep() const {return distancePerStep;}

//Decrease distanceLeft by distancePerStep,return true if distanceLeft<=0,false otherwise
bool DriverVolunteer::decreaseDistanceLeft() {
    distanceLeft -= distancePerStep;
    if(distanceLeft <= 0){
        distanceLeft = 0;
        return true;
    }
    return false;
}

bool DriverVolunteer::hasOrdersLeft() const {
    return true;
}

 // Signal if the volunteer is not busy and the order is within the maxDistance
bool DriverVolunteer::canTakeOrder(const Order &order) const {
    return hasOrdersLeft() && activeOrderId == NO_ORDER && order.getDistance() <= maxDistance && order.getStatus() == OrderStatus::COLLECTING;
}

// Reset distanceLeft to order.distance
void DriverVolunteer::acceptOrder(const Order &order) {
    distanceLeft = order.getDistance();
    activeOrderId = order.getId(); 
} 

// Decrease distanceLeft by distancePerStep
void DriverVolunteer::step() {
    if(distanceLeft > 0){
        if(decreaseDistanceLeft()){
            completedOrderId = activeOrderId;
            activeOrderId = NO_ORDER;
        }
    }
} 

string DriverVolunteer::toString() const {
    string result = "VolunteerID: " + to_string(getId()) + "\n"
                    + "isBusy: " + to_string(isBusy()) + "\n"
                    + "OrderId: " + to_string(getActiveOrderId()) + "\n"
                    + "distance left: " + to_string(distanceLeft) + "\n"
                    + "distance per step " + to_string(distancePerStep) + "\n"
                    + "ordersLeft: ";
        
    return result;
}
