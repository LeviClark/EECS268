#include "Chicken.h"
#include <iostream>

using namespace std;

Chicken::Chicken()
{
	m_name = "Chicken";
	m_sound = "Cluck";

}

int Chicken:: getEggs() const
{
	return m_eggs;
}

void Chicken:: setEggs(int eggs)
{
	m_eggs = eggs;
}

