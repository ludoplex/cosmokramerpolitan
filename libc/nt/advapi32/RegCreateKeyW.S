#include "libc/nt/codegen.h"
.imp	advapi32,__imp_RegCreateKeyW,RegCreateKeyW,1616

	.text.windows
RegCreateKey:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_RegCreateKeyW(%rip),%rax
	jmp	__sysv2nt
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	RegCreateKey,globl
	.previous
