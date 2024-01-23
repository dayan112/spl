#include"../../include/Action.h"



BackupWareHouse::BackupWareHouse():Action(){}
void act(WareHouse &wareHouse){
    // /todo
}

BackupWareHouse *BackupWareHouse::clone() const{
    return new BackupWareHouse();
}
string BackupWareHouse::toString() const{
    return "BackupWareHouse";
}