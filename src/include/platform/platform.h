/// \file include/platform/platform.h
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
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // defined(__cplusplus)

/// \brief Exits the application and returns to the environment.
///
/// \returns Does not return.
__public __noreturn void __platform_exit();

/// \brief Allocates at least the requested size (in bytes) of memory.
///
/// This function need not allocate -exactly- the requested size. In cases where the underlying
/// system may only allocate in pages then it would simply allocate the nearest available size
/// and return the real size in the second parameter.
///
/// \param[in]  size    The requested size to allocate.
/// \param[out] real    The real allocated size (if allocated).
///
/// \returns Returns the allocated memory or null.
__public void* __platform_allocate(size_t size, size_t* real);

/// \brief Frees size (in bytes) from the passed memory.
///
/// \param[in]  size    The size (in bytes) of the memory to free.
/// \param[in]  memory  Address of the memory to free.
__public void* __platform_free(size_t size, void* memory);

#ifdef __cplusplus
} // extern "C" {
#endif // defined(__cplusplus)
