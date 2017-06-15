#pragma once

namespace Ardutils
{
	using SizeT = decltype(sizeof(0));
	using NullPtrT = decltype(nullptr);
	using PtrDiffT = decltype(static_cast< char* >(0) - static_cast< char* >(0));
}
