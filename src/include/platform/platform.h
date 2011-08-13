/// \file include/platform.h
///
/// \brief Provides platform method calls to abstract platform details.
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
namespace std {
#endif //defined(__cplusplus)

/// \brief Exits the application and returns to the environment.
///
/// \returns Does not return.
__public __noreturn void __platform_exit();

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)
