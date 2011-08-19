/// \file src/c/stdlib/abort.c
///
/// \brief Implements abort(), as defined in <stdlib.h>.
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
#include <signal.h>

#ifdef __cplusplus
namespace std {
#endif // defined(__cplusplus)

/// \par Description:
/// The abort function causes abnormal program termination to occur, unless the signal
/// SIGABRT is being caught and the signal handler does not return. Whether open streams
/// with unwritten buffered data are flushed, open streams are closed, or temporary files are
/// removed is implementation-defined. An implementation-defined form of the status
/// unsuccessful termination is returned to the host environment by means of the function
/// call \ref raise(\ref SIGABRT).
__public __noreturn void abort()
{
    // Raise the SIGABRT signal
    raise(SIGABRT);

    // Attempt to terminate irrationally
    // FIXME: Make architecture-dependent intrinsic
    __asm__ volatile (".long 0");

    // Attempt to return failure normally
    _Exit(EXIT_FAILURE);
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
