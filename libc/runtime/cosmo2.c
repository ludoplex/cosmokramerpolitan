/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2023 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/calls/syscall-sysv.internal.h"
#include "libc/dce.h"
#include "libc/intrin/kprintf.h"
#include "libc/intrin/strace.internal.h"
#include "libc/macros.internal.h"
#include "libc/nexgen32e/rdtsc.h"
#include "libc/runtime/internal.h"
#include "libc/runtime/memtrack.internal.h"
#include "libc/runtime/runtime.h"
#include "libc/thread/thread.h"
#include "libc/thread/tls.h"
#ifndef __x86_64__

int main(int, char **, char **) __attribute__((__weak__));

#if 0
static inline long sys_set_tid_address(int *t) {
  register long res asm("x0");
  register long arg asm("x0") = (long)t;
  asm volatile("mov\tx8,%1\n\t"
               "svc\t0"
               : "=r"(res)
               : "i"(96), "r"(arg)
               : "x8", "memory");
  return res;
}
#endif

typedef int init_f(int argc, char **argv, char **envp, unsigned long *auxv);

extern init_f __strace_init;
extern init_f *__init_array_start[] __attribute__((__weak__));
extern init_f *__init_array_end[] __attribute__((__weak__));
extern pthread_mutex_t __mmi_lock_obj;

textstartup void cosmo(long *sp) {
  int argc;
  init_f **fp;
  uintptr_t *pp;
  char **argv, **envp;
  unsigned long *auxv;

  // get startup timestamp as early as possible
  // its used by --strace and also kprintf() %T
  kStartTsc = rdtsc();

  // extracts arguments from old sysv stack abi
  argc = *sp;
  argv = (char **)(sp + 1);
  envp = (char **)(sp + 1 + argc + 1);
  auxv = (unsigned long *)(sp + 1 + argc + 1);
  while (*auxv++) donothing;

  // needed by kisdangerous()
  __oldstack = (intptr_t)sp;
  __pid = sys_getpid().ax;

  // initialize mmap() manager extremely early
  _mmi.n = ARRAYLEN(_mmi.s);
  _mmi.p = _mmi.s;
  __mmi_lock_obj._type = PTHREAD_MUTEX_RECURSIVE;
  InitializeFileDescriptors();

#ifdef SYSDEBUG
  // initialize --strace functionality
  argc = __strace_init(argc, argv, envp, auxv);
#endif

#if IsAsan()
  __asan_init(argc, argv, envp, auxv);
#endif

  // set helpful globals
  __argc = argc;
  __argv = argv;
  __envp = envp;
  __auxv = auxv;
  environ = envp;
  if (argc) program_invocation_name = argv[0];

  // run initialization callbacks
  _init();
  __enable_tls();
  for (fp = __init_array_end; fp-- > __init_array_start;) {
    (*fp)(argc, argv, envp, auxv);
  }

  // run program
  exit(main(argc, argv, envp));
}

#endif /* __x86_64__ */
