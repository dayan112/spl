#include"../../include/Action.h"
#include "../../include/WareHouse.h"
#include "../../include/Customer.h"
using namespace std;

AddCustomer::AddCustomer(string const &customerName, string const &customerType, int distance, int maxOrders):
    Action(),customerName(customerName), customerType(((customerType == "soldier") || (customerType == "Soldier")) ? CustomerType::Soldier : CustomerType::Civilian),
    distance(distance), maxOrders(maxOrders){}

void AddCustomer::act(WareHouse &wareHouse) {
    if(customerType == CustomerType::Soldier){
        SoldierCustomer* new_c = new SoldierCustomer(wareHouse.getCounters(0),customerName, distance, maxOrders);
        wareHouse.incrementID(0);        
        wareHouse.addCustomer(new_c);
    }
    else{
        CivilianCustomer* new_c = new CivilianCustomer(wareHouse.getCounters(0),customerName, distance, maxOrders);
        wareHouse.incrementID(0);
        wareHouse.addCustomer(new_c);
    }
    complete();
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
    std::string str = "customer " + customerName+" " + type + " " + std::to_string(distance) + " " + std::to_string(maxOrders) + " " + statusToString() + "\n";
    return str;
}
