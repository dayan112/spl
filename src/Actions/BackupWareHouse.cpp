#include"../../include/BaseAction.h"

using namespace Action;

BackupWareHouse::BackupWareHouse():BaseAction(){}
void act(WareHouse &wareHouse){
    //TODO
}

BackupWareHouse *BackupWareHouse::clone() const{
    return new BackupWareHouse();
}
string BackupWareHouse::toString() const{
    return "BackupWareHouse";
}