/**
*	@file FarmAnimal.h
* 	@author Levi Clark
*	@date 2015.10.15
*
*/


#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <iostream>

using namespace std;
class FarmAnimal
{
	protected:
	string m_name;
	string m_sound;
	
	public:
	FarmAnimal();
	string getName() const;
	void setName(string name);
	string getSound() const;
	void setSound(string sound);



};
#endif
