#include"../../include/BaseAction.h"

class PrintCustomerStatus: public BaseAction {
    PrintCustomerStatus(int customerId):BaseAction(),customerId(customerId){}

    void act(WareHouse &wareHouse) override;

    PrintCustomerStatus *clone() const override{
        return new PrintCustomerStatus(customerId);
    }

    string toString() const override{
        return "PrintCustomerStatus of customer id: "+customerId;
    }
    private:
        const int customerId;
};