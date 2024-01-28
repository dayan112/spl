#include"../../include/Action.h"
#include "../../include/Global.h"

RestoreWareHouse::RestoreWareHouse():Action(){}

void RestoreWareHouse::act(WareHouse &wareHouse){
    if(backup){ 
        wareHouse = std::move(*backup->clone());
           
    }
    else{
        error("No backup available");
    }
    wareHouse.addAction(this);

}

RestoreWareHouse* RestoreWareHouse::clone() const{
    return new RestoreWareHouse();
}

string RestoreWareHouse::toString() const{
    return "RestoreWareHouse";
}