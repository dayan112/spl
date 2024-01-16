#include"../../include/BaseAction.h"

using namespace Action;

Close::Close():BaseAction(){}

void Close::act(WareHouse &wareHouse){
    //do sometthing
}

string Close::toString() const{
    return "Close Action";
}