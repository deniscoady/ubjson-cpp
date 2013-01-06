/*
 *	Filename: 	Array.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_ARRAY_H_
#define __INCLUDE_ARRAY_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class Array : public Element, public std::vector<Element*> {
public:

	virtual const Type type() const;

	virtual Array* unpack(std::string* data);

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};



#endif