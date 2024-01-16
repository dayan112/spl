#include"../../include/BaseAction.h"

using namespace Action;

RestoreWareHouse::RestoreWareHouse():BaseAction(){}

void RestoreWareHouse::act(WareHouse &wareHouse){
    //TODO
}

RestoreWareHouse* RestoreWareHouse::clone() const{
    return new RestoreWareHouse();
}

string RestoreWareHouse::toString() const{
    return "RestoreWareHouse";
}