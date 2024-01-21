output: main.o Order.o Volunteer.o DriverVolunteer.o LimitedDriverVolunteer.o CollectorVolunteer.o LimitedCollectorVolunteer.o Customers.o FileHandler.o
	g++ main.o Order.o Volunteer.o DriverVolunteer.o LimitedDriverVolunteer.o CollectorVolunteer.o LimitedCollectorVolunteer.o Customers.o FileHandler.o -o output

# main.cpp to main.o
main.o: src/main.cpp include/Order.h include/Volunteer.h include/Customer.h
	g++ -c src/main.cpp -o main.o

# Order.cpp to Order.o
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

FileHandler.o: src/FileHandler.cpp include/FileHandler.h
	g++ -c src/FileHandler.cpp -o FileHandler.o

# Clean up 
clean:
	rm -f *.o output
