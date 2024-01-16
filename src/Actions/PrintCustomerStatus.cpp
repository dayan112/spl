#include"../../include/BaseAction.h"
#include<iostream>

using namespace Action;

PrintCustomerStatus::PrintCustomerStatus(int customerId):BaseAction(),customerId(customerId){}

void PrintCustomerStatus::act(WareHouse &wareHouse){
    // Customer& cus = WareHouse.getCustomer();
    // if(cus == nullptr){
    //     error("Customer doesn't exist");
    // }
    // else{
    //     std::cout << cus.toString();
    // }
}

PrintCustomerStatus* PrintCustomerStatus::clone() const{
    return new PrintCustomerStatus(customerId);
}

string PrintCustomerStatus::toString() const{
    return "PrintCustomerStatus of customer id: "+customerId;
}
