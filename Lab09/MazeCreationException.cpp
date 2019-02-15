/**
*	@file MazeCreationException.cpp
* 	@author Levi Clark
*	@date 2015.11.13
*
*/
#include "MazeCreationException.h"
#include <iostream>
#include <stdexcept>


using namespace std;

MazeCreationException::MazeCreationException(const char* message):std::runtime_error(message)
{
	//nothing in here
}
