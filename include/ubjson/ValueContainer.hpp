/*
 *	Filename: 	ValueContainer.h
 * 	Author:		Denis Coady
 * 	Revision:
 */
#ifndef __INCLUDE_VALUECONTAINER_H_
#define __INCLUDE_VALUECONTAINER_H_

template<typename T>
class ValueContainer {
public:
	ValueContainer(T value) : value_(value)
	{
	}

	void operator=(const T& rhs)
	{
		value_ = rhs;
	}

	T value()
	{
		return value_;
	}

protected:
	T value_;
};


#endif