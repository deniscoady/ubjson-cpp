/*
 *	Filename: 	Byte.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_BYTE_H_
#define __INCLUDE_BYTE_H_


#include "Element.hpp"
#include "ValueContainer.hpp"
#include "numeric_string.hpp"

class Byte : public Element, public ValueContainer<byte> {
public:
	Byte(byte value);

	virtual const Type type() const;

	virtual const std::string pack() const;

	virtual const std::string to_string() const;
};


#endif