#include"../../include/BaseAction.h"

using namespace Action;

    PrintVolunteerStatus::PrintVolunteerStatus(int id):BaseAction(),VolunteerId(id){}

    void PrintVolunteerStatus::act(WareHouse &wareHouse) override;

    PrintVolunteerStatus* PrintVolunteerStatus::clone() const override{
        return new PrintVolunteerStatus(VolunteerId);
    }

    string PrintVolunteerStatus::toString() const override{
        return "PrintVolunteerStatus of volunteer id: " + VolunteerId;
    }