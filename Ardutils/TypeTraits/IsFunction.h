#pragma once

#include "IntegralConstant.h"

//
// IsFunction (scary amount of code)
//

namespace Ardutils
{
	template< typename T >
	struct IsFunction : FalseType {};

	// CV-Qualified
	template< typename R, typename... Args >
	struct IsFunction<R(Args...)> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) const> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) volatile> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) const volatile> : TrueType {};

	// LValue Ref-Qualified
	template< typename R, typename... Args >
	struct IsFunction<R(Args...) &> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) const &> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) volatile &> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) const volatile &> : TrueType {};

	// RValue Ref-Qualified
	template< typename R, typename... Args >
	struct IsFunction<R(Args...) && > : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) const &&> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) volatile &&> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args...) const volatile &&> : TrueType {};

	// Variadics
	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...)> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) volatile> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) const> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) const volatile> : TrueType {};

	// LValue Ref-Qualified Variadics
	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) &> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) const &> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) volatile &> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) const volatile &> : TrueType {};

	// RValue Ref-Qualified Variadics
	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) && > : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) const &&> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) volatile &&> : TrueType {};

	template< typename R, typename... Args >
	struct IsFunction<R(Args..., ...) const volatile &&> : TrueType {};

	//// CV-Qualified
	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) const noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) volatile noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) const volatile noexcept> : TrueType {};

	//// LValue Ref-Qualified
	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) & noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) const & noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) volatile & noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) const volatile & noexcept> : TrueType {};

	//// RValue Ref-Qualified
	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) && noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) const && noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) volatile && noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args...) const volatile && noexcept> : TrueType {};

	//// Variadics
	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) volatile noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) const noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) const volatile noexcept> : TrueType {};

	//// LValue Ref-Qualified Variadics
	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) & noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) const & noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) volatile & noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) const volatile & noexcept> : TrueType {};

	//// RValue Ref-Qualified Variadics
	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) && noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) const && noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) volatile && noexcept> : TrueType {};

	//template< typename R, typename... Args >
	//struct IsFunction<R(Args..., ...) const volatile && noexcept> : TrueType {};
}