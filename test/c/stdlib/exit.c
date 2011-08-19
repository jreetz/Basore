/// \file test/c/stdlib/exit.c
///
/// \brief Provides test procedure for exit().
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

// Test procedure for exit()
int main()
{
    // Attempt to exit using exit
    exit(EXIT_SUCCESS);

    // Return failure
    return EXIT_FAILURE;
}
