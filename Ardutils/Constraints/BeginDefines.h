
namespace Ardutils
{
#define DefineHasBinaryEitherOperator(name, op) \
	namespace Details \
	{ \
		template< typename T, typename U = T, typename = decltype(0) > \
		struct Has##name##Operator : FalseType {}; \
		template< typename T, typename U > \
		struct Has##name##Operator<T, U, decltype((DeclVal<T>()##op##DeclVal<U>()), 0)> : TrueType {}; \
	} \
	template< typename T, typename U = T > \
	struct Has##name##Operator : Details::Has##name##Operator< T, U > {};

#define DefineHasBinaryMemberOperator(name, op) \
	namespace Details \
	{ \
		template< typename T, typename U = T, typename = decltype(0) > \
		struct HasMember##name##Operator : FalseType {}; \
		template< typename T, typename U > \
		struct HasMember##name##Operator<T, U, decltype((DeclVal<T>().operator##op##(DeclVal<U>())), 0)> : TrueType {}; \
	} \
	template< typename T, typename U = T > \
	struct HasMember##name##Operator : Details::HasMember##name##Operator< T, U > {};

#define DefineHasBinaryFreeOperator(name, op) \
	namespace Details \
	{ \
		template< typename T, typename U = T, typename = decltype(0) > \
		struct HasFree##name##Operator : FalseType {}; \
		template< typename T, typename U > \
		struct HasFree##name##Operator<T, U, decltype((operator##op##(DeclVal<T>(), DeclVal<U>())), 0)> : TrueType {}; \
	} \
	template< typename T, typename U = T > \
	struct HasFree##name##Operator : Details::HasFree##name##Operator< T, U > {};

#define DefineHasBinaryOperatorAll(name, op) \
	DefineHasBinaryEitherOperator(name, op) \
	DefineHasBinaryMemberOperator(name, op) \
	DefineHasBinaryFreeOperator(name, op)

#define DefineHasUnaryEitherOperator(name, op) \
	namespace Details \
	{ \
		template< typename T, typename = decltype(0) > \
		struct Has##name##Operator : FalseType {}; \
		template< typename T > \
		struct Has##name##Operator<T, decltype((op##DeclVal<T>()), 0)> : TrueType {}; \
	} \
	template< typename T > \
	struct Has##name##Operator : Details::Has##name##Operator< T > {};

#define DefineHasUnaryMemberOperator(name, op) \
	namespace Details \
	{ \
		template< typename T, typename = decltype(0) > \
		struct HasMember##name##Operator : FalseType {}; \
		template< typename T > \
		struct HasMember##name##Operator<T, decltype((DeclVal<T>().operator##op##()), 0)> : TrueType {}; \
	} \
	template< typename T > \
	struct HasMember##name##Operator : Details::HasMember##name##Operator< T > {};

#define DefineHasUnaryFreeOperator(name, op) \
	namespace Details \
	{ \
		template< typename T, typename = decltype(0) > \
		struct HasFree##name##Operator : FalseType {}; \
		template< typename T > \
		struct HasFree##name##Operator<T, decltype((operator##op##(DeclVal<T>())), 0)> : TrueType {}; \
	} \
	template< typename T > \
	struct HasFree##name##Operator : Details::HasFree##name##Operator< T > {};

#define DefineHasUnaryOperatorAll(name, op) \
	DefineHasUnaryEitherOperator(name, op) \
	DefineHasUnaryMemberOperator(name, op) \
	DefineHasUnaryFreeOperator(name, op)

#define DefineHasBracketEitherOperator(name, lbrace, rbrace) \
	namespace Details \
	{ \
		template< typename T, typename U = T, typename = decltype(0) > \
		struct Has##name##Operator : FalseType {}; \
		template< typename T, typename U > \
		struct Has##name##Operator<T, U, decltype((DeclVal<T>()##lbrace##DeclVal<U>()##rbrace), 0)> : TrueType {}; \
	} \
	template< typename T, typename U = T > \
	struct Has##name##Operator : Details::Has##name##Operator< T, U > {};

#define DefineHasBracketMemberOperator(name, lbrace, rbrace) \
	namespace Details \
	{ \
		template< typename T, typename U = T, typename = decltype(0) > \
		struct HasMember##name##Operator : FalseType {}; \
		template< typename T, typename U > \
		struct HasMember##name##Operator<T, U, decltype((DeclVal<T>().operator##lbrace##rbrace##(DeclVal<U>())), 0)> : TrueType {}; \
	} \
	template< typename T, typename U = T > \
	struct HasMember##name##Operator : Details::HasMember##name##Operator< T, U > {};

#define DefineHasBracketFreeOperator(name, lbrace, rbrace) \
	namespace Details \
	{ \
		template< typename T, typename U = T, typename = decltype(0) > \
		struct HasFree##name##Operator : FalseType {}; \
		template< typename T, typename U > \
		struct HasFree##name##Operator<T, U, decltype((operator##lbrace##rbrace##(DeclVal<T>(), DeclVal<U>())), 0)> : TrueType {}; \
	} \
	template< typename T, typename U = T > \
	struct HasFree##name##Operator : Details::HasFree##name##Operator< T, U > {};

#define DefineHasBracketOperatorAll(name, lbrace, rbrace) \
	DefineHasBracketEitherOperator(name, lbrace, rbrace) \
	DefineHasBracketMemberOperator(name, lbrace, rbrace) \
	DefineHasBracketFreeOperator(name, lbrace, rbrace)
}