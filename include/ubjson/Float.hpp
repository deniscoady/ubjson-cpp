/*
 *	Filename: 	Float.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_FLOAT_H_
#define __INCLUDE_FLOAT_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class Float : public Element, public ValueContainer<float> {
public:
	Float(float value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};



#endif