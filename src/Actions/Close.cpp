#include"../../include/Action.h"

Close::Close():Action(){}

void Close::act(WareHouse &wareHouse){
    wareHouse.close();
    wareHouse.addAction(this);
}

Close* Close::clone() const{
    return new Close();
}


string Close::toString() const{
    return "Close Action";
}