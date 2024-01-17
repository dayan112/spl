#include "../include/Volunteer.h"


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
    string result = DriverVolunteer::toString();
     
    result +=  std::to_string(ordersLeft);
    result += "\nMax Orders: " + std::to_string(maxOrders);
    

    return result;
}