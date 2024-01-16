#include"../../include/BaseAction.h"

using namespace Action;

PrintActionsLog::PrintActionsLog():BaseAction(){}

void PrintActionsLog::act(WareHouse &wareHouse) override;

PrintActionsLog* PrintActionsLog::clone() const override{
    return new PrintActionsLog();
}

string PrintActionsLog::toString() const override{
    return "PrintActionsLog";
}