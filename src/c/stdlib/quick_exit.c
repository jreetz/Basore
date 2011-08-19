/// \file src/c/stdlib/quick_exit.c
///
/// \brief Implements quick_exit(), as defined in <stdlib.h>.
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
#include <stddef.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref quick_exit function causes normal program termination to occur. No functions
/// registered by the \ref atexit function or signal handlers registered by the \ref signal function
/// are called. If a program calls the \ref quick_exit function more than once, or calls the
/// \ref exit function in addition to the \ref quick_exit function, the behavior is undefined. If a
/// signal is raised while the \ref quick_exit function is executing, the behavior is undefined.
///
/// \par
/// The \ref quick_exit function first calls all functions registered by the \ref at_quick_exit
/// function, in the reverse order of their registration except that a function is called after
/// any previously registered functions that had already been called at the time it was
/// registered. If, during the call to any such function, a call to the \ref longjmp function is
/// made that would terminate the call to the registered function, the behavior is undefined.
///
/// \par
/// Then control is returned to the host environment by means of the function call
/// \ref _Exit(status).
__public __noreturn void quick_exit(int status)
{
    // Call functions registered by the at_quick_exit function.
    for (struct _BASORE_function* i = _BASORE_quick_exit_functions; i != NULL; i = i->next)
    {
        if (i->address)
        {
            i->address();
        }
    }

    // Exit to the environment
    _Exit(status);
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
