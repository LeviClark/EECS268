Lab07: Main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o Test.o
	g++ -g -std=c++11 -Wall  Main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o Test.o -o Lab07
	
Main.o: Main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -Wall -c Main.cpp
	
SortDriver.o: SortDriver.h SortDriver.cpp
	g++ -g -std=c++11 -Wall -c SortDriver.cpp
	
NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -Wall -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp
	g++ -g -std=c++11 -Wall -c NumberFileDriver.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp
	
clean: 
	rm *.o Lab07
