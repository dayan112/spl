#include "../include/Volunteer.h"


LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, string name, int coolDown ,int maxOrders)
    : CollectorVolunteer(id, name, coolDown), maxOrders(maxOrders), ordersLeft(maxOrders) {}


LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const {
    return new LimitedCollectorVolunteer(*this);
}


bool LimitedCollectorVolunteer::hasOrdersLeft() const {
    return ordersLeft > 0;
}

bool LimitedCollectorVolunteer::canTakeOrder(const Order &order) const {
    return hasOrdersLeft() && CollectorVolunteer::canTakeOrder(order);
}

void LimitedCollectorVolunteer::acceptOrder(const Order &order) {
    ordersLeft--;
    CollectorVolunteer::acceptOrder(order);
}

int LimitedCollectorVolunteer::getMaxOrders() const {return maxOrders;}
int LimitedCollectorVolunteer::getNumOrdersLeft() const {return ordersLeft;}

string LimitedCollectorVolunteer::toString() const {
    string result = CollectorVolunteer::toString();
     
    result +=  std::to_string(ordersLeft);
    result += "\nMax Orders: " + std::to_string(maxOrders);
    

    return result;
}