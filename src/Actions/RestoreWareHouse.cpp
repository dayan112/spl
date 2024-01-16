#include"../../include/BaseAction.h"

using namespace Action;

RestoreWareHouse::RestoreWareHouse():BaseAction(){}

void RestoreWareHouse::act(WareHouse &wareHouse) override;

RestoreWareHouse* RestoreWareHouse::clone() const override{
    return new RestoreWareHouse();
}

string RestoreWareHouse::toString() const override{
    return "RestoreWareHouse";
}