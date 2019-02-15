Lab02: Node.o LinkedList.o Test.o Main.o 
	g++ -std=c++11 -Wall -g Node.o LinkedList.o Test.o Main.o -o Lab02
Main.o: Node.h LinkedList.h Test.h Main.cpp
	g++ -std=c++11 -Wall -g -c Main.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -Wall -g -c Node.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -Wall -g -c LinkedList.cpp

Test.o: Test.h Test.cpp
	g++ -std=c++11 -Wall -g -c Test.cpp

clean: 
	rm *.o Lab02
