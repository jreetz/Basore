/// \file src/c/string/memmove.c
///
/// \brief Provides memmove(), as defined in <string.h>.
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
/// The \ref memmove function copies \c n characters from the object pointed to by \c s2 into the
/// object pointed to by \c s1 with regards to possible overlapping objects.
__public void* memmove(void* s1, const void* s2, size_t n)
{
    #include <memmove.i>
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
