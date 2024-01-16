#include"../../include/BaseAction.h"

class AddCustomer : public BaseAction {
    AddCustomer(string customerName, string customerType, int distance, int maxOrders):
        BaseAction(),customerName(customerName), customerType(customerType == "soldier" ? CustomerType::Soldier : CustomerType::Civilian),
        distance(distance), maxOrders(maxOrders){}
    
    void act(WareHouse &wareHouse) override;
    
    AddCustomer *clone() const override{
        string type = customerType == CustomerType::Soldier ? "soldier" : "civilian";
        AddCustomer* cloned = new AddCustomer(customerName,type,distance,maxOrders);
        return cloned;
    }
    
    string toString() const override{
        string type = customerType == CustomerType::Soldier ? "soldier" : "civilian";
        string str = "AddCustomer\n customerName: %s\ntype: %s\ndistance: %d\nmaxOrders: %d"
                ,customerName,type,distance,maxOrders;
        return str;
    }
    
    private:
        const string customerName;
        const CustomerType customerType;
        const int distance;
        const int maxOrders;
};