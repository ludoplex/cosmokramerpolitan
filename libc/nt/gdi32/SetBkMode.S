#include "libc/nt/codegen.h"
.imp	gdi32,__imp_SetBkMode,SetBkMode,1872

	.text.windows
SetBkMode:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_SetBkMode(%rip),%rax
	jmp	__sysv2nt
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	SetBkMode,globl
	.previous
