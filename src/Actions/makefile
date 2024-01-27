#hello: main.o print.o
#	g++ main.o print.o -o output

SimulateStep.o: ./SimulateStep.cpp
	g++ -c ./SimulateStep.cpp

Action.o: ./Action.cpp
	g++ -c ./Actions/Action.cpp

Order.o: ./Order.cpp
	g++ -c ./Actions/Order.cpp

AddCustomer.o: ./AddCustomer.cpp
	g++ -c ./AddCustomer.cpp

PrintOrderStatus.o: ./PrintOrderStatus.cpp
	g++ -c ./PrintOrderStatus.cpp

PrintCustomerStatus.o: ./PrintCustomerStatus.cpp
	g++ -c ./PrintCustomerStatus.cpp

PrintVolunteerStatus.o: ./PrintVolunteerStatus.cpp
	g++ -c ./PrintVolunteerStatus.cpp

PrintActionsLog.o: ./PrintActionsLog.cpp
	g++ -c ./PrintActionsLog.cpp

Close.o: ./Close.cpp
	g++ -c ./Close.cpp

BackupWareHouse.o: ./BackupWareHouse.cpp
	g++ -c ./BackupWareHouse.cpp

RestoreWareHouse.o: ./RestoreWareHouse.cpp
	g++ -c ./RestoreWareHouse.cpp


clean:
	rm ./*.o
