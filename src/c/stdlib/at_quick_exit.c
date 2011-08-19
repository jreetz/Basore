/// \file src/c/stdlib/at_quick_exit.c
///
/// \brief Implements at_quick_exit(), as defined in <stdlib.h>.
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
// TODO: #include <stddef.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref at_quick_exit function registers the function pointed to by \c func, to be called
/// without arguments should \ref quick_exit be called. It is unspecified whether a call to
/// the \ref at_quick_exit function that does not happen before the \ref quick_exit function
/// is called will succeed.
__public int at_quick_exit(void (*func)())
{
    // Is this the first call ?
    if (!__quick_exit_functions->address)
    {
        // Yes; register it #1
        __quick_exit_functions->address = func;
        __quick_exit_functions->next = &__quick_exit_functions[1];

        // Return success
        return 0;
    }

    // Get next slot
    struct __function* slot;
    int count = 0;

    for (slot = __quick_exit_functions; slot->next != 0/*FIXME: NULL*/; slot = slot->next, ++count) { }

    // Do we have buffer room ?
    if (count < QUICK_EXIT_FUNCTION_BUFFERED)
    {
        // Allocate
        slot->next = &__quick_exit_functions[count + 1];
        slot = slot->next;

        // Set
        slot->next = 0/*FIXME: NULL*/;
        slot->address = func;

        // Return success
        return 0;
    }

    // FIXME: Try and allocate more memory

    // Return failure
    return -1;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
