#include "../../include/Action.h"
#include "../../include/WareHouse.h"
#include <iostream>


using namespace std;

PrintActionsLog::PrintActionsLog():Action(){}

void PrintActionsLog::act(WareHouse &wareHouse) {
    const vector<Action*>& actions = wareHouse.getActions();
    for (Action* a : actions){
        cout << a->toString() << endl;
    }
    wareHouse.addAction((Action*)this);
}

PrintActionsLog* PrintActionsLog::clone() const{
    return new PrintActionsLog();
}

string PrintActionsLog::toString() const{
    return "PrintActionsLog";
}