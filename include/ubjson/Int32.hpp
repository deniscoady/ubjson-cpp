/*
 *	Filename: 	Int32.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_INT32_H_
#define __INCLUDE_INT32_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class Int32 : public Element, public ValueContainer<int32> {
public:
	Int32(int32 value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};


#endif