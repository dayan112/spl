#include"../../include/Action.h"
#include "../../include/WareHouse.h"
#include "../../include/Customer.h"
#include<iostream>


PrintCustomerStatus::PrintCustomerStatus(int customerId):Action(),customerId(customerId){}

void PrintCustomerStatus::act(WareHouse &wareHouse){
    //cout << wareHouse.getCustomer(customerId);
}

PrintCustomerStatus* PrintCustomerStatus::clone() const{
    return new PrintCustomerStatus(customerId);
}

string PrintCustomerStatus::toString() const {
    string str = "PrintCustomerStatus of customer id: ";
    str += customerId;
    str += " is ";

    if(this->getStatus() == ActionStatus::ERROR){
        str += "ERROR";
    }
    else{
        str += "COMPLETED";
    }
    return str;
}