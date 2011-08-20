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

// Buffered space available to malloc() and friends when os fails.
unsigned char _BASORE_emergency_buffer[MEMORY_EMERGENCY_BUFFER];

// Emergency memory block.
struct _BASORE_memory_chunk _BASORE_emergency_memory_chunk = { NULL, MEMORY_EMERGENCY_BUFFER };

// \brief First normal memory chunk.
struct _BASORE_memory_chunk _BASORE_first_memory_chunk = { NULL, 0 };

// Linked list of quick exit functions.
struct _BASORE_function _BASORE_quick_exit_functions[QUICK_EXIT_FUNCTION_BUFFERED];

// Next Pseudo-random Number
unsigned int _BASORE_rand_next = 1;
