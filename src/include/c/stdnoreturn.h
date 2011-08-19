/// \file include/c/stdnoreturn.h
///
/// \brief Implements the standard c/c++ header <stdnoreturn.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef STDNORETURN_F8A50E4C_FC75_4B10_9502_7D47B0B35A3D
#define STDNORETURN_F8A50E4C_FC75_4B10_9502_7D47B0B35A3D

#include <configuration.h>

/// \brief Expands to an attribute to declare a function as not being able to return.
#ifndef __cplusplus
// FIXME: #define noreturn _Noreturn
#define noreturn __noreturn
#endif // !defined(__cplusplus)

#endif // !defined(STDNORETURN_F8A50E4C_FC75_4B10_9502_7D47B0B35A3D)
