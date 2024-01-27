#pragma once
#include <string>
#include <vector>
using namespace std;

#include "Order.h"
#include "Customer.h"
#include "Action.h"

class BaseAction;
class Volunteer;
class Action;

// Warehouse responsible for Volunteers, Customers and Actions.


class WareHouse {

    public:
        WareHouse(const string &configFilePath);//TODO
        void start();//TODO
        const vector<BaseAction*> &getActions() const;
        void addOrder(Order* order);
        void addCustomer(Customer* customer);
        void addVolunteer(Volunteer* volunteer);
        void addAction(BaseAction* action);
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const;
        Order &getOrder(int orderId) const;

        //added function:
        void eraseVolunteer(Volunteer*);
        void moveOrderForward(Order* o, int fromList, int toList);
        void addAction(Action* action);

        //0 to get pendings, 1 to get inProcess, 2 to get completed
        const vector<Order*>& getOrders(int o_status) const; 
        const vector<Volunteer*>& getVolunteers() const;
        const vector<Customer*>& getCustomers() const;


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
};