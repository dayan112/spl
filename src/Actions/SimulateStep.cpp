#include"../../include/BaseAction.h"

using namespace Action;

SimulateStep::SimulateStep(int numOfSteps):BaseAction(), numOfSteps(numOfSteps){}

void SimulateStep::act(WareHouse &wareHouse) override{
    
}

std::string SimulateStep::toString() const override{
    return "Simulate %d Step" + numOfSteps;
}
SimulateStep* SimulateStep::clone() const override{
    return new SimulateStep(numOfSteps);
}