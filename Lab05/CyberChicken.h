/**
*	@file CyberChicken.h
* 	@author Levi Clark
*	@date 2015.10.15
*
*/


#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H
#include "Chicken.h"

using namespace std;

class CyberChicken: public Chicken
{
	public:
	CyberChicken();
	int getCyberEggs() const;
	void setCyberEggs(int eggs);


};
#endif
