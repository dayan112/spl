#include"../../include/BaseAction.h"

class RestoreWareHouse : public BaseAction {
    RestoreWareHouse():BaseAction(){}

    void act(WareHouse &wareHouse) override;

    RestoreWareHouse *clone() const override{
        return new RestoreWareHouse();
    }

    string toString() const override{
        return "RestoreWareHouse";
    }
};