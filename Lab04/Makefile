Lab04: Main.o PreconditionViolationException.o Test.o
	g++ -g -std=c++11 -Wall PreconditionViolationException.o Test.o Main.o -o Lab04
Main.o: Main.cpp Node.h Node.hpp StackInterface.h Stack.h Stack.hpp PreconditionViolationException.h Test.h
	g++ -g -std=c++11 -Wall -c Main.cpp
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp
Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp

clean: 
	rm *.o Lab04

