#include"../../include/Action.h"


RestoreWareHouse::RestoreWareHouse():Action(){}

void RestoreWareHouse::act(WareHouse &wareHouse){
    wareHouse = backup->clone();
}

RestoreWareHouse* RestoreWareHouse::clone() const{
    return new RestoreWareHouse();
}

string RestoreWareHouse::toString() const{
    return "RestoreWareHouse";
}