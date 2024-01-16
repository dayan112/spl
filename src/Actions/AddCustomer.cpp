#include"../../include/BaseAction.h"

using namespace Action;

AddCustomer::AddCustomer(string customerName, string customerType, int distance, int maxOrders):
    BaseAction(),customerName(customerName), customerType(customerType == "soldier" ? CustomerType::Soldier : CustomerType::Civilian),
    distance(distance), maxOrders(maxOrders){}

void AddCustomer::act(WareHouse &wareHouse) override{
    //TODO
}

AddCustomer *AddCustomer::clone() const override{
    string type = customerType == CustomerType::Soldier ? "soldier" : "civilian";
    AddCustomer* cloned = new AddCustomer(customerName,type,distance,maxOrders);
    return cloned;
}

string AddCustomer::toString() const override{
    string type = customerType == CustomerType::Soldier ? "soldier" : "civilian";
    string str = "AddCustomer\n customerName: %s\ntype: %s\ndistance: %d\nmaxOrders: %d"
            ,customerName,type,distance,maxOrders;
    return str;
}
