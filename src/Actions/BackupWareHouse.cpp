#include"../../include/BaseAction.h"

class BackupWareHouse : public BaseAction {
    public:
        BackupWareHouse():BaseAction(){}
        void act(WareHouse &wareHouse) override;

        BackupWareHouse *clone() const override{
            return new BackupWareHouse();
        }
        string toString() const override{
            return "BackupWareHouse";
        }
    private:
};