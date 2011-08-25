/// \file src/c/string/memcmp.i
///
/// \brief Implements memcmp(), as defined in <string.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

// __public int memcmp(const void* s1, const void* s2, size_t n)
for (size_t i = 0; i < n; ++i)
{
    if (((const unsigned char*)s1)[i] != ((const unsigned char*)s2)[i])
    {
        return ((const unsigned char*)s1)[i] < ((const unsigned char*)s2)[i] ? -1 : 1;
    }
}

return 0;
