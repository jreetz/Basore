/// \file include/c/stdbool.h
///
/// \brief Implements the standard c/c++ header <stdbool.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef STDBOOL_0EAA2C56_2857_490B_BBF3_F19B96388087
#define STDBOOL_0EAA2C56_2857_490B_BBF3_F19B96388087

#ifndef __cplusplus

/// \brief Expands to the C11 boolean datatype.
#define bool _Bool

/// \brief Expands to the integer constant 1.
#define true 1

/// \brief Expands to the integer constant 0.
#define false 0

#endif // !defined(__cplusplus)

/// \brief Expands to the integer constant 1 to indicate the boolean type is available.
#define __bool_true_false_are_defined 1

#endif // !defined(STDBOOL_0EAA2C56_2857_490B_BBF3_F19B96388087)
