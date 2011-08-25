/// \file src/c/string/memmove.i
///
/// \brief Implements memmove(), as defined in <string.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

// __public int memmove(const void* s1, const void* s2, size_t n)
// Test for an overlap that would prevent an ascending (normal) copy
if (s2 < s1 && (unsigned char*)s1 < (const unsigned char*)s2 + n)
{
    // There is a memory overlap; copy descending
    for (size_t i = n; i > 0; --i)
    {
        ((unsigned char*)s1)[i - 1] = ((const unsigned char*)s2)[i - 1];
    }
}
else
{
    // Nope we're good -- copy normally
    for (size_t i = 0; i < n; ++i)
    {
        ((unsigned char*)s1)[i] = ((const unsigned char*)s2)[i];
    }
}

return s1;
