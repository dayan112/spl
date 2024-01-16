#include"../../include/BaseAction.h"
#include<iostream>

using namespace Action;

PrintOrderStatus::PrintOrderStatus(int id):BaseAction(),orderId(id){}

void PrintOrderStatus::act(WareHouse &wareHouse){
    // Order::Order& ord(wareHouse.getOrder(orderId));
    // if(ord == nullptr){
    //     error("Order doesn't exist");
    // }
    // else{
    //     std::cout << ord.toString();//mayne not
    // }
}
PrintOrderStatus *PrintOrderStatus::clone() const{
    return new PrintOrderStatus(orderId);
}

string PrintOrderStatus::toString() const{
    return "PrintOrderStatus of order's id "+ orderId;
}