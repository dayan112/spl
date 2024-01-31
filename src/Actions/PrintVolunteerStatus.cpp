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
        complete();
    }
    else{
        error("Volunteer doesn’t exist");
    }
    wareHouse.addAction(this);
}

PrintVolunteerStatus* PrintVolunteerStatus::clone() const{
    return new PrintVolunteerStatus(VolunteerId);
}

string PrintVolunteerStatus::toString() const{
    string str = "volunteerStatus " + std::to_string(VolunteerId) + " " + statusToString() + "\n";
    return str;
}