/*
 *	Filename: 	Boolean.cpp
 * 	Author:		Denis Coady
 * 	Revision:
 */

#include <ubjson/Boolean.hpp>

Boolean::Boolean(bool value) : ValueContainer(value)
{
}

const Boolean::Type Boolean::type() const
{
	return BOOLEAN;
}

const std::string Boolean::pack() const
{
	std::string out;
	out = (value_ == true) ? 'T' : 'F';

	return out;
}

Boolean* Boolean::unpack(std::string::iterator& it)
{
	char type = *it++;
	bool value;

	switch(type)
	{
		case 'T': value = true;
		break;

		case 'F': value = false;
		break;

		default:
			std::stringstream ss;
			ss << "Invalid value of '" << type << "' for type boolean" << std::endl;
			throw ubjson_exception(ss.str().c_str());
	}

	return new Boolean(value);
}

const std::string Boolean::to_string() const
{
	std::string str;
	if(value_ == true)
	{
		str = "true";
	}
	else
	{
		str = "false";
	}
	return str;
}