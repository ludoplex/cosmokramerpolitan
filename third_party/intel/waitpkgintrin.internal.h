#if !defined _IMMINTRIN_H_INCLUDED
#error "Never use <waitpkgintrin.h> directly; include <immintrin.h> instead."
#endif

#ifndef _WAITPKG_H_INCLUDED
#define _WAITPKG_H_INCLUDED

#ifndef __WAITPKG__
#pragma GCC push_options
#pragma GCC target("waitpkg")
#define __DISABLE_WAITPKG__
#endif /* __WAITPKG__ */

extern __inline void
    __attribute__((__gnu_inline__, __always_inline__, __artificial__))
    _umonitor(void *__A) {
  __builtin_ia32_umonitor(__A);
}

extern __inline unsigned char
    __attribute__((__gnu_inline__, __always_inline__, __artificial__))
    _umwait(unsigned int __A, unsigned long long __B) {
  return __builtin_ia32_umwait(__A, __B);
}

extern __inline unsigned char
    __attribute__((__gnu_inline__, __always_inline__, __artificial__))
    _tpause(unsigned int __A, unsigned long long __B) {
  return __builtin_ia32_tpause(__A, __B);
}

#ifdef __DISABLE_WAITPKG__
#undef __DISABLE_WAITPKG__
#pragma GCC pop_options
#endif /* __DISABLE_WAITPKG__ */

#endif /* _WAITPKG_H_INCLUDED.  */
