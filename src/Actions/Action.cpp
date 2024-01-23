#include"../../include/Action.h"

Action::Action(){
    errorMsg = "";
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
}

string Action::getErrorMsg() const{
    return errorMsg;
}
