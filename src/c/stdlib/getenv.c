/// \file src/c/stdlib/getenv.c
///
/// \brief Implements getenv(), as defined in <stdlib.h>.
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
/// The \ref getenv function searches an environment list, provided by the host environment,
/// for a string that matches the string pointed to by \c name. The set of environment names
/// and the method for altering the environment list are implementation-defined. The
/// \ref getenv function need not avoid data races with other threads of execution that modify
/// the environment list.
__public char* getenv(__attribute__ ((unused)) const char* name)
{
    // TODO: Search environment list

    // Return failure
    return NULL;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
