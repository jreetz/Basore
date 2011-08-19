/// \file include/c/stddef.h
///
/// \brief Implements the standard c/c++ header <stddef.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#include <configuration.h>

/// \brief Null pointer constant.
///
/// \note Referenced from the International C11 Standard §7.19-3.
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL (void*)0
#endif

/// \brief Expands to the offset (in bytes) of a member in type.
///
/// \note Referenced from the International C11 Standard §7.19-3.
#define offsetof(type, member_designator) _BASORE_offsetof(type, member_designator)

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \brief The signed integer type of the result of subtracting two pointers.
///
/// \note Referenced from the International C11 Standard §7.19-2.
typedef _BASORE_ptrdiff_t ptrdiff_t;

/// \brief The unsigned integer type of the result of the sizeof operator.
///
/// \note Referenced from the International C11 Standard §7.19-2.
typedef _BASORE_size_t size_t;

/// \brief Alignment is as great as is supported by the implementation in all contexts.
///
/// \note Referenced from the International C11 Standard §7.19-2.
// TODO: typedef _BASORE_max_align_t max_align_t;

#ifndef __cplusplus
/// \brief Can represent distinct codes for all members of the largest extended character set.
///
/// \note Referenced from the International C11 Standard §7.19-2.
typedef _BASORE_wchar_t wchar_t;
#endif //!defined(__cplusplus)

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)
