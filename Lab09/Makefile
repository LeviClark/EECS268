Lab09: Main.o MazeCreationException.o  Position.o MazeReader.o MazeWalker.o Test.o
	g++ -g -std=c++11 -Wall Main.o MazeCreationException.o Position.o MazeReader.o MazeWalker.o Test.o -o Lab09
	
Main.o: Main.cpp MazeCreationException.h Position.h MazeCreationException.cpp Position.cpp
	g++ -g -std=c++11 -Wall -c Main.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -Wall -c MazeCreationException.cpp

Position.o: Position.h Position.cpp
	g++ -g -std=c++11 -Wall -c Position.cpp
	
MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -Wall -c MazeReader.cpp
	
MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -Wall -c MazeWalker.cpp

Test.o: Test.h ArrayHelper.h ArrayHelper.hpp Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp
	
clean: 
	rm *.o Lab09
