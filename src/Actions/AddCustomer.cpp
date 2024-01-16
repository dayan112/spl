#include"../../include/BaseAction.h"

using namespace Action;

AddCustomer::AddCustomer(string customerName, string customerType, int distance, int maxOrders):
    BaseAction(),customerName(customerName), customerType(((customerType == "soldier") || (customerType == "Soldier")) ? CustomerType::Soldier : CustomerType::Civilian),
    distance(distance), maxOrders(maxOrders){}

void AddCustomer::act(WareHouse &wareHouse) {
    //TODO
}

AddCustomer *AddCustomer::clone() const {
    std::string type = customerType == CustomerType::Soldier ? "soldier" : "civilian";
    AddCustomer* cloned = new AddCustomer(customerName,type,distance,maxOrders);
    return cloned;
}

string AddCustomer::toString() const{
    std::string type("");
    if (customerType == CustomerType::Soldier){
        type = "Soldier";
    }
    else{
        type = "Civilian";
    }
    std::string str = "AddCustomer\n customerName:" + customerName+
             "\ntype: " + type + "\ndistance: %d \nmaxOrders: %d", distance, maxOrders;
    return str;
}
