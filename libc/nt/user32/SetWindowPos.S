#include "libc/nt/codegen.h"
.imp	user32,__imp_SetWindowPos,SetWindowPos,2400

	.text.windows
SetWindowPos:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_SetWindowPos(%rip),%rax
	jmp	__sysv2nt8
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	SetWindowPos,globl
	.previous
