/// \file src/c/stdlib/system.c
///
/// \brief Provides system(), as defined in <stdlib.h>.
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
#include <stddef.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// If \c string is a null pointer, the \ref system function determines whether the host
/// environment has a command processor. If \c string is not a null pointer, the system
/// function passes the string pointed to by \c string to that command processor to be
/// executed in a manner which the implementation shall document; this might then cause the
/// program calling \ref system to behave in a non-conforming manner or to terminate.
__public __constant int system(__attribute__ ((unused)) const char* string)
{
    // TODO: Execute command

    // Return failure
    return 0;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
