/*
 *	Filename: 	String.cpp
 * 	Author:		Denis Coady
 * 	Revision:
 */

#include <ubjson/String.hpp>

String::String(std::string value) : ValueContainer(value)
{
}

String::String(const char* value)  : ValueContainer(std::string(value))
{
}

const String::Type String::type() const
{
	return STRING;
}

const std::string String::pack() const
{
	std::stringstream ss;
	int32 length = value_.length();
	if(length < 256)
	{
		ss << "s" << char(length);
	}
	else
	{
		ss << "S" << number_string<int32>(length);
	}
	
	ss << value_;

	return ss.str();
}

String* String::unpack(std::string::iterator& it)
{
	std::cout << "> String\n";
	char type = *it++;
	int32 length;

	switch(type)
	{
		case 'S':
			length = string_number<int32>(it, it + 4);
			it += 4; 
		break;

		case 's':
			length = string_number<byte>(it, it + 1);
			it++;
		break;

		default:
			std::stringstream ss;
			ss << "Invalid value of '" << type << "' for type string" << std::endl;
			throw ubjson_exception(ss.str().c_str());
	}

	String* str = new String(std::string(it, it + length ));
	it += length;
	return str;
}


const std::string String::to_string() const
{
	return '"' + value_ + '"';
}