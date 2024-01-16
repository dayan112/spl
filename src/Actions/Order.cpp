#include"../../include/BaseAction.h"
#include"../../include/Order.h"

using namespace Action;

Order::Order(int id):BaseAction(),customerId(id){ }
void act(WareHouse &wareHouse) override{
    Customer &cus = wareHouse.getCustomer();
    if(cus == nullptr){
        error("Cannot place this order", customerId);
    }
    else if(cus.getMaxOrders() == cus.getOrders().size()){
        error("Cannot place this order", customerId);
    }
    else{
        //TODO
    }

}
Order* Order::clone() const override{
    Order* cloned = new Order(customerId);
    return cloned;
}
string Order::toString() const override{
    string str = "Order of custumer: " + this->customerId;
    
}
