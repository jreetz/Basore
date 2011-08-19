/// \file test/c/stdlib/llabs.c
///
/// \brief Provides test procedure for llabs().
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
#include <stdbool.h>

// Test procedure for abs()
int main()
{
    // Declare result
    bool result = true;

    // Test
    result = result && (llabs( 2423432423324) == 2423432423324);
    result = result && (llabs(-2423432423324) == 2423432423324);

    // Return failure
    return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
