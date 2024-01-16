#include"../../include/BaseAction.h"

using namespace Action;

BackupWareHouse::BackupWareHouse():BaseAction(){}
void act(WareHouse &wareHouse) override;

BackupWareHouse *BackupWareHouse::clone() const override{
    return new BackupWareHouse();
}
string BackupWareHouse::toString() const override{
    return "BackupWareHouse";
}