#include"../../include/Action.h"
#include "../../include/Volunteer.h"
#include "../../include/WareHouse.h"
#include<iostream>
using namespace std;

PrintVolunteerStatus::PrintVolunteerStatus(int id):Action(),VolunteerId(id){}

void PrintVolunteerStatus::act(WareHouse &wareHouse){
    Volunteer& v = wareHouse.getVolunteer(VolunteerId);
    if(v.getId() != -1 ){
        cout << v.toString() << endl;
        return;
    }
    error("Volunteer doesn’t exist");
}

PrintVolunteerStatus* PrintVolunteerStatus::clone() const{
    return new PrintVolunteerStatus(VolunteerId);
}

string PrintVolunteerStatus::toString() const{
    string str = "PrintVolunteerStatus of volunteer id: ";
    str += VolunteerId;
    str += " is ";

    if(this->getStatus() == ActionStatus::ERROR){
        str += "ERROR";
    }
    else{
        str += "COMPLETED";
    }
    return str;
}