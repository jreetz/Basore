## \file platform/gcc/configuration.mk
##
## \brief Provides the configuration parameters specific to gcc.
##
## \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
##
## To the extent possible under law, the author(s) have dedicated all copyright and related and
## neighboring rights to this software to the public domain worldwide. This software is distributed
## without any warranty.
##
## You should have received a copy of the CC0 Public Domain Dedication along with this software.
## If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

# Function Attributes
ATTRIBUTE_PUBLIC    := __attribute__ ((visibility("default")))
ATTRIBUTE_PROTECTED := __attribute__ ((visibility("hidden")))
ATTRIBUTE_PRIVATE   := __attribute__ ((visibility("internal")))
ATTRIBUTE_CONSTANT  := __attribute__ ((const))
ATTRIBUTE_PURE      := __attribute__ ((pure))
ATTRIBUTE_NORETURN  := __attribute__ ((noreturn))
