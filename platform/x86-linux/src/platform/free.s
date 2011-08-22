## \file platform/x86-linux/src/platform/free.s
##
## \brief Implements the __platform_free() procedure, as defined in <platform.h>.
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
.global __platform_free

## \brief Free memory to the system.
##
## \param[in]   size    Amount of memory to free (hint).
## \param[in]   memory  Memory address to free.
__platform_free:
    pushl   %eax
    pushl   %ebx
    pushl   %ecx

    movl    $91,        %eax        # SYS_munmap
    movl    22(%esp),   %ebx        # memory address
    movl    18(%esp),   %ecx        # size to free

    int     $0x80

    popl    %ecx
    popl    %ebx
    popl    %eax

    ret
