#include"../../include/Action.h"
#include "../../include/WareHouse.h"
#include "../../include/Volunteer.h"
#include "../../include/Customer.h"
#include "../../include/Order.h"
#include <iostream>

SimulateStep::SimulateStep(int numOfSteps):Action(), numOfSteps(numOfSteps){}

void SimulateStep::act(WareHouse &wareHouse){
    for(int i = 0; i < numOfSteps; i++){
        const vector<Volunteer*>& voltuneers = wareHouse.getVolunteers();


        //Accepting pending orders
        for(Order* o : wareHouse.getOrders(0)){
            //testing
            std::cout<< "Order in simulateStep pending orders: - \n" + o->toString() << std::endl;        
            for(Volunteer* v : voltuneers){
                //testing
                std::cout<< "Volunteer in simulateStep pending orders: - \n" + v->toString() << std::endl;
                if(v->canTakeOrder(*o)){
                    v->acceptOrder(*o); //Here it checks if it needs a driver or collector
                    wareHouse.moveOrderForward(o,0,1);


                    if(o->getStatus() == OrderStatus::COLLECTING){
                        o->setDriverId(v->getId());
                        o->setStatus(OrderStatus::DELIVERING);
                        
                    }

                    else if(o->getStatus() == OrderStatus::PENDING){
                        o->setCollectorId(v->getId());
                        o->setStatus(OrderStatus::COLLECTING);
                    }

                    break;                

                }
            }
        }

        //step the simulation
        for(Volunteer* v: voltuneers){
            v->step();

            //This describes a volunteer which just finished his order.
            if(v->getCompletedOrderId() != NO_ORDER && v->getActiveOrderId() == NO_ORDER){

                Order& ord = wareHouse.getOrder(v->getCompletedOrderId());

                              
                for(Order* o : wareHouse.getOrders(1)){
                                            
                    //This is an order which finished its delieviring part, sof tipul.
                    if(o->getId() == ord.getId()){
                        if(ord.getStatus() == OrderStatus::COLLECTING){
                            wareHouse.moveOrderForward(o,1,0);
                            
                        } 

                        else if(ord.getStatus() == OrderStatus::DELIVERING){
                            wareHouse.moveOrderForward(o,1,2);
                            ord.setStatus(OrderStatus::COMPLETED);
                        }
                    }
                }
                
                //This completed order proceeded to the rightful place.
                v->clearCompletedOrder();
            }

            //This volunteer reached max orders, and isn't working on an active order: goodbye and thank you
            if(!v->hasOrdersLeft() && v->getActiveOrderId() == NO_ORDER){
                //testing 
                cout << v->getName() + " deleted >>>>>>" << endl;
                wareHouse.eraseVolunteer(v);
            }
        }
    }
}

std::string SimulateStep::toString() const{
    return "Simulate %d Step" + numOfSteps;
}
SimulateStep* SimulateStep::clone() const{
    return new SimulateStep(numOfSteps);
}