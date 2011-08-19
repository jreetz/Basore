/// \file include/c/stdlib.h
///
/// \brief Implements the standard c/c++ header <stdlib.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef STDLIB_4717D28D_B9BE_49F9_92A9_0924ED5D6709
#define STDLIB_4717D28D_B9BE_49F9_92A9_0924ED5D6709

#include <configuration.h>

/// \brief Designates a success status when returned to the environment.
///
/// \note Referenced from the International C11 Standard §7.22-3.
#define EXIT_SUCCESS (0)

/// \brief Designates a failure status when returned to the environment.
///
/// \note Referenced from the International C11 Standard §7.22-3.
#define EXIT_FAILURE (-1)

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \brief Causes an abnormal termination from the calling process.
///
/// \returns Does not return.
///
/// \note Referenced from the International C11 Standard §7.22.4.1.
extern __public __noreturn void abort();

/// \brief Causes a normal termination from the calling process.
///
/// \param[in]  status  The status to return to the environment.
///
/// \returns Does not return.
///
/// \note Referenced from the International C11 Standard §7.22.4.4.
extern __public __noreturn void exit(int status);

/// \brief Causes a fast termination from the calling process.
///
/// \param[in]  status  The status to return to the environment.
///
/// \returns Does not return.
///
/// \note Referenced from the International C11 Standard §7.22.4.7.
extern __public __noreturn void quick_exit(int status);

/// \brief Causes an immediate termination from the calling process.
///
/// \param[in]  status  The status to return to the environment.
///
/// \returns Does not return.
///
/// \note Referenced from the International C11 Standard §7.22.4.5.
extern __public __noreturn void _Exit(int status);

/// \brief Registers a function to be called upon normal termination.
///
/// \param[in]  func    The function to be registered.
///
/// \returns 0 on success and -1 on failure.
///
/// \note Referenced from the International C11 Standard §7.22.4.2.
extern __public int atexit(void (*func)());

/// \brief Registers a function to be called upon fast termination.
///
/// \param[in]  func    The function to be registered.
///
/// \returns 0 on success and -1 on failure.
///
/// \note Referenced from the International C11 Standard §7.22.4.3.
extern __public int at_quick_exit(void (*func)());

/// \brief Retrieves a value from an environment list.
///
/// \param[in]  name    Name of the environment variable.
///
/// \returns A pointer to the associated string, or a null pointer if it cannot be found.
///
/// \note Referenced from the International C11 Standard §7.22.4.6.
extern __public char* getenv(const char* name);

/// \brief Execute system command.
///
/// \param[in]  string  Name of the requested command.
///
/// \returns If \c string is null, returns non-zero if a command processor is available; else,
///          returns the result of the executed command.
///
/// \note Referenced from the International C11 Standard §7.22.4.8.
extern __public int system(const char* string);

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)

#if defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)
using std::exit;
using std::_Exit;
using std::abort;
using std::quick_exit;
using std::atexit;
using std::at_quick_exit;
#endif // defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)

#endif //!defined(STDLIB_4717D28D_B9BE_49F9_92A9_0924ED5D6709)
