/// \file include/c/stdalign.h
///
/// \brief Implements the standard c/c++ header <stdalign.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef STDALIGN_3AD91849_CBAB_4A25_AD59_030E2BB641E9
#define STDALIGN_3AD91849_CBAB_4A25_AD59_030E2BB641E9

#ifndef __cplusplus

/// \brief Forces the type to be declared with alignment constraints of the passed type.
#define alignas _Alignas

/// \brief Expands to the alignment, in bytes, for the passed type of object.
#define alignof _Alignof

#endif // !defined(__cplusplus)

/// \brief Expands to the integer constant 1 to indicate we have alignas.
#define __alignas_is_defined 1

/// \brief Expands to the integer constant 1 to indicate we have alignof.
#define __alignof_is_defined 1

#endif // !defined(STDALIGN_3AD91849_CBAB_4A25_AD59_030E2BB641E9)
