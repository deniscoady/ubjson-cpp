/*
 *	Filename: 	Int64.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_INT64_H_
#define __INCLUDE_INT64_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class Int64 : public Element, public ValueContainer<int64> {
public: 
	Int64(int64 value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};


#endif