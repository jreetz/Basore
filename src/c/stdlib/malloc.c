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

// Attempt to allocate from the passed linked list of memory chunks
static void* alloc(struct _BASORE_memory_chunk* chunk, struct _BASORE_memory_chunk** last,
    size_t size)
{
    // Iterate through passed memory chunks
    for (struct _BASORE_memory_chunk* i = chunk; i != NULL; i = i->next)
    {
        // Is this chunk big enough ?
        if (i->size > size)
        {
            // Yes; iterate through the passed memory blocks
            for (struct _BASORE_memory_block* j = i->first_block; j != NULL; j = j->next)
            {
                // Is the block available and large enough ?
                if (j->available && j->size > size)
                {
                    // Yes; can we split it ?
                    if (j->size > size + sizeof(long int) + sizeof(struct _BASORE_memory_block))
                    {
                        // Good; set it up
                        struct _BASORE_memory_block* temp = (struct _BASORE_memory_block*)
                            ((unsigned char*)(j + 1) + size);

                        temp->next = j->next;
                        temp->previous = j;

                        j->next = temp;

                        j->next->size = j->size - size - sizeof(struct _BASORE_memory_block);
                        j->next->available = true;
                        j->next->parent = chunk;

                        j->size = size;
                    }

                    // Make it not available
                    j->available = false;

                    // Return the memory
                    return (void*)(j + 1);
                }
            }
        }

        // Set last pointer, if available
        if (last != NULL)
        {
            *last = i;
        }
    }

    // Damn; out of luck
    return NULL;
}

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref malloc function allocates space for an object whose size is specified by size and
/// whose value is indeterminate.
__public void* malloc(size_t size)
{
    // Sanity check: are we allocating nothing ?
    if (size == 0)
    {
        // Yes; return nothing
        return NULL;
    }

    // Attempt to use an allocated chunk
    struct _BASORE_memory_chunk* last = NULL;
    void* result = alloc(&_BASORE_first_memory_chunk, &last, size);

    // Did we get memory ?
    if (result != NULL)
    {
        // Good; return it
        return result;
    }

    // See how much more memory we need
    // FIXME: Make 0x50000 a configuration option somewhere
    size_t needed = size + 0x50000;
    size_t real = 0;

    // Try and get more memory from system
    if (last->previous == NULL)
    {
        // First block.
        last->first_block = (struct _BASORE_memory_block*)(__platform_allocate(needed, &real));

        // Did we get it ?
        if (last->first_block)
        {
            // Set it up
            last->size = real;
            last->first_block->parent = last;
        }
    }
    else
    {
        // Not first block
        last->next = (struct _BASORE_memory_chunk*)(__platform_allocate(needed, &real));

        // Did we get it ?
        if (last->next)
        {
            // Set it up
            last->next->next = NULL;
            last->next->previous = last;
            last->next->size = real - sizeof(struct _BASORE_memory_chunk);
            last->next->first_block = (struct _BASORE_memory_block*)(last->next + 1);

            last->next->first_block->parent = last->next;

            last = last->next;
        }
    }

    // Did we get some ?
    if (last != NULL)
    {
        // Yes; finish setting it up
        last->first_block->previous = NULL;
        last->first_block->next = NULL;
        last->first_block->size = last->size - sizeof(struct _BASORE_memory_block);
        last->first_block->available = true;

        // Use it
        return alloc(last, NULL, size);
    }

    // Emergency situation; have we been here before ?
    if (_BASORE_emergency_memory_chunk.first_block->size == 0)
    {
        // No; initialize emergency block
        _BASORE_emergency_memory_chunk.first_block->parent = &_BASORE_emergency_memory_chunk;
        _BASORE_emergency_memory_chunk.first_block->available = true;
        _BASORE_emergency_memory_chunk.first_block->size = _BASORE_emergency_memory_chunk.size -
            sizeof (struct _BASORE_memory_block);
    }

    // Try to allocate off the emergency chunk
    return alloc(&_BASORE_emergency_memory_chunk, NULL, size);
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
