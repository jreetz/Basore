/// \file platform/x86-linux/src/platform/exit.i
///
/// \brief Implements __platform_exit(), as defined in <platform.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

// void __platform_exit(int status)
// Delegate exit to system call
__asm__ volatile ("movl $1, %%eax" : : : "%eax");
__asm__ volatile ("movl %0, %%ebx" : : "m" (status) : "%ebx");
__asm__ volatile ("int $0x80");
