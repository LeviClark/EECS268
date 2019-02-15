/**
*	@file AnimalPen.h
* 	@author Levi Clark
*	@date 2015.10.15
*
*/


#ifndef ANIMALPEN_H
#define ANIMALPEN_H
#include "Stack.h"
#include "FarmAnimal.h"
using namespace std;


class AnimalPen: public Stack<FarmAnimal*>
{
	public:
	//control the animal pen stack. adds, deletes, and peeks at top of stack.
	AnimalPen();
	~AnimalPen();
	void addAnimal(FarmAnimal* animal);
	FarmAnimal* peekAtNextAnimal();
	void releaseAnimal();
	bool isPenEmpty();
	
	private:
	//no private methods


};

#endif
