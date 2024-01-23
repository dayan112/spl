#include "../../include/Action.h"
#include "../../include/Order.h"
#include "../../include/WareHouse.h"
#include "../../include/Customer.h"

using namespace std;

AddOrder::AddOrder(int id):Action(),customerId(id){ }

void AddOrder::act(WareHouse &wareHouse){
    
    Customer &cus = wareHouse.getCustomer(customerId);
    if(cus.getId() == -1){
         error("Cannot place this order");
    }
    else if(cus.getMaxOrders() == wareHouse.getOrders(0).size()){
         error("Cannot place this order");
    }
    else{
         Order* new_order = new Order(10,customerId, cus.getCustomerDistance());  //need to add ID counter.
         wareHouse.addOrder(new_order);
    }

    wareHouse.addAction((Action*)this);

}

AddOrder* AddOrder::clone() const{
    AddOrder* cloned = new AddOrder(customerId);
    return cloned;
}

string AddOrder::toString() const{
    string str = "Order of custumer: %d",customerId;
    
}