/// \file include/c/limits.h
///
/// \brief Implements the standard c/c++ header <limits.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef LIMITS_56887E23_8B23_451D_BEBC_2A7002107EEB
#define LIMITS_56887E23_8B23_451D_BEBC_2A7002107EEB

#include <configuration.h>

/// \brief Number of bits in a byte.
#define CHAR_BIT _BASORE_CHAR_BIT

/// \brief Maximum number of bytes in a multibyte character, for any supported locale
#define MB_LEN_MAX 1

/// \brief Minimum value for an object of type signed char.
#define SCHAR_MIN (-SCHAR_MAX - 1)

/// \brief Maximum value for an object of type signed char.
#define SCHAR_MAX _BASORE_SCHAR_MAX

/// \brief Maximum value for an object of type unsigned char.
#define UCHAR_MAX ((SCHAR_MAX << 1) | 1)

/// \brief Minimum value for an object of type char.
#if _BASORE_CHAR_UNSIGNED
#define CHAR_MIN 0
#else
#define CHAR_MIN SCHAR_MIN
#endif //_BASORE_CHAR_UNSIGNED

/// \brief Maximum value for an object of type char.
#if _BASORE_CHAR_UNSIGNED
#define CHAR_MAX UCHAR_MAX
#else
#define CHAR_MAX SCHAR_MAX
#endif //_BASORE_CHAR_UNSIGNED

/// \brief Minimum value for an object of type signed short int.
#define SHRT_MIN (-SHRT_MAX - 1)

/// \brief Maximum value for an object of type signed short int.
#define SHRT_MAX _BASORE_SHRT_MAX

/// \brief Maximum value for an object of type unsigned short int.
#define USHRT_MAX ((SHRT_MAX << 1) | 1)

/// \brief Minimum value for an object of type signed int.
#define INT_MIN (-INT_MAX - 1)

/// \brief Maximum value for an object of type signed int.
#define INT_MAX _BASORE_INT_MAX

/// \brief Maximum value for an object of type unsigned int.
#define UINT_MAX ((INT_MAX << 1) | 1)

/// \brief Minimum value for an object of type signed long int.
#define LONG_MIN (-LONG_MAX - 1)

/// \brief Maximum value for an object of type signed long int.
#define LONG_MAX _BASORE_LONG_MAX

/// \brief Maximum value for an object of type unsigned long int.
#define ULONG_MAX ((LONG_MAX << 1) | 1)

/// \brief Minimum value for an object of type signed long long int.
#define LLONG_MIN (-LLONG_MAX - 1)

/// \brief Maximum value for an object of type signed long long int.
#define LLONG_MAX _BASORE_LLONG_MAX

/// \brief Maximum value for an object of type unsigned long long int.
#define ULLONG_MAX ((LLONG_MAX << 1) | 1)

#endif // !defined(LIMITS_56887E23_8B23_451D_BEBC_2A7002107EEB)
