#if COMPILER_IS_GCC

// Ref Here: https://gcc.gnu.org/onlinedocs/gcc/Type-Traits.html

#define COMPILER_TRAIT_HAS_NOTHROW_ASSIGN(type) __has_nothrow_assign(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_ASSIGN true

#define COMPILER_TRAIT_HAS_NOTHROW_COPY(type) __has_nothrow_copy(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_COPY true

#define COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR(type) __has_nothrow_constructor(type)
#define HAS_COMPILER_TRAIT_HAS_NOTHROW_CONSTRUCTOR true


#define COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN(type) __has_trivial_assign(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_ASSIGN true

#define COMPILER_TRAIT_HAS_TRIVIAL_COPY(type) __has_trivial_copy(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_COPY true

#define COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR(type) __has_trivial_constructor(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_CONSTRUCTOR true

#define COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR(type) __has_trivial_destructor(type)
#define HAS_COMPILER_TRAIT_HAS_TRIVIAL_DESTRUCTOR true


#define COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR(type) __has_virtual_destructor(type)
#define HAS_COMPILER_TRAIT_HAS_VIRTUAL_DESTRUCTOR true


#define COMPILER_TRAIT_IS_ABSTRACT(type) __is_abstract(type)
#define HAS_COMPILER_TRAIT_IS_ABSTRACT true

#define COMPILER_TRAIT_IS_BASE_OF(baseType, derivedType) __is_base_of(baseType, derivedType)
#define HAS_COMPILER_TRAIT_IS_BASE_OF true

#define COMPILER_TRAIT_IS_CLASS(type) __is_class(type)
#define HAS_COMPILER_TRAIT_IS_CLASS true

#define COMPILER_TRAIT_IS_EMPTY(type) __is_empty(type)
#define HAS_COMPILER_TRAIT_IS_EMPTY true

#define COMPILER_TRAIT_IS_ENUM(type) __is_enum(type)
#define HAS_COMPILER_TRAIT_IS_ENUM true

#define COMPILER_TRAIT_IS_LITERAL_TYPE(type) __is_literal_type(type)
#define HAS_COMPILER_TRAIT_IS_LITERAL_TYPE true

#define COMPILER_TRAIT_IS_POD(type) __is_pod(type)
#define HAS_COMPILER_TRAIT_IS_POD true

#define COMPILER_TRAIT_IS_POLYMORPHIC(type) __is_polymorphic(type)
#define HAS_COMPILER_TRAIT_IS_POLYMORPHIC true

#define COMPILER_TRAIT_IS_STANDARD_LAYOUT(type) __is_standard_layout(type)
#define HAS_COMPILER_TRAIT_IS_STANDARD_LAYOUT true

#define COMPILER_TRAIT_IS_TRIVIAL(type) __is_trivial(type)
#define HAS_COMPILER_TRAIT_IS_TRIVIAL true

#define COMPILER_TRAIT_IS_UNION(type) __is_union(type)
#define HAS_COMPILER_TRAIT_IS_UNION true

#define COMPILER_TRAIT_UNDERLYING_TYPE(type) __underlying_type(type)
#define HAS_COMPILER_TRAIT_UNDERLYING_TYPE true

#define COMPILER_TRAIT_ALIGNOF(type) __alignof__(type)
#define HAS_COMPILER_TRAIT_ALIGNOF true

#endif