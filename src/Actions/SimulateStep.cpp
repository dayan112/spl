#include"../../include/BaseAction.h"

class SimulateStep : public BaseAction {

    public:
        SimulateStep(int numOfSteps):BaseAction(), numOfSteps(numOfSteps){}

        void act(WareHouse &wareHouse) override;

        std::string toString() const override{
            return "Simulate %d Step" + numOfSteps;
        }
        SimulateStep *clone() const override{
            return new SimulateStep(numOfSteps);
        }

    private:
        const int numOfSteps;
};