#include "libc/nt/codegen.h"
.imp	kernel32,__imp_FillConsoleOutputAttribute,FillConsoleOutputAttribute,0

	.text.windows
FillConsoleOutputAttribute:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_FillConsoleOutputAttribute(%rip),%rax
	jmp	__sysv2nt6
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	FillConsoleOutputAttribute,globl
	.previous
