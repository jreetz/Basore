/// \file src/c/stdlib/exit.c
///
/// \brief Implements exit(), as defined in <stdlib.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#include <stdlib.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref exit function causes normal program termination to occur. No functions registered
/// by the \ref at_quick_exit function are called. If a program calls the \ref exit function
/// more than once, or calls the \ref quick_exit function in addition to the \ref exit function, the
/// behavior is undefined.
///
/// \par
/// First, all functions registered by the \ref atexit function are called, in the reverse order of
/// their registration except that a function is called after any previously registered
/// functions that had already been called at the time it was registered. If, during the call to
/// any such function, a call to the \ref longjmp function is made that would terminate the call
/// to the registered function, the behavior is undefined.
///
/// \par
/// Next, all open streams with unwritten buffered data are flushed, all open streams are
/// closed, and all files created by the tmpfile function are removed.
///
/// \par
/// Finally, control is returned to the host environment. If the value of status is zero or
/// \ref EXIT_SUCCESS, an implementation-defined form of the status successful termination is
/// returned. If the value of status is \ref EXIT_FAILURE, an implementation-defined form
/// of the status unsuccessful termination is returned. Otherwise the status returned is
/// implementation-defined.
__public __noreturn void exit(int status)
{
    // TODO: Destroy thread_local objects (call destructors)
    // TODO: Call __cxa_finalize(&__dso_handle)
    // TODO: Iterate through .fini_array; call all static destructors
    // TODO: Iterate through .dtors; call all static destructors
    // TODO: Close all open file streams
    // TODO: Remove all created temporary files

    // Exit to the environment
    _Exit(status);
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
