#pragma once

#include <avr/pgmspace.h>

template< typename T, size_t N >
struct ProgmemArray
{
private:
	const T * data;
	
public:
	ProgmemArray(const T * data) : data(data) {}
	
	template< size_t N2 >
	ProgmemArray(const T data[N2]) : data(data) {}
	
	const T operator [](const uint8_t & index) const
	{
		T result;
		memcpy_P(&result, data + index, sizeof(T));
		return result;
	}
};