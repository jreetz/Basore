/// \file src/runtime/initialize.c
///
/// \brief Provides the runtime initialization procedure.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#include <configuration.h>

#ifdef __cplusplus
extern "C" {
#endif // defined(__cplusplus)

/// \brief Runtime initialization procedure.
__constant void _init()
{
    // TODO: Iterate through .init_array; call all static constructors
    // TODO: Iterate through .ctors; call all static constructors
}

#ifdef __cplusplus
} // extern "C" {
#endif // defined(__cplusplus)
