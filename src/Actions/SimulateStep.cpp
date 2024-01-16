#include"../../include/BaseAction.h"

using namespace Action;

SimulateStep::SimulateStep(int numOfSteps):BaseAction(), numOfSteps(numOfSteps){}

void SimulateStep::act(WareHouse &wareHouse){
    
}

std::string SimulateStep::toString() const{
    return "Simulate %d Step" + numOfSteps;
}
SimulateStep* SimulateStep::clone() const{
    return new SimulateStep(numOfSteps);
}