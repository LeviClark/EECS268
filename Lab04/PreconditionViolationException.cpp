/**
*	@file PreconditionViolationException.cpp
* 	@author Levi Clark
*	@date 2015.09.03
*
*/


#include "PreconditionViolationException.h"
#include <stdexcept>
#include <iostream>


PreconditionViolationException:: PreconditionViolationException(const char* msg) : std::runtime_error(msg)
{
	//nothing goes in here!
}
