#include"../../include/Action.h"
#include "../../include/Order.h"
#include "../../include/WareHouse.h"
#include<iostream>

using namespace std;

PrintOrderStatus::PrintOrderStatus(int id):Action(),orderId(id){}

void PrintOrderStatus::act(WareHouse &wareHouse){
    cout << wareHouse.getOrder(orderId).toString() << endl;
}
PrintOrderStatus *PrintOrderStatus::clone() const{
    return new PrintOrderStatus(orderId);
}

string PrintOrderStatus::toString() const{
    string str = "PrintOrderStatus of order's id: ";
    str += orderId;
    str += " is ";

    if(this->getStatus() == ActionStatus::ERROR){
        str += "ERROR";
    }
    else{
        str += "COMPLETED";
    }
    return str;
}