#include "../../include/Action.h"
#include "../../include/Order.h"
#include "../../include/WareHouse.h"
#include "../../include/Customer.h"
#include <iostream>
using namespace std;

AddOrder::AddOrder(int id):Action(),customerId(id){ }

void AddOrder::act(WareHouse &wareHouse){
    Customer &cus = wareHouse.getCustomer(customerId);
    if(cus.getId() == -1){
         error("Cannot place this order");
    }
    else if(!cus.canMakeOrder()){
         error("Cannot place this order");
    }
    else{      
         Order* new_order = new Order(wareHouse.getCounters(1),customerId, cus.getCustomerDistance()); 
         wareHouse.incrementID(1);
         wareHouse.addOrder(new_order);
         cus.addOrder(new_order->getId());
    }
    complete();
    wareHouse.addAction(this);

}

AddOrder* AddOrder::clone() const{
    AddOrder* cloned = new AddOrder(customerId);
    return cloned;
}

string AddOrder::toString() const{
    string str = "order " + std::to_string(customerId) + " " + statusToString() + "\n";
    return str;
    
}