#include"../../include/BaseAction.h"

using namespace Action;

Close::Close():BaseAction(){}

void Close::act(WareHouse &wareHouse) override;

string Close::toString() const override{
    return "Close Action";
}