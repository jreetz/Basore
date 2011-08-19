/// \file src/c/stdlib/initialize.s
///
/// \brief Provides the runtime initialization procedure.
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
/// The \ref signal function chooses one of three ways in which receipt of the signal number
/// \c sig is to be subsequently handled. If the value of \c func is \ref SIG_DFL, default handling
/// for that signal will occur. If the value of func is \ref SIG_IGN, the signal will be ignored.
/// Otherwise, \c func shall point to a function to be called when that signal occurs. An
/// invocation of such a function because of a signal, or (recursively) of any further functions
/// called by that invocation (other than functions in the standard library) is called a
/// signal handler.
///
/// \par
/// When a signal occurs and \c func points to a function, it is implementation-defined
/// whether the equivalent of \ref signal(\ref sig, \ref SIG_DFL); is executed or the
/// implementation prevents some implementation-defined set of signals (at least including
/// sig) from occurring until the current signal handling has completed; in the case of
/// \ref SIGILL, the implementation may alternatively define that no action is taken. Then the
/// equivalent of (*func)(sig); is executed. If and when the function returns, if the
/// value of sig is \ref SIGFPE, \ref SIGILL, \ref SIGSEGV, or any other implementation-defined
/// value corresponding to a computational exception, the behavior is undefined; otherwise
/// the program will resume execution at the point it was interrupted.
///
/// \par
/// If the signal occurs as the result of calling the \ref abort or \ref raise function, the signal
/// handler shall not call the raise function.
///
/// \par
/// If the signal occurs other than as the result of calling the \ref abort or \ref raise function,
/// the behavior is undefined if the signal handler refers to any object with static or thread
/// storage duration that is not a lock-free atomic object other than by assigning a value to an
/// object declared as volatile sig_atomic_t, or the signal handler calls any function
/// in the standard library other than the \ref abort function, the \ref _Exit function, the
/// \ref quick_exit function, or the \ref signal function with the first argument equal to the
/// signal number corresponding to the signal that caused the invocation of the handler.
/// Furthermore, if such a call to the \ref signal function results in a \ref SIG_ERR return, the
/// value of \ref errno is indeterminate.
///
/// \par
/// At program startup, the equivalent of \ref signal(\ref sig, \ref SIG_IGN) may be executed for
/// some signals selected in an implementation-defined manner. The equivalent of
/// \ref signal(\ref sig, \ref SIG_DFL) is executed for all other signals defined by
/// the implementation.
///
/// \par
/// Use of this function in a multi-threaded program results in undefined behavior. The
/// implementation shall behave as if no library function calls the \ref signal function.
__public void (*signal(int sig, void (*func)(int)))(int)
{
    // Set the designated signal
    __signal_handlers[sig] = func;

    // Return the signal handler
    return func;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
