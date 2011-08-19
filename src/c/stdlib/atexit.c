/// \file src/c/stdlib/atexit.c
///
/// \brief Implements atexit(), as defined in <stdlib.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#include <stdlib.h>
// FIXME: #include <stddef.h>
// FIXME: #include <cxxabi.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref atexit function registers the function pointed to by \c func, to be called without
/// arguments at normal program termination. It is unspecified whether a call to the
/// \ref atexit function that does not happen before the \ref exit function is called will succeed.
__public int atexit(__attribute__ ((unused)) void (*func)())
{
    // FIXME: Delegate to __cxa_atexit(...)
    // return __cxa_atexit(func);

    // Just return failure
    return -1;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
