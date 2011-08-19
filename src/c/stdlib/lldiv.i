/// \file src/c/stdlib/lldiv.i
///
/// \brief Implements lldiv(), as defined in <stdlib.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

// __public lldiv_t lldiv(long long int numer, long long int denom)
lldiv_t result;
result.quot = numer / denom;
result.rem  = numer % denom;

return result;
