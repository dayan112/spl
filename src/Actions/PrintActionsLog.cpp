#include "../../include/Action.h"
#include "../../include/WareHouse.h"
#include <iostream>


using namespace std;

PrintActionsLog::PrintActionsLog():Action(){}

void PrintActionsLog::act(WareHouse &wareHouse) {
    
    cout << wareHouse.actionsToString();
    complete();
    wareHouse.addAction(this);
}

PrintActionsLog* PrintActionsLog::clone() const{
    return new PrintActionsLog();
}

string PrintActionsLog::toString() const{
    return "log " + statusToString() + "\n";
}