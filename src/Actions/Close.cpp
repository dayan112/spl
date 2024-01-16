#include"../../include/BaseAction.h"

class Close : public BaseAction {
    Close():BaseAction(){}

    void act(WareHouse &wareHouse) override;

    string toString() const override{
        return "Close Action";
    }
};