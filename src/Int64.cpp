/*
 *	Filename: 	Int64.cpp
 * 	Author:		Denis Coady
 * 	Revision:
 */

#include <ubjson/Int64.hpp>

Int64::Int64(int64 value) : ValueContainer(value)
{
}

const Int64::Type Int64::type() const
{
	return INT64;
}

const std::string Int64::pack() const
{
	std::stringstream ss;
	ss << 'L' << number_string<int64>(value_);

	return ss.str();
}

const std::string Int64::to_string() const
{
	std::stringstream ss;
	ss << value_;
	return ss.str();
}