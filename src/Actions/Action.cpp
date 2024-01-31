#include"../../include/Action.h"
#include<iostream>
using namespace std;
Action::Action(){
    errorMsg = "";
    status = ActionStatus::COMPLETED;
}
ActionStatus Action::getStatus() const{
    return status;
}

void Action::complete(){
    status = ActionStatus::COMPLETED;
    errorMsg = "";
}
void Action::error(string errorMsg){
    status = ActionStatus::ERROR;
    this->errorMsg = errorMsg;
    cout << "Error: " << errorMsg << endl;
}

string Action::getErrorMsg() const{
    return errorMsg;
}

string Action::statusToString() const{
    if(status == ActionStatus::COMPLETED){
        return "completed";
    }
    return "error";
}
