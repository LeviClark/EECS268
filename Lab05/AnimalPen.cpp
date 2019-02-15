#include "AnimalPen.h"
#include <iostream>
#include <stdexcept>
#include "Stack.h"
#include "FarmAnimal.h"
#include "Node.h"

using namespace std;
AnimalPen:: AnimalPen()
{
	//empty
}
AnimalPen:: ~AnimalPen()
{
 	while(!isPenEmpty())
 	{
 		pop();
 	}
 
}

void AnimalPen:: addAnimal(FarmAnimal* animal)
{
	push(animal);
	
}

FarmAnimal* AnimalPen:: peekAtNextAnimal()
{
	return peek();
}

void AnimalPen:: releaseAnimal()
{
	pop();
}

bool AnimalPen:: isPenEmpty()
{
	return(isEmpty());
}


















