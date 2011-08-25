/// \file src/c/string/memset.i
///
/// \brief Implements memset(), as defined in <string.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

// __public void memset(void* s, int c, size_t n)
for (size_t i = 0; i < n; ++i)
{
    ((unsigned char*)s)[i] = ((unsigned char)c);
}
