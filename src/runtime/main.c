/// \file src/runtime/main.c
///
/// \brief Provides the runtime main procedure.
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
extern "C" {
#endif // defined(__cplusplus)

/// \brief Runtime main procedure.
void _start()
{
    // Declare status
    int status;

    // Call initialize and main
    __asm__ volatile (
        "call _init;"
        "call main;"
        "movl %%eax, %0;"
        : "=g" (status) : : "%eax");

    // Call exit procedure
    exit(status);
}

#ifdef __cplusplus
} // extern "C" {
#endif // defined(__cplusplus)
