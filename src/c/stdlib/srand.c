/// \file src/c/stdlib/srand.c
///
/// \brief Implements srand(), as defined in <stdlib.h>.
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
/// The \ref srand function uses the argument as a seed for a new sequence of pseudo-random
/// numbers to be returned by subsequent calls to \ref rand. If \ref srand is then called with the
/// same seed value, the sequence of pseudo-random numbers shall be repeated. If \ref rand is
/// called before any calls to \ref srand have been made, the same sequence shall be generated
/// as when \ref srand is first called with a seed value of 1.
__public void srand(unsigned int seed)
{
    _BASORE_rand_next = seed;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
