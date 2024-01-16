#include"../../include/BaseAction.h"

class PrintOrderStatus : public BaseAction {
    PrintOrderStatus(int id):BaseAction(),orderId(id){}

    void act(WareHouse &wareHouse) override;

    PrintOrderStatus *clone() const override{
        return new PrintOrderStatus(orderId);
    }

    string toString() const override{
        return "PrintOrderStatus of order's id "+ orderId;
    }

    private:
        const int orderId;
};