#pragma once

#include "Forward.h"
#include "DeclVal.h"

namespace Ardutils
{
	namespace Details
	{
		template< typename Func, typename... Args >
		constexpr inline auto Invoke(Func&& f, Args&&... args)
			-> decltype(Forward<Func>(f)(Forward<Args>(args)...))
		{
			return Forward<Func>(f)(Forward<Args>(args)...);
		}

		template< typename Base, typename T, typename Derived >
		constexpr inline auto Invoke(T Base::*p, Derived&& ref)
			-> decltype(Forward<Derived>(ref).*p)
		{
			return Forward<Derived>(ref).*p;
		}

		template< typename Base, typename T, typename Derived, typename... Args >
		constexpr inline auto Invoke(T Base::*p, Derived&& ref, Args&&... args)
			-> decltype((Forward<Derived>(ref).*p)(Forward<Args>(args)...))
		{
			return (Forward<Derived>(ref).*p)(Forward<Args>(args)...);
		}

		template< typename T, typename Pointer >
		constexpr inline auto Invoke(T&& p, Pointer&& pointer)
			-> decltype((*Forward<Pointer>(pointer)).*Forward<T>(p))
		{
			return (*Forward<Pointer>(pointer)).*Forward<T>(p);
		}

		template< typename T, typename Pointer, typename... Args >
		constexpr inline auto Invoke(T&& p, Pointer&& pointer, Args&&... args)
			-> decltype(((*Forward<Pointer>(pointer)).*Forward<T>(p))(Forward<Args>(args)...))
		{
			return ((*Forward<Pointer>(pointer)).*Forward<T>(p))(Forward<Args>(args)...);
		}

		template < typename Void, typename T, typename... Args >
		struct InvokeResult { };

		template <typename Func, typename...Args>
		struct InvokeResult<decltype(void(Details::Invoke(DeclVal<Func>(), DeclVal<Args>()...))), Func, Args...>
		{
			using Type = decltype(Details::Invoke(DeclVal<Func>(), DeclVal<Args>()...));
		};
	}

	template< typename T >
	struct ResultOf;

	template< typename Func, typename... Args >
	struct ResultOf<Func(Args...)> : Details::InvokeResult<void, Func, Args...> {};

	template< typename T >
	using ResultOfT = typename ResultOf<T>::Type;
}
