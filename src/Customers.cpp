#include "../include/Customer.h"
#include <iostream>
Customer::Customer(int id, const string &name, int locationDistance, int maxOrders): 
    id(id), name(name),locationDistance(locationDistance),maxOrders(maxOrders){
        //testing
        std::cout << "Customer id - " + std::to_string(id) <<std::endl;
    }

const string &Customer::getName() const {return name;}
int Customer::getId() const {return id;}
int Customer::getCustomerDistance() const {return locationDistance;}
int Customer::getMaxOrders() const {return maxOrders;}
int Customer::getNumOrders() const {return ordersId.size();}
bool Customer::canMakeOrder() const {
    //testing
    std::cout << "this customers orderdsID size : "+ std::to_string(ordersId.size()) + " and his max oorders is - " + std::to_string(maxOrders) << std::endl;    
    return ordersId.size() < maxOrders; 
} 
const vector<int> &Customer::getOrdersIds() const {return ordersId;}

//return OrderId if order was added successfully, -1 otherwise
int Customer::addOrder(int orderId) {
        if (canMakeOrder()) {
            ordersId.push_back(orderId);
            return orderId;
        } 
        else {
            return -1; 
        }
    }

SoldierCustomer::SoldierCustomer(int id, const string& name, int locationDistance, int maxOrders):
    Customer(id,name,locationDistance,maxOrders){}

CivilianCustomer::CivilianCustomer(int id,const string& name, int locationDistance, int maxOrders):
    Customer(id,name,locationDistance,maxOrders){}

SoldierCustomer* SoldierCustomer::clone() const {
    return new SoldierCustomer(*this);
}

CivilianCustomer* CivilianCustomer::clone() const {
    return new CivilianCustomer(*this);
}



