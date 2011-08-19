/// \file src/c/stdlib/_Exit.c
///
/// \brief Implements _Exit(), as defined in <stdlib.h>.
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
#include <platform.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The \ref _Exit function causes normal program termination to occur and control to be
/// returned to the host environment. No functions registered by the \ref atexit function, the
/// \ref at_quick_exit function, or signal handlers registered by the \ref signal function are
/// called. The \c status returned to the host environment is determined in the same way as for
/// the \ref exit function. Whether open streams with unwritten buffered data are
/// flushed, open streams are closed, or temporary files are removed is implementation-
/// defined.
__public __noreturn void _Exit(int status)
{
    // Attempt to exit using platform-dependent function
    __platform_exit(status);

    // Loop forever if all else fails
    for ( ; ; )
    {
        // FIXME: Make architecture-dependent intrinsic
        __asm__ volatile ("hlt");
    }
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
