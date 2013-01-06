/*
 *	Filename: 	Double.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_DOUBLE_H_
#define __INCLUDE_DOUBLE_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class Double : public Element, public ValueContainer<double> {
public:
	Double(double value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};



#endif