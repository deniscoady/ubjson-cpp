/*
 *	Filename: 	Int16.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_INT16_H_
#define __INCLUDE_INT16_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"
 
class Int16 : public Element, public ValueContainer<int16> {
public:
	Int16(int16 value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};


#endif