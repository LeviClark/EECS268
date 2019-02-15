polyCalc: calc.o main.o
	g++ -std=c++11 -Wall -g calc.o main.o -o polyCalc

calc.o: calc.h calc.cpp
	g++ -std=c++11 -Wall -g -c calc.cpp

main.o: calc.h main.cpp
	g++ -std=c++11 -Wall -g -c main.cpp


clean: 
	rm *.o polyCalc
