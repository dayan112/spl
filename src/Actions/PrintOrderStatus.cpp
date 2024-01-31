#include"../../include/Action.h"
#include "../../include/Order.h"
#include "../../include/WareHouse.h"
#include<iostream>

using namespace std;

PrintOrderStatus::PrintOrderStatus(int id):Action(),orderId(id){}

void PrintOrderStatus::act(WareHouse &wareHouse){
    Order& o = wareHouse.getOrder(orderId);
    if(o.getId() != -1){
        cout << o.toString() << endl;
        complete();
    }
    else{
        error("Order doesn’t exist");
    }
    wareHouse.addAction(this);
}
PrintOrderStatus *PrintOrderStatus::clone() const{
    return new PrintOrderStatus(orderId);
}

string PrintOrderStatus::toString() const{
    string str = "orderStatus " + std::to_string(orderId) + " " + statusToString() + "\n";
    return str;
}