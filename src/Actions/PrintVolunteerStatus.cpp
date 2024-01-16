#include"../../include/BaseAction.h"

class PrintVolunteerStatus : public BaseAction {
    PrintVolunteerStatus(int id):BaseAction(),VolunteerId(id){}

    void act(WareHouse &wareHouse) override;

    PrintVolunteerStatus *clone() const override{
        return new PrintVolunteerStatus(VolunteerId);
    }

    string toString() const override{
        return "PrintVolunteerStatus of volunteer id: " + VolunteerId;
    }
    private:
        const int VolunteerId;
};