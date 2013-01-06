/*
 *	Filename: 	ubjson_exception.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_UBJSON_EXCEPTION_H_
#define __INCLUDE_UBJSON_EXCEPTION_H_

#include <stdexcept>

class ubjson_exception : public std::runtime_error {
public:
	
	explicit ubjson_exception(const std::string& what_arg)
	: runtime_error(what_arg)
	{
	}
};




#endif