/// \file src/c/stdlib/internal.h
///
/// \brief Provides private types and variables.
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

/// \brief Function callback type to be registered by at*() and called by *exit().
struct _BASORE_function
{
    /// \brief Address of next function callback description.
    struct _BASORE_function* next;

    /// \brief Address of this callback.
    void (*address)();
};

/// \brief Number of buffered (for sure available) quick exit functions.
#define QUICK_EXIT_FUNCTION_BUFFERED  32

/// \brief Linked list of exit functions.
extern struct _BASORE_function _BASORE_quick_exit_functions[QUICK_EXIT_FUNCTION_BUFFERED];
