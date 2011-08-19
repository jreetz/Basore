/// \file include/c/stdint.h
///
/// \brief Implements the standard c/c++ header <stdint.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef STDINT_9AE6437A_4B76_4108_8F32_FD6E9B27F71C
#define STDINT_9AE6437A_4B76_4108_8F32_FD6E9B27F71C

#include <configuration.h>

#if _BASORE_HAS_INT8
/// \brief Minimum value of a signed integer with exactly 8-bits in width.
#define INT8_MIN (-INT8_MAX - 1)

/// \brief Maximum value of a signed integer with exactly 8-bits in width.
#define INT8_MAX _BASORE_INT8_MAX
#endif // _BASORE_HAS_INT8

#if _BASORE_HAS_INT16
/// \brief Minimum value of a signed integer with exactly 16-bits in width.
#define INT16_MIN (-INT16_MAX - 1)

/// \brief Maximum value of a signed integer with exactly 16-bits in width.
#define INT16_MAX _BASORE_INT16_MAX
#endif // _BASORE_HAS_INT16

#if _BASORE_HAS_INT32
/// \brief Minimum value of a signed integer with exactly 32-bits in width.
#define INT32_MIN (-INT32_MAX - 1)

/// \brief Maximum value of a signed integer with exactly 32-bits in width.
#define INT32_MAX _BASORE_INT32_MAX
#endif // _BASORE_HAS_INT32

#if _BASORE_HAS_INT64
/// \brief Minimum value of a signed integer with exactly 64-bits in width.
#define INT64_MIN (-INT64_MAX - 1)

/// \brief Maximum value of a signed integer with exactly 64-bits in width.
#define INT64_MAX _BASORE_INT64_MAX
#endif // _BASORE_HAS_INT64

/// \brief Maximum value of an unsigned integer with exactly 8-bits in width.
#if _BASORE_HAS_UINT8
#define UINT8_MAX _BASORE_UINT8_MAX
#endif // _BASORE_HAS_UINT8

/// \brief Maximum value of an unsigned integer with exactly 16-bits in width.
#if _BASORE_HAS_UINT16
#define UINT16_MAX _BASORE_UINT16_MAX
#endif // _BASORE_HAS_UINT16

/// \brief Maximum value of an unsigned integer with exactly 32-bits in width.
#if _BASORE_HAS_UINT32
#define UINT32_MAX _BASORE_UINT32_MAX
#endif // _BASORE_HAS_UINT32

/// \brief Maximum value of an unsigned integer with exactly 64-bits in width.
#if _BASORE_HAS_UINT64
#define UINT64_MAX _BASORE_UINT64_MAX
#endif // _BASORE_HAS_UINT64

/// \brief Minimum value of a signed integer with at least 8-bits in width.
#define INT_LEAST8_MIN (-INT_LEAST8_MAX - 1)

/// \brief Maximum value of a signed integer with at least 8-bits in width.
#define INT_LEAST8_MAX _BASORE_INT_LEAST8_MAX

/// \brief Minimum value of a signed integer with at least 16-bits in width.
#define INT_LEAST16_MIN (-INT_LEAST16_MAX - 1)

/// \brief Maximum value of a signed integer with at least 16-bits in width.
#define INT_LEAST16_MAX _BASORE_INT_LEAST16_MAX

/// \brief Minimum value of a signed integer with at least 32-bits in width.
#define INT_LEAST32_MIN (-INT_LEAST32_MAX - 1)

/// \brief Maximum value of a signed integer with at least 32-bits in width.
#define INT_LEAST32_MAX _BASORE_INT_LEAST32_MAX

/// \brief Minimum value of a signed integer with at least 64-bits in width.
#define INT_LEAST64_MIN (-INT_LEAST64_MAX - 1)

/// \brief Maximum value of a signed integer with at least 64-bits in width.
#define INT_LEAST64_MAX _BASORE_INT_LEAST64_MAX

/// \brief Minimum value of a signed integer with at least 8-bits in width.
#define INT_LEAST8_MIN (-INT_LEAST8_MAX - 1)

/// \brief Maximum value of an unsigned integer with at least 8-bits in width.
#define UINT_LEAST8_MAX _BASORE_UINT_LEAST8_MAX

/// \brief Maximum value of an unsigned integer with at least 16-bits in width.
#define UINT_LEAST16_MAX _BASORE_UINT_LEAST16_MAX

/// \brief Maximum value of an unsigned integer with at least 32-bits in width.
#define UINT_LEAST32_MAX _BASORE_UINT_LEAST32_MAX

/// \brief Maximum value of an unsigned integer with at least 64-bits in width.
#define UINT_LEAST64_MAX _BASORE_UINT_LEAST64_MAX

/// \brief Minimum value of a signed integer with at least 8-bits in width.
#define INT_FAST8_MIN (-INT_FAST8_MAX - 1)

/// \brief Maximum value of a signed integer with at least 8-bits in width.
#define INT_FAST8_MAX _BASORE_INT_FAST8_MAX

/// \brief Minimum value of a signed integer with at least 16-bits in width.
#define INT_FAST16_MIN (-INT_FAST16_MAX - 1)

/// \brief Maximum value of a signed integer with at least 16-bits in width.
#define INT_FAST16_MAX _BASORE_INT_FAST16_MAX

/// \brief Minimum value of a signed integer with at least 32-bits in width.
#define INT_FAST32_MIN (-INT_FAST32_MAX - 1)

/// \brief Maximum value of a signed integer with at least 32-bits in width.
#define INT_FAST32_MAX _BASORE_INT_FAST32_MAX

/// \brief Minimum value of a signed integer with at least 64-bits in width.
#define INT_FAST64_MIN (-INT_FAST64_MAX - 1)

/// \brief Maximum value of a signed integer with at least 64-bits in width.
#define INT_FAST64_MAX _BASORE_INT_FAST64_MAX

/// \brief Minimum value of a signed integer with at least 8-bits in width.
#define INT_FAST8_MIN (-INT_FAST8_MAX - 1)

/// \brief Maximum value of an unsigned integer with at least 8-bits in width.
#define UINT_FAST8_MAX _BASORE_UINT_FAST8_MAX

/// \brief Maximum value of an unsigned integer with at least 16-bits in width.
#define UINT_FAST16_MAX _BASORE_UINT_FAST16_MAX

/// \brief Maximum value of an unsigned integer with at least 32-bits in width.
#define UINT_FAST32_MAX _BASORE_UINT_FAST32_MAX

/// \brief Maximum value of an unsigned integer with at least 64-bits in width.
#define UINT_FAST64_MAX _BASORE_UINT_FAST64_MAX

/// \brief Maximum value of a signed integer capable of holding an object pointer.
#define INTPTR_MAX _BASORE_INTPTR_MAX

/// \brief Minimum value of a signed integer capable of holding an object pointer.
#define INTPTR_MIN (-INTPTR_MAX - 1)

/// \brief Maximum value of an unsigned integer capable of holding an object pointer.
#define UINTPTR_MAX _BASORE_UINTPTR_MAX

/// \brief Maximum value of a signed integer of the greatest supported width.
#define INTMAX_MAX _BASORE_INTMAX_MAX

/// \brief Minimum value of a signed integer of the greatest supported width.
#define INTMAX_MIN (-INTMAX_MAX - 1)

/// \brief Maximum value of an unsigned integer of the greatest supported width.
#define UINTMAX_MAX _BASORE_UINTMAX_MAX

/// \brief Maximum value of an object of type size_t.
#define SIZE_MAX _BASORE_SIZE_MAX

/// \brief Minimum value of an object of type wchar_t.
#define WCHAR_MIN (-WCHAR_MAX - 1)

/// \brief Maximum value of an object of type wchar_t.
#define WCHAR_MAX _BASORE_WCHAR_MAX

/// \brief Minimum value of an object of type wint_t.
#define WINT_MIN (-WINT_MAX - 1)

/// \brief Maximum value of an object of type wint_t.
#define WINT_MAX _BASORE_WINT_MAX

/// \brief Minimum value of an object of type sig_atomic_t.
#define SIG_ATOMIC_MIN (-SIG_ATOMIC_MAX - 1)

/// \brief Maximum value of an object of type sig_atomic_t.
#define SIG_ATOMIC_MAX _BASORE_SIG_ATOMIC_MAX

/// \brief Expands to an integer constant with the type int_least8_t.
#define INT8_C(value) _BASORE_INT8_C(value)

/// \brief Expands to an integer constant with the type int_least16_t.
#define INT16_C(value) _BASORE_INT16_C(value)

/// \brief Expands to an integer constant with the type int_least32_t.
#define INT32_C(value) _BASORE_INT32_C(value)

/// \brief Expands to an integer constant with the type int_least64_t.
#define INT64_C(value) _BASORE_INT64_C(value)

/// \brief Expands to an integer constant with the type uint_least8_t.
#define UINT8_C(value) _BASORE_UINT8_C(value)

/// \brief Expands to an integer constant with the type uint_least16_t.
#define UINT16_C(value) _BASORE_UINT16_C(value)

/// \brief Expands to an integer constant with the type uint_least32_t.
#define UINT32_C(value) _BASORE_UINT32_C(value)

/// \brief Expands to an integer constant with the type uint_least64_t.
#define UINT64_C(value) _BASORE_UINT64_C(value)

/// \brief Expands to an integer constant with the type intmax_t.
#define INTMAX_C(value) _BASORE_INTMAX_C(value)

/// \brief Expands to an integer constant with the type uintmax_t.
#define UINTMAX_C(value) _BASORE_UINTMAX_C(value)

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \brief Signed integer type of exactly 8-bits in width.
#if _BASORE_HAS_INT8
typedef _BASORE_int8_t int8_t;
#endif // _BASORE_HAS_INT8

/// \brief Signed integer type of exactly 16-bits in width.
#if _BASORE_HAS_INT16
typedef _BASORE_int16_t int16_t;
#endif // _BASORE_HAS_INT16

/// \brief Signed integer type of exactly 32-bits in width.
#if _BASORE_HAS_INT32
typedef _BASORE_int32_t int32_t;
#endif // _BASORE_HAS_INT32

/// \brief Signed integer type of exactly 64-bits in width.
#if _BASORE_HAS_INT64
typedef _BASORE_int64_t int64_t;
#endif // _BASORE_HAS_INT64

/// \brief Unsigned integer type of exactly 8-bits in width.
#if _BASORE_HAS_UINT8
typedef _BASORE_uint8_t uint8_t;
#endif // _BASORE_HAS_UINT8

/// \brief Unsigned integer type of exactly 16-bits in width.
#if _BASORE_HAS_UINT16
typedef _BASORE_uint16_t uint16_t;
#endif // _BASORE_HAS_UINT16

/// \brief Unsigned integer type of exactly 32-bits in width.
#if _BASORE_HAS_UINT32
typedef _BASORE_uint32_t uint32_t;
#endif // _BASORE_HAS_UINT32

/// \brief Unsigned integer type of exactly 64-bits in width.
#if _BASORE_HAS_UINT64
typedef _BASORE_uint64_t uint64_t;
#endif // _BASORE_HAS_UINT64

/// \brief Signed integer type of at least 8-bits in width.
typedef _BASORE_int_least8_t int_least8_t;

/// \brief Signed integer type of at least 16-bits in width.
typedef _BASORE_int_least16_t int_least16_t;

/// \brief Signed integer type of at least 32-bits in width.
typedef _BASORE_int_least32_t int_least32_t;

/// \brief Signed integer type of at least 64-bits in width.
typedef _BASORE_int_least64_t int_least64_t;

/// \brief Unsigned integer type of at least 8-bits in width.
typedef _BASORE_uint_least8_t uint_least8_t;

/// \brief Unsigned integer type of at least 16-bits in width.
typedef _BASORE_uint_least16_t uint_least16_t;

/// \brief Unsigned integer type of at least 32-bits in width.
typedef _BASORE_uint_least32_t uint_least32_t;

/// \brief Unsigned integer type of at least 64-bits in width.
typedef _BASORE_uint_least64_t uint_least64_t;

/// \brief Fastest signed integer type of at least 8-bits in width.
typedef _BASORE_int_fast8_t int_fast8_t;

/// \brief Fastest signed integer type of at least 16-bits in width.
typedef _BASORE_int_fast16_t int_fast16_t;

/// \brief Fastest signed integer type of at least 32-bits in width.
typedef _BASORE_int_fast32_t int_fast32_t;

/// \brief Fastest signed integer type of at least 64-bits in width.
typedef _BASORE_int_fast64_t int_fast64_t;

/// \brief Fastest unsigned integer type of at least 8-bits in width.
typedef _BASORE_uint_fast8_t uint_fast8_t;

/// \brief Fastest unsigned integer type of at least 16-bits in width.
typedef _BASORE_uint_fast16_t uint_fast16_t;

/// \brief Fastest unsigned integer type of at least 32-bits in width.
typedef _BASORE_uint_fast32_t uint_fast32_t;

/// \brief Fastest unsigned integer type of at least 64-bits in width.
typedef _BASORE_uint_fast64_t uint_fast64_t;

/// \brief Signed integer type capable of holding an object pointer.
typedef _BASORE_intptr_t intptr_t;

/// \brief Unsigned integer type capable of holding an object pointer.
typedef _BASORE_uintptr_t uintptr_t;

/// \brief Signed integer of the greatest supported width.
typedef _BASORE_intmax_t intmax_t;

/// \brief unsigned integer of the greatest supported width.
typedef _BASORE_uintmax_t uintmax_t;

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)

#if defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)

#if _BASORE_HAS_INT8
using std::int8_t;
#endif // _BASORE_HAS_INT8

#if _BASORE_HAS_INT16
using std::int16_t;
#endif // _BASORE_HAS_INT16

#if _BASORE_HAS_INT32
using std::int32_t;
#endif // _BASORE_HAS_INT32

#if _BASORE_HAS_INT64
using std::int64_t;
#endif // _BASORE_HAS_INT64

#if _BASORE_HAS_UINT8
using std::uint8_t;
#endif // _BASORE_HAS_UINT8

#if _BASORE_HAS_UINT16
using std::uint16_t;
#endif // _BASORE_HAS_UINT16

#if _BASORE_HAS_UINT32
using std::uint32_t;
#endif // _BASORE_HAS_UINT32

#if _BASORE_HAS_UINT64
using std::uint64_t;
#endif // _BASORE_HAS_UINT64

using std::int_least8_t;
using std::int_least16_t;
using std::int_least32_t;
using std::int_least64_t;
using std::uint_least8_t;
using std::uint_least16_t;
using std::uint_least32_t;
using std::uint_least64_t;

using std::int_fast8_t;
using std::int_fast16_t;
using std::int_fast32_t;
using std::int_fast64_t;
using std::uint_fast8_t;
using std::uint_fast16_t;
using std::uint_fast32_t;
using std::uint_fast64_t;

using std::intptr_t;
using std::uintptr_t;

using std::intmax_t;
using std::uintmax_t;

#endif // defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)

#endif // !defined(STDINT_9AE6437A_4B76_4108_8F32_FD6E9B27F71C)
