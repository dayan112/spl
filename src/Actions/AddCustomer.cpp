#include"../../include/Action.h"
#include "../../include/WareHouse.h"
#include "../../include/Customer.h"
using namespace std;

AddCustomer::AddCustomer(string customerName, string customerType, int distance, int maxOrders):
    Action(),customerName(customerName), customerType(((customerType == "soldier") || (customerType == "Soldier")) ? CustomerType::Soldier : CustomerType::Civilian),
    distance(distance), maxOrders(maxOrders){}

void AddCustomer::act(WareHouse &wareHouse) {
    if(customerType == CustomerType::Soldier){
        SoldierCustomer* new_c = new SoldierCustomer(10,customerName, distance, maxOrders);
        wareHouse.addCustomer(new_c);
    }
    else{
        CivilianCustomer* new_c = new CivilianCustomer(10,customerName, distance, maxOrders);
        wareHouse.addCustomer(new_c);
    }

    wareHouse.addAction(this); 
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
