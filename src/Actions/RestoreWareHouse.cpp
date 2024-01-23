#include"../../include/Action.h"


RestoreWareHouse::RestoreWareHouse():Action(){}

void RestoreWareHouse::act(WareHouse &wareHouse){
    //TODO
}

RestoreWareHouse* RestoreWareHouse::clone() const{
    return new RestoreWareHouse();
}

string RestoreWareHouse::toString() const{
    return "RestoreWareHouse";
}