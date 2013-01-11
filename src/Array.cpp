/*
 *	Filename: 	Array.cpp
 * 	Author:		Denis Coady
 * 	Revision:
 */

#include <ubjson/Array.hpp>

const Array::Type Array::type() const
{
	return ARRAY;
}

Array* Array::unpack(std::string::iterator& it)
{
	std::cout << "> Object\n";
	int32 elements;
	char type = *it++;

	switch(type)
	{
		case 'A':
			elements = string_number<int32>(it, it+4);
			it += 4;
		break;

		case 'a':
			elements = string_number<byte>(it, it+1);
			it++;
		break;

		default:
			std::stringstream ss;
			ss << "Invalid value of '" << type << "' for type array" << std::endl;
			throw ubjson_exception(ss.str().c_str());
	}

	Array* a = new Array();
	for(int i = 0; i < elements; i++)
	{
		a->push_back( Element::unpack(it) );
	}

	return a;
}

const std::string Array::pack() const
{
	std::stringstream ss;
	int32 length = this->size();

	if(length < 256)
	{
		ss << "a" << char(length);
	}
	else
	{
		ss << "A" << number_string<int32>(length);
	}

	Array::const_iterator it;
	for(it = begin(); it != end(); ++it)
	{
		ss << (*it)->pack();
	}
	return ss.str();
}

const std::string Array::to_string() const
{
	std::stringstream ss;
	ss << "[";

	Array::const_iterator it;
	for(it = begin(); it != end(); it++)
	{
		if(it != begin())
		{
			ss << ",";
		}
		ss << (*it)->to_string();
	}
	ss << "]";

	return ss.str();
}
