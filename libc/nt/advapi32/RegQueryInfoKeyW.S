#include "libc/nt/codegen.h"
.imp	advapi32,__imp_RegQueryInfoKeyW,RegQueryInfoKeyW,0

	.text.windows
RegQueryInfoKey:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_RegQueryInfoKeyW(%rip),%rax
	jmp	__sysv2nt12
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	RegQueryInfoKey,globl
	.previous
