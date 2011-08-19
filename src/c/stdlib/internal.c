/// \file src/c/stdlib/internal.c
///
/// \brief Implements private types and variables.
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

// Linked list of quick exit functions.
struct _BASORE_function _BASORE_quick_exit_functions[QUICK_EXIT_FUNCTION_BUFFERED];
