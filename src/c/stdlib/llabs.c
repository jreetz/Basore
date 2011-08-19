/// \file src/c/stdlib/llabs.c
///
/// \brief Implements llabs(), as defined in <stdlib.h>.
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
#include <limits.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// Compute the absolute value of an integer \c j. If the result cannot be represented,
/// the behavior is undefined.
__public long long int llabs(long long int j)
{
    static const int s_bits = CHAR_BIT * sizeof(long long int) - 1;

    long long int temp = j >> s_bits;

    j ^= temp;
    j += temp & 0x01;

    return j;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
