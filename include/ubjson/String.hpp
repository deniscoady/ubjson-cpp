/*
 *	Filename: 	String.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_STRING_H_
#define __INCLUDE_STRING_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class String : public Element, public ValueContainer<std::string> {
public:
	String(std::string value);

	String(const char* value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	static String* unpack(std::string::iterator& it);

	virtual const std::string to_string() const;
};



#endif