mp: Main.o Bank.o User.o Account.o
	g++ -std=c++0x main.o Bank.o User.o Account.o -o mp

Main.o: main.cpp Bank.h
	g++ -std=c++0x -Wall -c main.cpp

Bank.o: Bank.cpp Bank.h User.h Account.h
	g++ -std=c++0x -Wall -c Bank.cpp

User.o: User.cpp User.h Account.h
	g++ -std=c++0x -Wall -c User.cpp

Account.o: Account.cpp Account.h
	g++ -std=c++0x -Wall -c Account.cpp