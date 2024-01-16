#include"../../include/BaseAction.h"

Action::BaseAction::BaseAction(){
    errorMsg = "";
}
Action::ActionStatus Action::BaseAction::getStatus() const{
    return status;
}

void Action::BaseAction::complete(){
    status = Action::ActionStatus::COMPLETED;
    errorMsg = "";
}
void Action::BaseAction::error(string errorMsg){
    status = Action::ActionStatus::ERROR;
    this->errorMsg = errorMsg;
}
string Action::BaseAction::getErrorMsg() const{
    return errorMsg;
}
