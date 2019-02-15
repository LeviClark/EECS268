/**
*	@file PreconditionViolationException.h
* 	@author Levi Clark
*	@date 2015.09.03
*
*/


#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H
#include <stdexcept>
#include <iostream>

class PreconditionViolationException: public std::runtime_error
{
	public:
	PreconditionViolationException(const char* msg);
	
};
#endif
