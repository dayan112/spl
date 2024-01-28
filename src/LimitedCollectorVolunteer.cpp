#include "../include/Volunteer.h"
using namespace std;

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
    string active_ord = activeOrderId == NO_ORDER ? "None" : to_string(activeOrderId);
    string result = "VolunteerID: " + to_string(getId()) + "\n"
                    + "isBusy: " + to_string(isBusy()) + "\n"
                    + "OrderId: " + active_ord + "\n"
                    + "timeLeft: " + to_string(getTimeLeft()) + "\n"
                    + "ordersLeft: "+ to_string(ordersLeft) + "\n"
                    + "Max Orders: " + to_string(maxOrders) + "\n";
        
    return result;
}