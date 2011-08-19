/// \file src/c/stdlib/rand.c
///
/// \brief Implements rand(), as defined in <stdlib.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#include "internal.h"

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref rand function computes a sequence of pseudo-random integers in the range 0 to
/// \ref RAND_MAX.
__public int rand()
{
    _BASORE_rand_next = _BASORE_rand_next * 1103515245 + 12345;
    return (unsigned int)(_BASORE_rand_next / (RAND_MAX << 2)) % RAND_MAX;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
