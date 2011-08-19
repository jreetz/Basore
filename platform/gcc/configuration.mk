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
ATTRIBUTE_PUBLIC            := __attribute__ ((visibility("default")))
ATTRIBUTE_PROTECTED         := __attribute__ ((visibility("hidden")))
ATTRIBUTE_PRIVATE           := __attribute__ ((visibility("internal")))
ATTRIBUTE_CONSTANT          := __attribute__ ((const))
ATTRIBUTE_PURE              := __attribute__ ((pure))
ATTRIBUTE_NORETURN          := __attribute__ ((noreturn))

# Standard Types
TYPE_POINTER_DIFFERENCE     := __PTRDIFF_TYPE__
TYPE_SIZE                   := __SIZE_TYPE__
TYPE_MAXIMUM_ALIGNMENT      := __MAX_ALIGN_TYPE__
TYPE_WIDE_CHARACTER         := __WCHAR_TYPE__

# Standard Macros
MACRO_OFFSETOF              := __builtin_offsetof

# Standard Limits
LIMIT_BIT                   := __CHAR_BIT__
LIMIT_CHAR                  := __SCHAR_MAX__
LIMIT_SHORT                 := __SHRT_MAX__
LIMIT_INT                   := __INT_MAX__
LIMIT_LONG                  := __LONG_MAX__
LIMIT_LONG_LONG             := __LONG_LONG_MAX__

# Standard Conditionals
CONDITION_CHAR_UNSIGNED     := defined(__CHAR_UNSIGNED__)
