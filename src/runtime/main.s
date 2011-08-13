## \file src/runtime/main.s
##
## \brief Provides the runtime start-up procedure.
##
## \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
##
## To the extent possible under law, the author(s) have dedicated all copyright and related and
## neighboring rights to this software to the public domain worldwide. This software is distributed
## without any warranty.
##
## You should have received a copy of the CC0 Public Domain Dedication along with this software.
## If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

# Declare procedure
.global _start

## \brief Runtime start-up procedure; for executables only.
_start:
    call    _init

    call    main
    pushl   %eax

    call    _fini

    call __platform_exit
