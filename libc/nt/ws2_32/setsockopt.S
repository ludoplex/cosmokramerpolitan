#include "libc/nt/codegen.h"
.imp	ws2_32,__imp_setsockopt,setsockopt,21

	.text.windows
__sys_setsockopt_nt:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_setsockopt(%rip),%rax
	jmp	__sysv2nt6
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	__sys_setsockopt_nt,globl
	.previous
