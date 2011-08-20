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
/// The \ref malloc function allocates space for an object whose size is specified by size and
/// whose value is indeterminate.
__public void* malloc(size_t size)
{
    // TODO: Check local memory block
    // TODO: Request for more memory from os

    // Out of memory; do we have any emergency memory?
    for (struct _BASORE_memory_block* i = &_BASORE_emergency_memory_block; i != NULL; i = i->next)
    {
        // Available and big enough ?
        if (i->available && i->size > (size + sizeof(struct _BASORE_memory_block)))
        {
            // Yes; split block
            struct _BASORE_memory_block* new_block = (struct _BASORE_memory_block*)
                ((unsigned char*)i + sizeof(struct _BASORE_memory_block) + size);

            new_block->next = i->next;
            i->next = new_block;

            // Initialize new block
            i->next->size = i->size - sizeof(struct _BASORE_memory_block) - size;
            i->next->available = true;

            // Set current
            i->size = size;
            i->available = false;

            // Return block
            return (void*)((unsigned char*)i + sizeof(struct _BASORE_memory_block));
        }
    }

    // Out of luck
    return NULL;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
