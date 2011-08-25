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
#include <platform.h>

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
        // Get header
        struct _BASORE_memory_block* header = (((struct _BASORE_memory_block*)ptr) - 1);

        // No; make available
        header->available = true;

        // Merge next block if it is free
        if (header->next != NULL && header->next->available)
        {
            header->size += sizeof (struct _BASORE_memory_block) + header->next->size;
            header->next = header->next->next;

            if (header->next)
            {
                header->next->previous = header;
            }
        }

        // Merge previous block if it is free
        if (header->previous != NULL && header->previous->available)
        {
            header->previous->size += sizeof (struct _BASORE_memory_block) + header->size;
            header->previous->next = header->next;

            if (header->previous->next)
            {
                header->previous->next->previous = header->previous;
            }

            header = header->previous;
        }

        // Free chunk to system
        if (header->previous == NULL && header->next == NULL)
        {
            // We just free´d the last chunk
            // Get chunk pointer
            struct _BASORE_memory_chunk* chunk = header->parent;

            // Is this the emergency chunk ?
            if (chunk != &_BASORE_emergency_memory_chunk)
            {
                // No; we only free the -last- chunk
                if (chunk->next == NULL)
                {
                    // Is this the first chunk ?
                    if (chunk->previous == NULL)
                    {
                        // Yes; free the first_block pointer
                        __platform_free(chunk->size, chunk->first_block);

                        // Null it
                        chunk->size = 0;
                        chunk->first_block = NULL;
                    }
                    else
                    {
                        // No; free the whole chunk
                        chunk->previous->next = NULL;
                        __platform_free(chunk->size + sizeof(struct _BASORE_memory_chunk), chunk);
                    }
                }
            }
        }
    }
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
