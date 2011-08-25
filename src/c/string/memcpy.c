/// \file src/c/string/memcpy.c
///
/// \brief Provides memcpy(), as defined in <string.h>.
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
/// The \ref memcpy function copies \c n characters from the object pointed to by \c s2 into the
/// object pointed to by \c s1. If copying takes place between objects that overlap, the behavior
/// is undefined.
__public void* memcpy(void* __restrict s1, const void* __restrict s2, size_t n)
{
    #include <memcpy.i>
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
