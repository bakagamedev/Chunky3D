#pragma once

namespace Ardutils
{
	template< typename T, typename U = T > T Exchange(T & value, U && newValue)
	{
		T oldValue = Move(value);
		value = Forward(newValue);
		return oldValue;
	}
}