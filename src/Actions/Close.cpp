#include"../../include/Action.h"

Close::Close():Action(){}

void Close::act(WareHouse &wareHouse){
    wareHouse.close();
    wareHouse.addAction(this);
}

string Close::toString() const{
    return "Close Action";
}