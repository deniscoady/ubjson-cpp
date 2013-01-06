/*
 *	Filename: 	Object.cpp
 * 	Author:		Denis Coady
 * 	Revision:
 */
#include <ubjson/Object.hpp>

const Object::Type Object::type() const
{
	return OBJECT;
}

Object* Object::unpack(std::string::iterator& it)
{
	std::cout << "> Object\n";
	int32 elements;
	char type = *it++;

	switch(type)
	{
		case 'O':
			elements = string_number<int32>(it, it+4);
			it += 4;
		break;

		case 'o':
			elements = string_number<byte>(it, it+1);
			it++;
		break;

		default:
			std::stringstream ss;
			ss << "Invalid value of '" << type << "' for type object" << std::endl;
			throw ubjson_exception(ss.str().c_str());
	}

	Object* o = new Object();
	for(int i = 0; i < elements; i++)
	{
		String*  key 	= String::unpack(it);
		Element* value 	= Element::unpack(it);

		(*o)[key->value()] = value;
	}

	return o;
}

const std::string Object::pack() const
{
	std::stringstream ss;
	int32 length = this->size();

	if(length < 256)
	{
		ss << "o" << char(length);
	}
	else
	{
		ss << "O" << number_string<int32>(length);
	}

	Object::const_iterator it;
	for(it = begin(); it != end(); it++)
	{
		ss << String(it->first).pack();
		ss << it->second->pack();
	}

	return ss.str();
}

const std::string Object::to_string() const
{
	std::stringstream ss;

	ss << "{";
	Object::const_iterator it;
	for(it = begin(); it != end(); it++)
	{
		if(it != begin())
		{
			ss << ",";
		}
		ss << String(it->first).to_string() << ":" << it->second->to_string();
	}
	ss << "}";

	return ss.str();
}
