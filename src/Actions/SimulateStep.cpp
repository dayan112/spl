#include"../../include/Action.h"
#include "../../include/WareHouse.h"
#include "../../include/Volunteer.h"
#include "../../include/Customer.h"
#include "../../include/Order.h"


SimulateStep::SimulateStep(int numOfSteps):Action(), numOfSteps(numOfSteps){}

void SimulateStep::act(WareHouse &wareHouse){
    //const vector<Volunteer*>& voltuneers = wareHouse.getVolunteers();
    //Accepting pending orders
    // for(Order* o : wareHouse.getOrders(0)){       
    //     for(Volunteer* v : voltuneers){
    //         if(v->canTakeOrder(*o)){
    //             v->acceptOrder(*o); //Here it check if it needs a driver or collector
    //             wareHouse.moveOrderForward(o,0,1);

    //             if(o->getStatus() == OrderStatus::COLLECTING)
    //                 o->setStatus(OrderStatus::DELIVERING);

    //             else if(o->getStatus() == OrderStatus::PENDING)
    //                 o->setStatus(OrderStatus::COLLECTING);                

    //         }
    //     }
    // }

    // //step the simulation
    // for(Volunteer* v: voltuneers){
    //     v->step();

    //     //This describes a volunteer which just finished his order.
    //     if(v->getCompletedOrderId() != NO_ORDER && v->getActiveOrderId() == NO_ORDER){

    //         Order& ord = wareHouse.getOrder(v->getCompletedOrderId());
                            
    //         for(Order* o : wareHouse.getOrders(1)){
    //             //This is an order which finished its collecting part, we need to move it back to pending and wait for a driver
    //             if(o->getId() == ord.getId()){
    //                 if(ord.getStatus() == OrderStatus::COLLECTING){
    //                     wareHouse.moveOrderForward(o,1,0);
    //                 }
    //             }

    //             //This is an order which finished its delieviring part, sof tipul.
    //             if(o->getId() == ord.getId()){
    //                 if(ord.getStatus() == OrderStatus::DELIVERING){
    //                     wareHouse.moveOrderForward(o,1,2);
    //                 }
    //             }
    //         }
            
    //         //This completed order proceeded to the rightful place.
    //         v->clearCompletedOrder();
    //     }

    //     //This volunteer reached max orders, goodbye and thank you
    //     if(!v->hasOrdersLeft()){
    //         wareHouse.eraseVolunteer(v);
    //     }
    // }
}

std::string SimulateStep::toString() const{
    return "Simulate %d Step" + numOfSteps;
}
SimulateStep* SimulateStep::clone() const{
    return new SimulateStep(numOfSteps);
}