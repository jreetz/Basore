/// \file src/c/stdlib/malloc.c
///
/// \brief Implements malloc(), as defined in <stdlib.h>.
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
/// The \ref free function causes the space pointed to by ptr to be deallocated, that is, made
/// available for further allocation. If \c ptr is a null pointer, no action occurs. Otherwise, if
/// the argument does not match a pointer earlier returned by a memory management
/// function, or if the space has been deallocated by a call to \ref free or \ref realloc, the
/// behavior is undefined.
__public void free(void* ptr)
{
    // Null ?
    if (ptr)
    {
        // No; make available
        ((struct _BASORE_memory_block*)ptr)->available = true;

        // FIXME: Merge adjacent free blocks
    }
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
