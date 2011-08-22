/// \file src/c/stdlib/div.c
///
/// \brief Provides div(), as defined in <stdlib.h>.
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

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// Compute the quotient and remainder of the passed values in a single operation.
__public __constant div_t div(int numer, int denom)
{
    #include <div.i>
}

#ifdef __cplusplus
/// \par Description:
/// Compute the quotient and remainder of the passed values in a single operation.
__public __constant ldiv_t div(long int numer, long int denom)
{
    return ldiv(numer, denom);
}

/// \par Description:
/// Compute the quotient and remainder of the passed values in a single operation.
__public __constant lldiv_t div(long long int numer, long long int denom)
{
    return lldiv(numer, denom);
}
#endif // defined(__cplusplus)

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
