/*
 *	Filename: 	Object.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_OBJECT_H_
#define __INCLUDE_OBJECT_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"
#include "String.hpp"

class Object : public Element, public std::map<std::string, Element*> {
public:

	virtual const Type type() const;

	static Object* unpack(std::string::iterator& it);

	virtual const std::string pack() const;

	const std::string to_string() const;
};


#endif