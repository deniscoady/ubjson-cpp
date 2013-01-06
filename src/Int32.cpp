/*
 *	Filename: 	Int32.cpp
 * 	Author:		Denis Coady
 * 	Revision:
 */
#include <ubjson/Int32.hpp>

Int32::Int32(int32 value) : ValueContainer(value)
{
}

const Int32::Type Int32::type() const
{
	return INT32;
}

const std::string Int32::pack() const
{
	std::stringstream ss;
	ss << 'I' << number_string<int32>(value_);

	return ss.str();
}

const std::string Int32::to_string() const
{
	std::stringstream ss;
	ss << value_;
	return ss.str();
}