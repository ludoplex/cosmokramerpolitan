#include "libc/nt/codegen.h"
.imp	advapi32,__imp_RegConnectRegistryW,RegConnectRegistryW,1608

	.text.windows
RegConnectRegistry:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_RegConnectRegistryW(%rip),%rax
	jmp	__sysv2nt
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	RegConnectRegistry,globl
	.previous
