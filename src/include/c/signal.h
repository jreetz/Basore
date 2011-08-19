/// \file include/c/signal.h
///
/// \brief Implements the standard c/c++ header <signal.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef SIGNAL_BE972ECD_0D3D_4ED5_BEB3_DFB4B5BB886D
#define SIGNAL_BE972ECD_0D3D_4ED5_BEB3_DFB4B5BB886D

#include <configuration.h>

/// \brief Specifies the default action for the signal.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIG_DFL (void (*)())0

/// \brief Specifies an error occurred in the \ref signal() function.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIG_ERR (void (*)())2

/// \brief Specifies a signal to be ignored.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIG_IGN (void (*)())1

/// \brief Signifies abnormal termination, such as is initiated by the abort function.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIGABRT 1

/// \brief Signifies an erroneous arithmetic operation.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIGFPE 2

/// \brief Signifies detection of an invalid function image, such as an invalid instruction.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIGILL 3

/// \brief Signifies receipt of an interactive attention signal.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIGINT 4

/// \brief Signifies an invalid access to storage.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIGSEGV 5

/// \brief Signifies a termination request sent to the program.
///
/// \note Referenced from the International C11 Standard §7.14-3.
#define SIGTERM 6

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \brief An object that can be accessed as an atomic entity.
///
/// \note Referenced from the International C11 Standard §7.14-2.
typedef volatile int sig_atomic_t; // FIXME: Make atomic_int

/// \brief Specifies how a certain signal will be handled.
///
/// \param[in]  sig     The signal handler to set (SIG*).
/// \param[in]  func    The action to set the handler to (function address or SIG_*).
///
/// \returns The parameter \c func on success and \ref SIG_ERR on failure.
///
/// \note Referenced from the International C11 Standard §7.14.1.1.
extern __public void (*signal(int sig, void (*func)(int)))(int);

/// \brief Carries out the designated action for the signal \c sig.
///
/// \param[in]  sig     The signal handler to execute.
///
/// \returns 0 on success and -1 on failure.
///
/// \note Referenced from the International C11 Standard §7.14.1.2.
extern __public int raise(int sig);

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)

#if defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)
using std::sig_atomic_t;
using std::signal;
using std::raise;
#endif // defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)

#endif // !defined(SIGNAL_BE972ECD_0D3D_4ED5_BEB3_DFB4B5BB886D)
