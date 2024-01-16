#include"../../include/BaseAction.h"

class PrintActionsLog : public BaseAction {
    PrintActionsLog():BaseAction(){}

    void act(WareHouse &wareHouse) override;

    PrintActionsLog *clone() const override{
        return new PrintActionsLog();
    }

    string toString() const override{
        return "PrintActionsLog";
    }
};