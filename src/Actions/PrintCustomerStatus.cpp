#include"../../include/Action.h"
#include "../../include/WareHouse.h"
#include "../../include/Customer.h"
#include<iostream>


PrintCustomerStatus::PrintCustomerStatus(int customerId):Action(),customerId(customerId){}

void PrintCustomerStatus::act(WareHouse &wareHouse){
    if(wareHouse.getCustomer(customerId).getId() != -1){
        cout << wareHouse.customerStatus(customerId);
        complete();
    }
    else{
        error("Customer doesn’t exist");
    }
    wareHouse.addAction(this);
}

PrintCustomerStatus* PrintCustomerStatus::clone() const{
    return new PrintCustomerStatus(customerId);
}

string PrintCustomerStatus::toString() const {
    string str = "customerStatus " + std::to_string(customerId) + " " + statusToString() + "\n";
    return str;
}