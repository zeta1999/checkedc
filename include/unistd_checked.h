//---------------------------------------------------------------------//
// Bounds-safe interfaces for functions in unistd.h that               //
// take pointer arguments.                                             //
//                                                                     //
// These are POSIX-only                                                //
/////////////////////////////////////////////////////////////////////////

#ifndef __cplusplus
#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE off
#endif

#include <unistd.h>

#ifndef __cplusplus
#pragma CHECKED_SCOPE pop
#endif

#ifndef __cplusplus
#ifndef __UNISTD_CHECKED_H
#define __UNISTD_CHECKED_H

#pragma CHECKED_SCOPE push
#pragma CHECKED_SCOPE on

#if _POSIX_VERSION >= 200112L

extern char ** environ : itype(_Nt_array_ptr<_Nt_array_ptr<char>>);

#ifdef __APPLE__

extern int access (const char *__name : itype(_Nt_array_ptr<const char>), int __type);
extern ssize_t read (int __fd, void *__buf : byte_count(__nbytes), size_t __nbytes);
extern ssize_t write (int __fd, const void *__buf : byte_count(__n), size_t __n);

#else

extern int access (const char *__name : itype(_Nt_array_ptr<const char>), int __type) __THROW __nonnull ((1));
extern ssize_t read (int __fd, void *__buf : byte_count(__nbytes), size_t __nbytes) __wur;
extern ssize_t write (int __fd, const void *__buf : byte_count(__n), size_t __n) __wur;

#endif
#endif

#pragma CHECKED_SCOPE pop

#endif
#endif
