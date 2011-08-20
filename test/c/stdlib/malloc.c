/// \file test/c/stdlib/malloc.c
///
/// \brief Provides test procedure for malloc().
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

    // Allocate some memory
    int* int_pointer = (int*)malloc(sizeof (int));
    char* char_pointer = (char*)malloc(sizeof (char));
    bool* bool_pointer = (bool*)malloc(sizeof (bool));

    // Store values
    *char_pointer = 'f';
    *bool_pointer = false;
    *int_pointer = 42362;

    // Test: Check the values
    result = result && (*int_pointer == 42362);
    result = result && (*char_pointer == 'f');
    result = result && !(*bool_pointer);

    // Free
    free(int_pointer);
    free(char_pointer);
    free(bool_pointer);

    // Set to null
    int_pointer = NULL;
    char_pointer = NULL;
    bool_pointer = NULL;

    // Free again (shouldn't error)
    free(int_pointer);
    free(char_pointer);
    free(bool_pointer);

    // Return failure
    return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
