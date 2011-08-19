/// \file src/platform/exit.c
///
/// \brief Provides __platform_exit(), as defined in <platform.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#include <platform.h>

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \par Description:
/// Requests an exit from the specific hosted platform. This function should never return.
__public __noreturn void __platform_exit(int status)
{
#ifdef __STDC_HOSTED__
    // Delegate implemention to the platform
    #include <exit.i>
#endif // defined(__STDC_HOSTED__)

    // Just halt for now
    // FIXME: Figure out how-the-hell this is supposed to be implemented.
    for ( ; ; )
    {
        // FIXME: Make the asm 'hlt' below a platform intrinsic
        __asm__ volatile ("hlt");
    }
}

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)
