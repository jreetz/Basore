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
#include <stdbool.h>
#include <platform.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

// Attempt to allocate from the passed linked list of memory chunks
static void* alloc(struct _BASORE_memory_chunk* chunk, struct _BASORE_memory_chunk** last,
    size_t size)
{
    for (struct _BASORE_memory_chunk* i = chunk; i != NULL; i = i->next)
    {
        // Is this memory chunk large enough ?
        if (i->size > size)
        {
            // Yes; iterate through exposed blocks
            for (struct _BASORE_memory_block* j = (struct _BASORE_memory_block*)(i + 1);
                 j != NULL; j = j->next)
            {
                // Is this block available and large enough ?
                if (j->available && j->size > size)
                {
                    // Yes; can we split it ?
                    if (j->size > (size + sizeof(struct _BASORE_memory_block) + 5))
                    {
                        // Yes; split it.
                        struct _BASORE_memory_block* temp = (struct _BASORE_memory_block*)
                            ((unsigned char*)(j + 1) + size);

                        temp->next = j->next;
                        j->next = temp;

                        j->next->size = j->size - size - sizeof(struct _BASORE_memory_block);
                        j->next->available = true;

                        j->size = size;
                    }

                    // Set it not available
                    j->available = false;

                    // Return it
                    return (void*)(j + 1);
                }
            }
        }

        // Set last iterator
        if (last != NULL)
        {
            *last = i;
        }
    }

    // Damn; return null
    return NULL;
}

/// \par Description:
/// The \ref malloc function allocates space for an object whose size is specified by size and
/// whose value is indeterminate.
__public void* malloc(size_t size)
{
    // Iterate through available memory chunks
    struct _BASORE_memory_chunk* last;

    void* result = alloc(&_BASORE_first_memory_chunk, &last, size);

    // Did we get some ?
    if (result != NULL)
    {
        // Yes; return it
        return result;
    }

    // Damn. Need more memory from system.
    size_t real_size;
    last->next = (struct _BASORE_memory_chunk*)__platform_allocate(size + 50000, &real_size);

    // Did we get any ?
    if (last->next != NULL)
    {
        // Yes; set it up
        last->next->size = real_size;

        // Allocate and return
        return alloc(last->next, NULL, size);
    }

    // Emergency situation. Use emergency buffer.
    result = alloc(&_BASORE_emergency_memory_chunk, NULL, size);

    // Did we get some ?
    if (result != NULL)
    {
        // Yes; return it
        return result;
    }

    // Damn. We're all doomed. Must be 2012.
    return NULL;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
