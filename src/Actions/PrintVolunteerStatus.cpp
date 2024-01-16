#include"../../include/BaseAction.h"

using namespace Action;

    PrintVolunteerStatus::PrintVolunteerStatus(int id):BaseAction(),VolunteerId(id){}

    void PrintVolunteerStatus::act(WareHouse &wareHouse){
        //TODO
    }

    PrintVolunteerStatus* PrintVolunteerStatus::clone() const{
        return new PrintVolunteerStatus(VolunteerId);
    }

    string PrintVolunteerStatus::toString() const{
        return "PrintVolunteerStatus of volunteer id: " + VolunteerId;
    }