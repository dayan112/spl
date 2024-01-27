#pragma once
#include <string>
#include <vector>
using namespace std;

#include "Order.h"
#include "Customer.h"
#include "Action.h"

class Volunteer;
class Action;

// Warehouse responsible for Volunteers, Customers and Actions.


class WareHouse {

    public:
        WareHouse(const WareHouse& other);
        WareHouse(const string &configFilePath);//TODO
        void start();//TODO
        const vector<Action*> &getActions() const;
        void addOrder(Order* order);
        void addCustomer(Customer* customer);
        void addVolunteer(Volunteer* volunteer);
        void addAction(Action* action);
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;
        
        //added functions:

        void eraseVolunteer(Volunteer*);
        void moveOrderForward(Order* o, int fromList, int toList);
        void addAction(Action* action);
        bool getOpeness()const;
        //0 for customerCounter, 1 for volunteerCounter.
        int getCounters(int i)const ;
        //0 to get pendings, 1 to get inProcess, 2 to get completed
        const vector<Order*>& getOrders(int o_status) const; 
        const vector<Volunteer*>& getVolunteers() const;
        const vector<Customer*>& getCustomers() const;
        WareHouse* clone() const;
        ~WareHouse();
        void close();
        void open();

    private:
        bool isOpen;
        vector<Action*> actions;
        vector<Volunteer*> volunteers;
        vector<Order*> pendingOrders;
        vector<Order*> inProcessOrders;
        vector<Order*> completedOrders;
        vector<Customer*> customers;
        int customerCounter; //For assigning unique customer IDs
        int volunteerCounter; //For assigning unique volunteer IDs
        void setup(const string&);
        Action* parseInputToAction(string input);
};