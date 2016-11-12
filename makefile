all: BankingSystem
BankingSystem: main.o Customer.o EmployeeAccount.o Manager.o Maintenance.o User.o
	g++ -Wall -o BankingSystem main.o Customer.o EmployeeAccount.o User.o  Manager.o Maintenance.o
main.o: main.cpp User.h User.cpp Customer.h Customer.cpp EmployeeAccount.h EmployeeAccount.cpp Manager.h Manager.cpp Maintenance.h Maintenance.cpp
	g++ -Wall -c main.cpp
Customer.o: Customer.cpp Customer.h User.cpp User.h
	g++ -Wall -c Customer.cpp
Manager.o: Manager.cpp Manager.h EmployeeAccount.h EmployeeAccount.cpp
	g++ -Wall -c Manager.cpp
Maintenance.o: Maintenance.cpp Maintenance.h EmployeeAccount.h EmployeeAccount.cpp
	g++ -Wall -c Maintenance.cpp
User.o: User.cpp User.h
	g++ -Wall -c User.cpp
EmployeeAccount.o: EmployeeAccount.cpp EmployeeAccount.h
	g++ -Wall -c EmployeeAccount.cpp
clean:
	rm -f sample *.o core *.gch
