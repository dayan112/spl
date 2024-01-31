bin/warehouse: bin/main.o bin/FileHandler.o bin/Order.o bin/Warehouse.o bin/Volunteer.o bin/DriverVolunteer.o bin/LimitedDriverVolunteer.o bin/CollectorVolunteer.o bin/LimitedCollectorVolunteer.o bin/Customers.o bin/SimulateStep.o bin/RestoreWareHouse.o bin/PrintVolunteerStatus.o bin/PrintOrderStatus.o bin/PrintCustomerStatus.o bin/PrintActionsLog.o bin/AddOrder.o bin/Close.o bin/Action.o bin/BackupWareHouse.o bin/AddCustomer.o
	g++ bin/main.o bin/FileHandler.o bin/Order.o bin/Warehouse.o bin/Volunteer.o bin/DriverVolunteer.o bin/LimitedDriverVolunteer.o bin/CollectorVolunteer.o bin/LimitedCollectorVolunteer.o bin/Customers.o bin/SimulateStep.o bin/RestoreWareHouse.o bin/PrintVolunteerStatus.o bin/PrintOrderStatus.o bin/PrintCustomerStatus.o bin/PrintActionsLog.o bin/AddOrder.o bin/Close.o bin/Action.o bin/BackupWareHouse.o bin/AddCustomer.o -o bin/warehouse
#	valgrind --track-origins=yes --leak-check=full ./output ./bin/rest/input_file.txt
#	Need to add fileHandler--show-leak-kinds=all --track-origins=yes

#main.cpp to main.o
bin/main.o: src/main.cpp include/Order.h include/Volunteer.h include/Customer.h include/Action.h
	g++ -c src/main.cpp -o bin/main.o


bin/FileHandler.o: src/FileHandler.cpp include/FileHandler.h
	g++ -c src/FileHandler.cpp -o bin/FileHandler.o

#Order.cpp to Order.o
bin/Order.o: src/Order.cpp include/Order.h
	g++ -c src/Order.cpp -o bin/Order.o

bin/Warehouse.o: src/Warehouse.cpp include/WareHouse.h
	g++ -c src/Warehouse.cpp -o bin/Warehouse.o

bin/Volunteer.o: src/Volunteer.cpp include/Volunteer.h
	g++ -c src/Volunteer.cpp -o bin/Volunteer.o

bin/CollectorVolunteer.o: src/CollectorVolunteer.cpp include/Volunteer.h
	g++ -c src/CollectorVolunteer.cpp -o bin/CollectorVolunteer.o

bin/LimitedCollectorVolunteer.o: src/LimitedCollectorVolunteer.cpp include/Volunteer.h 
	g++ -c src/LimitedCollectorVolunteer.cpp -o bin/LimitedCollectorVolunteer.o

bin/DriverVolunteer.o: src/DriverVolunteer.cpp include/Volunteer.h 
	g++ -c src/DriverVolunteer.cpp -o bin/DriverVolunteer.o

bin/LimitedDriverVolunteer.o: src/LimitedDriverVolunteer.cpp include/Volunteer.h 
	g++ -c src/LimitedDriverVolunteer.cpp -o bin/LimitedDriverVolunteer.o

bin/Customers.o: src/Customers.cpp include/Customer.h 
	g++ -c src/Customers.cpp -o bin/Customers.o

bin/BackupWareHouse.o: src/Actions/BackupWareHouse.cpp include/Action.h
	g++ -c src/Actions/BackupWareHouse.cpp -o bin/BackupWareHouse.o

bin/Action.o: src/Actions/Action.cpp include/Action.h
	g++ -c src/Actions/Action.cpp -o bin/Action.o

bin/AddCustomer.o: src/Actions/AddCustomer.cpp include/Action.h
	g++ -c src/Actions/AddCustomer.cpp -o bin/AddCustomer.o

bin/Close.o: src/Actions/Close.cpp include/Action.h
	g++ -c src/Actions/Close.cpp -o bin/Close.o

bin/AddOrder.o: src/Actions/AddOrder.cpp include/Action.h
	g++ -c src/Actions/AddOrder.cpp -o bin/AddOrder.o

bin/PrintActionsLog.o: src/Actions/PrintActionsLog.cpp include/Action.h
	g++ -c src/Actions/PrintActionsLog.cpp -o bin/PrintActionsLog.o

bin/PrintCustomerStatus.o: src/Actions/PrintCustomerStatus.cpp include/Action.h
	g++ -c src/Actions/PrintCustomerStatus.cpp -o bin/PrintCustomerStatus.o

bin/PrintOrderStatus.o: src/Actions/PrintOrderStatus.cpp include/Action.h
	g++ -c src/Actions/PrintOrderStatus.cpp -o bin/PrintOrderStatus.o


bin/PrintVolunteerStatus.o: src/Actions/PrintVolunteerStatus.cpp include/Action.h
	g++ -c src/Actions/PrintVolunteerStatus.cpp -o bin/PrintVolunteerStatus.o

bin/RestoreWareHouse.o: src/Actions/RestoreWareHouse.cpp include/Action.h
	g++ -c src/Actions/RestoreWareHouse.cpp -o bin/RestoreWareHouse.o

bin/SimulateStep.o: src/Actions/SimulateStep.cpp include/Action.h
	g++ -c src/Actions/SimulateStep.cpp -o bin/SimulateStep.o

# Clean up 
clean:
	rm -f bin/*.o bin/warehouse
