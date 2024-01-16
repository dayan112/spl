#include"../../include/BaseAction.h"

using namespace Action;

PrintCustomerStatus(int customerId):BaseAction(),customerId(customerId){}

void PrintCustomerStatus::act(WareHouse &wareHouse) override;

PrintCustomerStatus* PrintCustomerStatus::clone() const override{
    return new PrintCustomerStatus(customerId);
}

string PrintCustomerStatus::toString() const override{
    return "PrintCustomerStatus of customer id: "+customerId;
}
