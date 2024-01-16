#include"../../include/BaseAction.h"


class BaseAction{
    BaseAction(){
        errorMsg = "";
    }
    ActionStatus getStatus() const{
        return status;
    }
    virtual void act(WareHouse& wareHouse)=0;
    virtual string toString() const=0;
    virtual BaseAction* clone() const=0;

    void complete(){
        status = ActionStatus::COMPLETED;
        errorMsg = "";
    }
    void error(string errorMsg){
        status = ActionStatus::ERROR;
        this->errorMsg = errorMsg;
    }
    string getErrorMsg() const{
        return errorMsg;
    }

    private:
        string errorMsg;
        ActionStatus status;
};