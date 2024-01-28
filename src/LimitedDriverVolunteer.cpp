#include "../include/Volunteer.h"

using namespace std;

LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep,int maxOrders)
    : DriverVolunteer(id, name, maxDistance, distancePerStep), maxOrders(maxOrders), ordersLeft(maxOrders) {}


LimitedDriverVolunteer* LimitedDriverVolunteer::clone() const {
    return new LimitedDriverVolunteer(*this);
}


bool LimitedDriverVolunteer::hasOrdersLeft() const {
    return ordersLeft > 0;
}

bool LimitedDriverVolunteer::canTakeOrder(const Order &order) const {
    return hasOrdersLeft() && DriverVolunteer::canTakeOrder(order);
}

void LimitedDriverVolunteer::acceptOrder(const Order &order) {
    ordersLeft--;
    DriverVolunteer::acceptOrder(order);
}

int LimitedDriverVolunteer::getMaxOrders() const {return maxOrders;}
int LimitedDriverVolunteer::getNumOrdersLeft() const {return ordersLeft;}

string LimitedDriverVolunteer::toString() const {
    string active_ord = activeOrderId == NO_ORDER ? "None" : to_string(activeOrderId);
    string result = "VolunteerID: " + to_string(getId()) + "\n"
                    + "isBusy: " + to_string(isBusy()) + "\n"
                    + "OrderId: " + active_ord + "\n"
                    + "distance left: " + to_string(getDistanceLeft()) + "\n"
                    + "distance per step " + to_string(getDistancePerStep()) + "\n"
                    + "ordersLeft: " + to_string(ordersLeft) + "\n"
                    + "Max Orders: " + to_string(maxOrders) + "\n";
        
    return result;
}