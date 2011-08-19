/// \file include/c/stdarg.h
///
/// \brief Implements the standard c/c++ header <stdarg.h>.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
#ifndef STDARG_1F544C63_F7EB_455B_8F77_6B93D7AE997D
#define STDARG_1F544C63_F7EB_455B_8F77_6B93D7AE997D

/// \brief Expands to an expression that has the value of the next argument.
#define va_arg(ap, type) _BASORE_va_arg(ap, type)

/// \brief Initializes ap for subsequent use by the \ref va_arg and \ref va_end macros.
#define va_start(ap, paramN) _BASORE_va_start(ap, paramN)

/// \brief Facilitates a normal return from the varidac function.
#define va_end(ap) _BASORE_va_end(ap)

/// \brief Initializes dest as a copy of src.
#define va_copy(dest, src) _BASORE_va_copy(dest, src)

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \brief Complete object type suitable for holding information needed by the macros.
typedef _BASORE_va_list va_list;

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)

#if defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)
using std::va_list;
#endif //defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)

#endif // !defined(STDARG_1F544C63_F7EB_455B_8F77_6B93D7AE997D)
