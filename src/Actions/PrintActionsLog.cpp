#include"../../include/BaseAction.h"

using namespace Action;

PrintActionsLog::PrintActionsLog():BaseAction(){}

void PrintActionsLog::act(WareHouse &wareHouse) {
    //TODO
}

PrintActionsLog* PrintActionsLog::clone() const{
    return new PrintActionsLog();
}

string PrintActionsLog::toString() const{
    return "PrintActionsLog";
}