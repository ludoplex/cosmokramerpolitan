#include "libc/nt/codegen.h"
.imp	kernel32,__imp_PurgeComm,PurgeComm,0

	.text.windows
PurgeComm:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_PurgeComm(%rip),%rax
	jmp	__sysv2nt
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	PurgeComm,globl
	.previous
