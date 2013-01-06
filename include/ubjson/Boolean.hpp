/*
 *	Filename: 	Boolean.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_BOOLEAN_H_
#define __INCLUDE_BOOLEAN_H_


#include "Element.hpp"
#include "ValueContainer.hpp"

class Boolean : public Element, public ValueContainer<bool> {
public:
	Boolean(bool value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	static Boolean* unpack(std::string::iterator& it);

	virtual const std::string to_string() const;
};



#endif