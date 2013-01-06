/*
 *	Filename: 	ubjson.cpp
 * 	Author:		Denis Coady
 * 	Revision:
 */
#include <ubjson/Element.hpp>
/* Subtypes */
#include <ubjson/Array.hpp>
#include <ubjson/Boolean.hpp>
#include <ubjson/Byte.hpp>
#include <ubjson/Double.hpp>
#include <ubjson/Float.hpp>
#include <ubjson/Huge.hpp>
#include <ubjson/Int16.hpp>
#include <ubjson/Int32.hpp>
#include <ubjson/Int64.hpp>
#include <ubjson/Object.hpp>
#include <ubjson/String.hpp>

Element* Element::unpack(std::string* data)
{
	std::string::iterator it = data->begin();
	return Element::unpack(it);
}

Element* Element::unpack(std::string::iterator& it)
{
	Element* e = NULL;
	switch(*it)
	{
		case 'o':
		case 'O':
			e = Object::unpack(it);
		break;

		case 'T':
		case 'F':
			e = Boolean::unpack(it);
		break;

		case 's':
		case 'S':
			e = String::unpack(it);

		case 'B':
			e = Byte::unpack(it);
		break;

		case 'i':
			e = Int16::unpack(it);
		break;

		case 'I':
			e =  Int32::unpack(it);
		break;

		case 'L':
			e = Int64::unpack(it);
		break;
	}

	return e;
}