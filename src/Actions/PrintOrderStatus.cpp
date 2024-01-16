#include"../../include/BaseAction.h"
#include<iosteram>

using namespace Action;

PrintOrderStatus::PrintOrderStatus(int id):BaseAction(),orderId(id){}

void PrintOrderStatus::act(WareHouse &wareHouse) override{
    Order::Order& ord = wareHouse.getOrder(orderId);
    if(ord == nullptr){
        error("Order doesn't exist");
    }
    else{
        //TODO
    }
}

PrintOrderStatus* PrintOrderStatusclone() const override{
    return new PrintOrderStatus(orderId);
}

string PrintOrderStatus::toString() const override{
    return "PrintOrderStatus of order's id "+ orderId;
}