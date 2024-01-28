#include "../include/Order.h"
using namespace std;



Order::Order(int id, int customerId, int distance): 
    id(id), customerId(customerId), distance(distance),
    status(OrderStatus::PENDING), collectorId(NO_VOLUNTEER), driverId(NO_VOLUNTEER) {}



int Order::getId() const {return id;}
int Order::getCustomerId() const {return customerId;}
int Order::getCollectorId() const {return collectorId;}
int Order::getDriverId() const {return driverId;}
int Order::getDistance() const { return distance;}

void Order::setStatus(OrderStatus status) { this->status = status; }
void Order::setCollectorId(int collectorId) { this->collectorId = collectorId; }
void Order::setDriverId(int driverId) { this->driverId = driverId; }

OrderStatus Order::getStatus() const {return status;}


string Order::statusToString() const{
    string status_temp;
    switch (this->status) {
        case OrderStatus::PENDING:
            status_temp = "Pending";
            break;
        case OrderStatus::COLLECTING:
            status_temp = "Collecting";
            break;
        case OrderStatus::COMPLETED:
            status_temp = "Completed";
            break;
        case OrderStatus::DELIVERING:
            status_temp = "Delivering";
            break;
        default:
            status_temp = "Unknown Status";
            break;
        }

    return status_temp;
}


const string Order::toString() const {
    
    string status_temp = statusToString();
    std::string result = "OrderId: " + std::to_string(id) + "\n"
                    + "OrderStatus: ";
        result += status_temp + "\n"
                + "CustomerID: " + std::to_string(customerId) + "\n"
                + "Collector: ";

    if (collectorId != NO_VOLUNTEER)
        result += std::to_string(collectorId);
    else
        result += "None";

    result += "\nDriver: ";

    if (driverId != NO_VOLUNTEER)
        result += std::to_string(driverId);
    else
        result += "None";
    
    return result;
}

Order* Order::clone() const {
    return new Order(*this);
}