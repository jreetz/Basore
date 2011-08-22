## \file platform/x86-linux/src/platform/allocate.s
##
## \brief Implements the __platform_allocate() procedure, as defined in <platform.h>.
##
## \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
##
## To the extent possible under law, the author(s) have dedicated all copyright and related and
## neighboring rights to this software to the public domain worldwide. This software is distributed
## without any warranty.
##
## You should have received a copy of the CC0 Public Domain Dedication along with this software.
## If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

# Declare function visibility
.global __platform_allocate

## \brief Allocates memory from the system.
##
## \param[in]   size    Amount of memory to allocate.
## \param[out]  real    Actual amount of memory allocated.
##
## \returns The requested memory or null.
__platform_allocate:
    pushl   %ebx
    pushl   %ecx
    pushl   %edx
    pushl   %esi
    pushl   %edi
    pushl   %ebp

    movl    $192,       %eax        # SYS_mmap2
    movl    $0,         %ebx
    movl    28(%esp),   %ecx        # 'size'
    movl    $0x03,      %edx        # PROT_READ | PROT_WRITE
    movl    $0x22,      %esi        # MAP_ANONYMOUS | MAP_PRIVATE
    movl    $0,         %edi
    movl    $0,         %ebp

    int     $0x80

    movl    28(%esp),   %ecx        # 'size'
    movl    32(%esp),   %ebx
    movl    %ecx,       (%ebx)

    popl    %ebp
    popl    %edi
    popl    %esi
    popl    %edx
    popl    %ecx
    popl    %ebx

    ret
