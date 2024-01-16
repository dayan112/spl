#include"../../include/BaseAction.h"
#include"../../include/Order.h"

Action::Order::Order(int id):BaseAction(),customerId(id){ }

void Action::Order::act(WareHouse &wareHouse){
    // Customer &cus = wareHouse.getCustomer();
    // if(cus == nullptr){
    //     error("Cannot place this order", customerId);
    // }
    // else if(cus.getMaxOrders() == cus.getOrders().size()){
    //     error("Cannot place this order", customerId);
    // }
    // else{
    //     //TODO
    // }

}
Action::Order* Action::Order::clone() const{
    Order* cloned = new Order(customerId);
    return cloned;
}
string Action::Order::toString() const{
    string str = "Order of custumer: %d",customerId;
    
}
