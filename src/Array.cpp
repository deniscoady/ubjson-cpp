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

Array* Array::unpack(std::string* data)
{
	Array* a = new Array();

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
