/// \file /platform/x86-linux/src/platform/allocate.c
///
/// \brief Implements __platform_allocate(), as defined in <platform.h>.
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

#define __USE_MISC
#include <sys/mman.h>

#include <sys/syscall.h>

/// \par Description:
/// Requests an exit from the specific hosted platform. This function should never return.
__public void* __platform_allocate(size_t size, size_t* real)
{
#ifdef __STDC_HOSTED__
    // Declare result
    void* result;

    // Delegate to the implementation
    __asm__ volatile ("movl %0, %%eax" : : "c" (SYS_mmap2) : "%eax");
    __asm__ volatile ("pushl $0");
    __asm__ volatile ("pushl $0");
    __asm__ volatile ("pushl %0" : : "c" (0x20 | MAP_PRIVATE));
    __asm__ volatile ("pushl %0" : : "c" (PROT_READ | PROT_WRITE));
    __asm__ volatile ("pushl %0" : : "m" (size));
    __asm__ volatile ("pushl $0");
    __asm__ volatile ("movl %%esp, %%ebx" : : : "%esp", "%ebx");
    __asm__ volatile ("sysenter");
    __asm__ volatile ("movl %%eax, %0" : "=a" (result));

    // We can do it.
    *real = size;

    // Return it
    return result;
#else
    // Out of luck; all we can do here
    return NULL;
#endif // defined(__STDC_HOSTED__)
}
