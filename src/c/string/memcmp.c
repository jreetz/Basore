/// \file src/c/string/memcmp.c
///
/// \brief Provides memcmp(), as defined in <string.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#include <string.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref memcmp function compares the first \c n characters of the object pointed to by \c s1 to
/// the first \c n characters of the object pointed to by \c s2.
__public __pure int memcmp(const void* s1, const void* s2, size_t n)
{
    #include <memcmp.i>
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
