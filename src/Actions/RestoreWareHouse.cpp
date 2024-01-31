#include"../../include/Action.h"
#include "../../include/Global.h"
#include "../../include/WareHouse.h"

RestoreWareHouse::RestoreWareHouse():Action(){}

void RestoreWareHouse::act(WareHouse &wareHouse){
    if(backup != nullptr){ 
        wareHouse = *backup;
        complete();
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
    return "restore " + statusToString() + "\n";
    
}