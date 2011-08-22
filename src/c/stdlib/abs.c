/// \file src/c/stdlib/abs.c
///
/// \brief Implements abs(), as defined in <stdlib.h>.
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
__public __constant int abs(int j)
{
    static const int s_bits = CHAR_BIT * sizeof(int) - 1;

    int temp = j >> s_bits;

    j ^= temp;
    j += temp & 0x01;

    return j;
}

#ifdef __cplusplus
/// \par Description:
/// Compute the absolute value of an integer \c j. If the result cannot be represented,
/// the behavior is undefined.
__public __constant long int abs(long int j)
{
    return labs(j);
}

/// \par Description:
/// Compute the absolute value of an integer \c j. If the result cannot be represented,
/// the behavior is undefined.
__public __constant long long int abs(long long int j)
{
    return llabs(j);
}
#endif // defined(__cplusplus)

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
