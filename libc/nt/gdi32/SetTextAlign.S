#include "libc/nt/codegen.h"
.imp	gdi32,__imp_SetTextAlign,SetTextAlign,1910

	.text.windows
SetTextAlign:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_SetTextAlign(%rip),%rax
	jmp	__sysv2nt
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	SetTextAlign,globl
	.previous
