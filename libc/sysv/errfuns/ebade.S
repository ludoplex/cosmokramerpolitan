#include "libc/macros.internal.h"
.text.unlikely

ebade:
#ifdef __x86_64__
	.leafprologue
	.profilable
	mov	EBADE(%rip),%ecx
	jmp	__errfun
#elif defined(__aarch64__)
	adrp	x1,EBADE
	ldr	w0,[x1,#:lo12:EBADE]
	b	__errfun
#else
#error "unsupported architecture"
#endif
	.endfn	ebade,globl,hidden
