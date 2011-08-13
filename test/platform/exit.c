/// \file test/platform/exit.c
///
/// \brief Provides test procedure for __platform_exit().
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

// Test procedure for ::__platform_exit()
int main()
{
    // Return success
    __platform_exit(0);

    // Return failure
    return -1;
}
