#include"../../include/Action.h"
#include "../../include/Global.h"


BackupWareHouse::BackupWareHouse():Action(){}

void BackupWareHouse::act(WareHouse &wareHouse){
    backup = new WareHouse(wareHouse); //copy constructor
    wareHouse.addAction(this);
}

BackupWareHouse *BackupWareHouse::clone() const{
    return new BackupWareHouse();
}
string BackupWareHouse::toString() const{
    return "BackupWareHouse";
}