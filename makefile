output: main.o Order.o Volunteer.o DriverVolunteer.o LimitedDriverVolunteer.o CollectorVolunteer.o LimitedCollectorVolunteer.o Customers.o SimulateStep.o RestoreWareHouse.o PrintVolunteerStatus.o PrintOrderStatus.o PrintCustomerStatus.o PrintActionsLog.o AddOrder.o Close.o Action.o BackupWareHouse.o
	g++ main.o Order.o Volunteer.o DriverVolunteer.o LimitedDriverVolunteer.o CollectorVolunteer.o LimitedCollectorVolunteer.o Customers.o SimulateStep.o RestoreWareHouse.o PrintVolunteerStatus.o PrintOrderStatus.o PrintCustomerStatus.o PrintActionsLog.o AddOrder.o Close.o Action.o BackupWareHouse.o -o output
#	SimulateStep.o RestoreWareHouse.o PrintVolunteerStatus.o PrintOrderStatus.o
#	PrintCustomerStatus.o PrintActionsLog.o OrderaAct.o Close.o Action.o
#	BackupWareHouse.o 

#main.cpp to main.o
main.o: src/main.cpp include/Order.h include/Volunteer.h include/Customer.h include/Action.h
	g++ -c src/main.cpp -o main.o


FileHandler.o: src/FileHandler.cpp include/FileHaandler.h
	g++ -c src/FileHandler.cpp -o FileHandler.o

#Order.cpp to Order.o
Order.o: src/Order.cpp include/Order.h
	g++ -c src/Order.cpp -o Order.o

Volunteer.o: src/Volunteer.cpp include/Volunteer.h
	g++ -c src/Volunteer.cpp -o Volunteer.o

CollectorVolunteer.o: src/CollectorVolunteer.cpp include/Volunteer.h
	g++ -c src/CollectorVolunteer.cpp -o CollectorVolunteer.o

LimitedCollectorVolunteer.o: src/LimitedCollectorVolunteer.cpp include/Volunteer.h 
	g++ -c src/LimitedCollectorVolunteer.cpp -o LimitedCollectorVolunteer.o

DriverVolunteer.o: src/DriverVolunteer.cpp include/Volunteer.h 
	g++ -c src/DriverVolunteer.cpp -o DriverVolunteer.o

LimitedDriverVolunteer.o: src/LimitedDriverVolunteer.cpp include/Volunteer.h 
	g++ -c src/LimitedDriverVolunteer.cpp -o LimitedDriverVolunteer.o

Customers.o: src/Customers.cpp include/Customer.h 
	g++ -c src/Customers.cpp -o Customers.o

BackupWareHouse.o: src/Actions/BackupWareHouse.cpp include/Action.h
	g++ -c src/Actions/BackupWareHouse.cpp -o BackupWareHouse.o

Action.o: src/Actions/Action.cpp include/Action.h
	g++ -c src/Actions/Action.cpp -o Action.o

Close.o: src/Actions/Close.cpp include/Action.h
	g++ -c src/Actions/Close.cpp -o Close.o

AddOrder.o: src/Actions/AddOrder.cpp include/Action.h
	g++ -c src/Actions/AddOrder.cpp -o AddOrder.o

PrintActionsLog.o: src/Actions/PrintActionsLog.cpp include/Action.h
	g++ -c src/Actions/PrintActionsLog.cpp -o PrintActionsLog.o

PrintCustomerStatus.o: src/Actions/PrintCustomerStatus.cpp include/Action.h
	g++ -c src/Actions/PrintCustomerStatus.cpp -o PrintCustomerStatus.o

PrintOrderStatus.o: src/Actions/PrintOrderStatus.cpp include/Action.h
	g++ -c src/Actions/PrintOrderStatus.cpp -o PrintOrderStatus.o


PrintVolunteerStatus.o: src/Actions/PrintVolunteerStatus.cpp include/Action.h
	g++ -c src/Actions/PrintVolunteerStatus.cpp -o PrintVolunteerStatus.o

RestoreWareHouse.o: src/Actions/RestoreWareHouse.cpp include/Action.h
	g++ -c src/Actions/RestoreWareHouse.cpp -o RestoreWareHouse.o

SimulateStep.o: src/Actions/SimulateStep.cpp include/Action.h
	g++ -c src/Actions/SimulateStep.cpp -o SimulateStep.o

# Clean up 
clean:
	rm -f *.o output
