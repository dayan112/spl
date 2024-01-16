#include"../../include/BaseAction.h"
#include"../../include/Order.h"

class Order : public BaseAction {
    Order(int id):BaseAction(),customerId(id){ }
    void act(WareHouse &wareHouse) override{
        /*
            TODO:
        */
    }
    Order *clone() const override{
        Order* cloned = new Order(customerId);
        return cloned;
    }
    string toString() const override{
        string str = "Order of custumer: " + this->customerId;
        
    }
    
    private:
        const int customerId;
};