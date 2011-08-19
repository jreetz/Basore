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

/// \brief Null pointer constant.
///
/// \note Referenced from the International C11 Standard §7.19-3.
#ifdef __cplusplus
#define NULL nullptr
#else
#define NULL (void*)0
#endif

/// \brief Designates a success status when returned to the environment.
///
/// \note Referenced from the International C11 Standard §7.22-3.
#define EXIT_SUCCESS (0)

/// \brief Designates a failure status when returned to the environment.
///
/// \note Referenced from the International C11 Standard §7.22-3.
#define EXIT_FAILURE (-1)

/// \brief Maximum value returned by the rand function.
///
/// \note Referenced from the International C11 Standard §7.22-3.
#define RAND_MAX 32767

/// \brief Maximum number of bytes of a multibyte character, currently.
///
/// \note Referenced from the International C11 Standard §7.22-3.
#define MB_CUR_MAX 1

#ifdef __cplusplus
namespace std {
#endif //defined(__cplusplus)

/// \brief The unsigned integer type of the result of the sizeof operator.
///
/// \note Referenced from the International C11 Standard §7.19-2.
typedef _BASORE_size_t size_t;

/// \brief Can represent distinct codes for all members of the largest extended character set.
///
/// \note Referenced from the International C11 Standard §7.19-2.
#ifndef __cplusplus
typedef _BASORE_wchar_t wchar_t;
#endif //!defined(__cplusplus)

/// \brief Is the type returned by the div() function.
///
/// \note Referenced from the International C11 Standard §7.22-2.
typedef _BASORE_div_t div_t;

/// \brief Is the type returned by the ldiv() function.
///
/// \note Referenced from the International C11 Standard §7.22-2.
typedef _BASORE_ldiv_t ldiv_t;

/// \brief Is the type returned by the lldiv() function.
///
/// \note Referenced from the International C11 Standard §7.22-2.
typedef _BASORE_lldiv_t lldiv_t;

/// \brief Computes the next number in the pseudo-random number sequnece.
///
/// \returns Returns a pseudo-random number.
///
/// \note Referenced from the International C11 Standard §7.22.2.1.
extern __public int rand();

/// \brief Seeds the pseudo-random number generator.
///
/// \param[in]  seed    The seed to use.
///
/// \note Referenced from the International C11 Standard §7.22.2.2.
extern __public void srand(unsigned int seed);

/// \brief Allocates a block of suitably aligned memory.
///
/// \param[in]  alignment   The power-of-2 alignment for the allocation.
/// \param[in]  size        The number of bytes to allocate.
///
/// \returns The allocated memory or null.
///
/// \note Referenced from the International C11 Standard §7.22.3.1.
extern __public void* aligned_alloc(size_t alignment, size_t size);

/// \brief Allocates a block of memory.
///
/// \param[in]  size        The number of bytes to allocate.
///
/// \returns The allocated memory or null.
///
/// \note Referenced from the International C11 Standard §7.22.3.4.
extern __public void* malloc(size_t size);

/// \brief Allocates and clears a block of memory.
///
/// \param[in]  nmemb       The number of elements to allocate.
/// \param[in]  size        The number of bytes per element.
///
/// \returns The allocated memory or null.
///
/// \note Referenced from the International C11 Standard §7.22.3.2
extern __public void* calloc(size_t nmemb, size_t size);

/// \brief Frees a block of memory.
///
/// \param[in]  ptr     Address of the memory to free.
///
/// \note Referenced from the International C11 Standard §7.22.3.3.
extern __public void free(void* ptr);

/// \brief Reallocates a block of memory.
///
/// \param[in]  ptr         Address of the block of memory to reallocate.
/// \param[in]  size        The new number of bytes to allocate.
///
/// \returns The reallocated memory or null.
///
/// \note Referenced from the International C11 Standard §7.22.3.4.
extern __public void* realloc(void* ptr, size_t size);

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

/// \brief Computes the absolute value of the passed \c value.
///
/// \param[in]  j   The value to compute absolute value on.
///
/// \returns The absolute value of \c j.
///
/// \note Referenced from the International C11 Standard §7.22.6.1.
extern __public int abs(int j);

#ifdef __cplusplus
/// \brief Computes the absolute value of the passed \c value.
///
/// \param[in]  j   The value to compute absolute value on.
///
/// \returns The absolute value of \c j.
///
/// \note Referenced from the International C11 Standard §7.22.6.1.
extern __public long int abs(long int j);

/// \brief Computes the absolute value of the passed \c value.
///
/// \param[in]  j   The value to compute absolute value on.
///
/// \returns The absolute value of \c j.
///
/// \note Referenced from the International C11 Standard §7.22.6.1.
extern __public long long int abs(long long int j);
#endif // defined(__cplusplus)

/// \brief Computes the absolute value of the passed \c value.
///
/// \param[in]  j   The value to compute absolute value on.
///
/// \returns The absolute value of \c j.
///
/// \note Referenced from the International C11 Standard §7.22.6.1.
extern __public long int labs(long int j);

/// \brief Computes the absolute value of the passed \c value.
///
/// \param[in]  j   The value to compute absolute value on.
///
/// \returns The absolute value of \c j.
///
/// \note Referenced from the International C11 Standard §7.22.6.1.
extern __public long long int llabs(long long int j);

/// \brief Computes the quotient and remainder of two integers in a single operation.
///
/// \param[in]  numer   The dividend of the division expression.
/// \param[in]  denom   The divisor of the division expression.
///
/// \returns The quotient and remainder of the division expression.
///
/// \note Referenced from the International C11 Standard §7.22.6.2.
extern __public div_t div(int numer, int denom);

#ifdef __cplusplus
/// \brief Computes the quotient and remainder of two integers in a single operation.
///
/// \param[in]  numer   The dividend of the division expression.
/// \param[in]  denom   The divisor of the division expression.
///
/// \returns The quotient and remainder of the division expression.
///
/// \note Referenced from the International C11 Standard §7.22.6.2.
extern __public ldiv_t div(long int numer, long int denom);

/// \brief Computes the quotient and remainder of two integers in a single operation.
///
/// \param[in]  numer   The dividend of the division expression.
/// \param[in]  denom   The divisor of the division expression.
///
/// \returns The quotient and remainder of the division expression.
///
/// \note Referenced from the International C11 Standard §7.22.6.2.
extern __public lldiv_t div(long long int numer, long long int denom);
#endif // defnied(__cplusplus)

/// \brief Computes the quotient and remainder of two integers in a single operation.
///
/// \param[in]  numer   The dividend of the division expression.
/// \param[in]  denom   The divisor of the division expression.
///
/// \returns The quotient and remainder of the division expression.
///
/// \note Referenced from the International C11 Standard §7.22.6.2.
extern __public ldiv_t ldiv(long int numer, long int denom);

/// \brief Computes the quotient and remainder of two integers in a single operation.
///
/// \param[in]  numer   The dividend of the division expression.
/// \param[in]  denom   The divisor of the division expression.
///
/// \returns The quotient and remainder of the division expression.
///
/// \note Referenced from the International C11 Standard §7.22.6.2.
extern __public lldiv_t lldiv(long long int numer, long long int denom);

#ifdef __cplusplus
} // namespace std {
#endif //defined(__cplusplus)

#if defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)
using std::size_t;
using std::div_t;
using std::ldiv_t;
using std::lldiv_t;
using std::rand;
using std::srand;
using std::aligned_alloc;
using std::malloc;
using std::calloc;
using std::free;
using std::realloc;
using std::exit;
using std::_Exit;
using std::abort;
using std::quick_exit;
using std::atexit;
using std::at_quick_exit;
using std::getenv;
using std::system;
using std::abs;
using std::div;
using std::labs;
using std::llabs;
using std::ldiv;
using std::lldiv;
#endif // defined(__cplusplus) && !defined(_BASORE_NO_C_COMPAT)

#endif //!defined(STDLIB_4717D28D_B9BE_49F9_92A9_0924ED5D6709)
