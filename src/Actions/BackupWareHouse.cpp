#include"../../include/Action.h"



BackupWareHouse::BackupWareHouse():Action(){}

void act(WareHouse &wareHouse){
    backup = wareHouse->clone();
    wareHouse.addAction(this);
}

BackupWareHouse *BackupWareHouse::clone() const{
    return new BackupWareHouse();
}
string BackupWareHouse::toString() const{
    return "BackupWareHouse";
}