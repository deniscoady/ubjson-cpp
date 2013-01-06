/*
 *	Filename: 	Huge.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_HUGE_H_
#define __INCLUDE_HUGE_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class Huge : public Element, public ValueContainer<huge> {
public:
	Huge(huge value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};



#endif