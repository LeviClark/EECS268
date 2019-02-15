/**
*	@file Chicken.h
* 	@author Levi Clark
*	@date 2015.10.15
*
*/


#ifndef CHICKEN_H
#define CHICKEN_H
#include "FarmAnimal.h"
#include <iostream>
using namespace std;

class Chicken: public FarmAnimal
{
	protected:
	int getEggs() const;
	void setEggs(int eggs);
	int m_eggs;
	
	public:
	Chicken();


};
#endif
