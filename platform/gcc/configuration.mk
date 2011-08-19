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

# Varidac Macros
MACRO_VA_START              := __builtin_va_start
MACRO_VA_END                := __builtin_va_end
MACRO_VA_ARG                := __builtin_va_arg
MACRO_VA_COPY               := __builtin_va_copy

# Varidac Types
TYPE_VA_LIST                := __builtin_va_list

# Standard Limits
LIMIT_BIT                   := __CHAR_BIT__
LIMIT_CHAR                  := __SCHAR_MAX__
LIMIT_SHORT                 := __SHRT_MAX__
LIMIT_INT                   := __INT_MAX__
LIMIT_LONG                  := __LONG_MAX__
LIMIT_LONG_LONG             := __LONG_LONG_MAX__

# Standard Conditionals
CONDITION_CHAR_UNSIGNED     := defined(__CHAR_UNSIGNED__)

# Standard Integer Conditionals
CONDITION_INT8              := defined(__INT8_TYPE__)
CONDITION_INT16             := defined(__INT16_TYPE__)
CONDITION_INT32             := defined(__INT32_TYPE__)
CONDITION_INT64             := defined(__INT64_TYPE__)

CONDITION_UINT8             := defined(__UINT8_TYPE__)
CONDITION_UINT16            := defined(__UINT16_TYPE__)
CONDITION_UINT32            := defined(__UINT32_TYPE__)
CONDITION_UINT64            := defined(__UINT64_TYPE__)

# Standard Integer Types
TYPE_INT8                   := __INT8_TYPE__
TYPE_INT16                  := __INT16_TYPE__
TYPE_INT32                  := __INT32_TYPE__
TYPE_INT64                  := __INT64_TYPE__

TYPE_UINT8                  := __UINT8_TYPE__
TYPE_UINT16                 := __UINT16_TYPE__
TYPE_UINT32                 := __UINT32_TYPE__
TYPE_UINT64                 := __UINT64_TYPE__

TYPE_INT_LEAST8             := __INT_LEAST8_TYPE__
TYPE_INT_LEAST16            := __INT_LEAST16_TYPE__
TYPE_INT_LEAST32            := __INT_LEAST32_TYPE__
TYPE_INT_LEAST64            := __INT_LEAST64_TYPE__

TYPE_UINT_LEAST8            := __UINT_LEAST8_TYPE__
TYPE_UINT_LEAST16           := __UINT_LEAST16_TYPE__
TYPE_UINT_LEAST32           := __UINT_LEAST32_TYPE__
TYPE_UINT_LEAST64           := __UINT_LEAST64_TYPE__

TYPE_INT_FAST8              := __INT_FAST8_TYPE__
TYPE_INT_FAST16             := __INT_FAST16_TYPE__
TYPE_INT_FAST32             := __INT_FAST32_TYPE__
TYPE_INT_FAST64             := __INT_FAST64_TYPE__

TYPE_UINT_FAST8             := __UINT_FAST8_TYPE__
TYPE_UINT_FAST16            := __UINT_FAST16_TYPE__
TYPE_UINT_FAST32            := __UINT_FAST32_TYPE__
TYPE_UINT_FAST64            := __UINT_FAST64_TYPE__

TYPE_INTPTR                 := __INTPTR_TYPE__
TYPE_UINTPTR                := __UINTPTR_TYPE__

TYPE_INTMAX                 := __INTMAX_TYPE__
TYPE_UINTMAX                := __UINTMAX_TYPE__

# Standard Integer Limits
LIMIT_INT8                  := __INT8_MAX__
LIMIT_INT16                 := __INT16_MAX__
LIMIT_INT32                 := __INT32_MAX__
LIMIT_INT64                 := __INT64_MAX__

LIMIT_UINT8                 := __UINT8_MAX__
LIMIT_UINT16                := __UINT16_MAX__
LIMIT_UINT32                := __UINT32_MAX__
LIMIT_UINT64                := __UINT64_MAX__

LIMIT_INT_LEAST8            := __INT_LEAST8_MAX__
LIMIT_INT_LEAST16           := __INT_LEAST16_MAX__
LIMIT_INT_LEAST32           := __INT_LEAST32_MAX__
LIMIT_INT_LEAST64           := __INT_LEAST64_MAX__

LIMIT_UINT_LEAST8           := __UINT_LEAST8_MAX__
LIMIT_UINT_LEAST16          := __UINT_LEAST16_MAX__
LIMIT_UINT_LEAST32          := __UINT_LEAST32_MAX__
LIMIT_UINT_LEAST64          := __UINT_LEAST64_MAX__

LIMIT_INT_FAST8             := __INT_FAST8_MAX__
LIMIT_INT_FAST16            := __INT_FAST16_MAX__
LIMIT_INT_FAST32            := __INT_FAST32_MAX__
LIMIT_INT_FAST64            := __INT_FAST64_MAX__

LIMIT_UINT_FAST8            := __UINT_FAST8_MAX__
LIMIT_UINT_FAST16           := __UINT_FAST16_MAX__
LIMIT_UINT_FAST32           := __UINT_FAST32_MAX__
LIMIT_UINT_FAST64           := __UINT_FAST64_MAX__

LIMIT_INTPTR                := __INTPTR_MAX__
LIMIT_UINTPTR               := __UINTPTR_MAX__

LIMIT_INTMAX                := __INTMAX_MAX__
LIMIT_UINTMAX               := __UINTMAX_MAX__

LIMIT_SIZE                  := __SIZE_MAX__
LIMIT_WIDE_CHARACTER        := __WCHAR_MAX__
LIMIT_WIDE_INT              := __WINT_MAX__
LIMIT_SIG_ATMOIC            := __SIG_ATOMIC_MAX__

# Standard Integer Constants
CONSTANT_INT8               := __INT8_C__
CONSTANT_INT16              := __INT16_C__
CONSTANT_INT32              := __INT32_C__
CONSTANT_INT64              := __INT64_C__

CONSTANT_UINT8              := __UINT8_C__
CONSTANT_UINT16             := __UINT16_C__
CONSTANT_UINT32             := __UINT32_C__
CONSTANT_UINT64             := __UINT64_C__
