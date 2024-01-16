#include"../../include/BaseAction.h"

using namespace Action;

BaseAction::BaseAction(){
    errorMsg = "";
}
ActionStatus BaseAction::getStatus() const{
    return status;
}

void BaseAction::complete(){
    status = ActionStatus::COMPLETED;
    errorMsg = "";
}
void BaseAction::error(string errorMsg){
    status = ActionStatus::ERROR;
    this->errorMsg = errorMsg;
}
string BaseAction::getErrorMsg() const{
    return errorMsg;
}
