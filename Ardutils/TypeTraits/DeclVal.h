#pragma once

#include "AddRValueReference.h"

namespace Ardutils
{
	template< typename T >
	typename AddRValueReference<T>::Type DeclVal();
}