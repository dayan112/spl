#include"../../include/Action.h"

Close::Close():Action(){
}

void Close::act(WareHouse &wareHouse){
    wareHouse.addAction(this);
    complete();
    wareHouse.close();
}

Close* Close::clone() const{
    return new Close();
}


string Close::toString() const{
    return "close";
}