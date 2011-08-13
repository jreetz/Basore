/// \file src/runtime/finalize.s
///
/// \brief Provides the runtime finalization procedure.
///
/// \author Ryan Leckey (mehcode) leckey.ryan@gmail.com
///
/// To the extent possible under law, the author(s) have dedicated all copyright and related and
/// neighboring rights to this software to the public domain worldwide. This software is distributed
/// without any warranty.
///
/// You should have received a copy of the CC0 Public Domain Dedication along with this software.
/// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

#ifdef __cplusplus
extern "C" {
#endif // defined(__cplusplus)

/// \brief Runtime finalization procedure.
void _fini()
{
    // TODO: Call __cxa_finalize(&__dso_handle)
    // TODO: Iterate through .fini_array; call all static destructors
    // TODO: Iterate through .dtors; call all static destructors
}

#ifdef __cplusplus
} // extern "C" {
#endif // defined(__cplusplus)
