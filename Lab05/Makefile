Lab05: Main.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o PreconditionViolationException.o Main.o -o Lab05

Main.o: Main.cpp Node.h Node.hpp StackInterface.h Stack.h Stack.hpp AnimalPen.h FarmAnimal.h Cow.h Chicken.h CyberChicken.h PreconditionViolationException.h
	g++ -g -std=c++11 -Wall -c Main.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++11 -Wall -c FarmAnimal.cpp

Cow.o: Cow.h Cow.cpp
	g++ -g -std=c++11 -Wall -c Cow.cpp

Chicken.o: Chicken.h Chicken.cpp
	g++ -g -std=c++11 -Wall -c Chicken.cpp

CyberChicken.o: CyberChicken.h CyberChicken.cpp
	g++ -g -std=c++11 -Wall -c CyberChicken.cpp

AnimalPen.o: AnimalPen.h AnimalPen.cpp
	g++ -g -std=c++11 -Wall -c AnimalPen.cpp
	
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

clean: 
	rm *.o Lab05

