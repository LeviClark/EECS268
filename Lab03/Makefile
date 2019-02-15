Lab03: Main.o Test.o
	g++ -g -std=c++11 -Wall Test.o Main.o -o Lab03
Main.o: Main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Main.cpp
Test.o: Test.h Test.cpp
	g++ -std=c++11 -Wall -g -c Test.cpp

clean: 
	rm *.o Lab03
