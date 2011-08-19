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
/// The \ref raise function carries out the actions described for the \ref signal function for
/// the signal \c sig. If a signal handler is called, the \ref raise function shall not return
/// until after the signal handler does.
__public int raise(int sig)
{
    // Is there a valid signal handler ?
    // FIXME: Perhaps forward SIG_DFL to the system ?
    if (__signal_handlers[sig] != SIG_ERR &&
        __signal_handlers[sig] != SIG_DFL &&
        __signal_handlers[sig] != SIG_IGN)
    {
        // Yes; call it.
        __signal_handlers[sig](sig);

        // Return success
        return 0;
    }

    // Return failure
    return -1;
}

#ifdef __cplusplus
} // namespace std {
#endif // defined(__cplusplus)
