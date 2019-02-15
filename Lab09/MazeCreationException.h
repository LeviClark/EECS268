/**
*	@file MazeCreationException.h
* 	@author Levi Clark
*	@date 2015.11.13
*
*/

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <stdexcept>

class MazeCreationException: public std::runtime_error
{
	public:
	  /**
          * @post Creates an exception with the message
          */
          MazeCreationException(const char* message);
};
#endif
