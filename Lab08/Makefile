Lab08: Main.o Test.o
	g++ -g -std=c++11 -Wall Main.o Test.o -o Lab08
Main.o: Main.cpp Node.h Node.hpp BSTI.h BinarySearchTree.hpp BinarySearchTree.h Test.h
	g++ -g -std=c++11 -Wall -c Main.cpp
Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp

clean: 
	rm *.o Lab08

