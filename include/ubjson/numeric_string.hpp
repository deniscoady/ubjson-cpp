/*
 *	Filename: 	NumericString.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_NUMERIC_STRING_H_
#define __INCLUDE_NUMERIC_STRING_H_

template<typename T>
std::string number_string(T value)
{
	std::stringstream ss;
	union
	{
	  T v;
	  char c[sizeof(T)];
	};
	v = value;

	for(unsigned int i = 0; i < sizeof(T); i++)
		ss << c[i];
	
	return ss.str();
}

template<typename T>
T string_number(std::string* str)
{
	union
	{
	  T v;
	  char c[sizeof(T)];
	};
	std::copy(str->begin(), str->end(), c);

	return v;
}

template<typename T>
T string_number(std::string::iterator begin, std::string::iterator end)
{
	union
	{
	  T v;
	  char c[sizeof(T)];
	};
	std::copy(begin, end, c);

	return v;
}


#endif