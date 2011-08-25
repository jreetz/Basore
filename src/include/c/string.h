/// \file include/c/string.h
///
/// \brief Implements the standard c/c++ header <string.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef STRING_24D5A4A1_8F83_487E_9357_8BC04AF664EC
#define STRING_24D5A4A1_8F83_487E_9357_8BC04AF664EC

#include <configuration.h>

/// \brief Null pointer constant.
///
/// \note Referenced from the International C11 Standard §7.19-3.
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL (void*)0
#endif

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \brief The unsigned integer type of the result of the sizeof operator.
///
/// \note Referenced from the International C11 Standard §7.19-2.
typedef _BASORE_size_t size_t;

/// \brief Copies \c n bytes in memory from \c s1 to \c s2.
///
/// \param[in]  s1  Destination address in memory.
/// \param[in]  s2  Source address in memory.
/// \param[in]  n   Number of bytes to copy.
///
/// \returns Returns the value of \c s1.
///
/// \note Referenced from the International C11 Standard §7.24.2.1.
extern __public void* memcpy(void* __restrict s1, const void* __restrict s2, size_t n);

/// \brief Moves \c n bytes in memory from \c s1 to \c s2.
///
/// \param[in]  s1  Destination address in memory.
/// \param[in]  s2  Source address in memory.
/// \param[in]  n   Number of bytes to move.
///
/// \returns Returns the value of \c s1.
///
/// \note Referenced from the International C11 Standard §7.24.2.2.
extern __public void* memmove(void* s1, const void* s2, size_t n);

/// \brief Compares \c n bytes of memory at \c s1 to \c s2.
///
/// \param[in]  s1  Address of the memory to compare.
/// \param[in]  s2  Address of the memory to be compared to.
/// \param[in]  n   Number of bytes to compare.
///
/// \returns Returns an integer greater than, equal to, or less than zero, accordingly as the
///          object pointed to by \c s1 is greater than, equal to, or less than the object pointed
///          to by \c s2.
///
/// \note Referenced from the International C11 Standard §7.24.4.1.
extern __public int memcmp(const void* s1, const void* s2, size_t n);

/// \brief Sets \c n bytes of memory at \c s to \c c.
///
/// \param[in]  s   Address of the memory to set.
/// \param[in]  c   Value to set the memory to.
/// \param[in]  n   Number of bytes to set.
///
/// \note Referenced from the International C11 Standard §7.24.6.1.
extern __public void memset(void* s, int c, size_t n);

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)

#endif // !defined(STRING_24D5A4A1_8F83_487E_9357_8BC04AF664EC)
