#include "libc/nt/codegen.h"
.imp	ws2_32,__imp_WSAWaitForMultipleEvents,WSAWaitForMultipleEvents,124

	.text.windows
__WSAWaitForMultipleEvents:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_WSAWaitForMultipleEvents(%rip),%rax
	jmp	__sysv2nt6
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	__WSAWaitForMultipleEvents,globl
	.previous
