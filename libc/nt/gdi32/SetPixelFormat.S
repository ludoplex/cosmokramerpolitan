#include "libc/nt/codegen.h"
.imp	gdi32,__imp_SetPixelFormat,SetPixelFormat,1902

	.text.windows
SetPixelFormat:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_SetPixelFormat(%rip),%rax
	jmp	__sysv2nt
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	SetPixelFormat,globl
	.previous
