/// \file test/c/stdlib/abort.c
///
/// \brief Provides test procedure for abort().
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
#include <platform.h>
#include <stdnoreturn.h>

// Signal handler for SIGABRT
__noreturn void abort_handler(__attribute__ ((unused)) int signal)
{
    // Just return success
    __platform_exit(EXIT_SUCCESS);
}

// Test procedure for abort()
int main()
{
    // Attempt to register signal handler
    if (signal(SIGABRT, &abort_handler) != &abort_handler)
    {
        // Failed to register handler, bail
        return EXIT_FAILURE;
    }

    // Attempt to abort
    abort();

    // Return failure
    return EXIT_FAILURE;
}
