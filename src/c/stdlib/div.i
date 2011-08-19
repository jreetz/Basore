/// \file src/c/stdlib/div.i
///
/// \brief Implements div(), as defined in <stdlib.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

// __public div_t div(int numer, int denom)
div_t result;
result.quot = numer / denom;
result.rem  = numer % denom;

return result;
