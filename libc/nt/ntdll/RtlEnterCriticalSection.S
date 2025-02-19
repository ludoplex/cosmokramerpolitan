#include "libc/nt/ntdllimport.h"
.ntimp	RtlEnterCriticalSection,RtlEnterCriticalSection

	.text.windows
RtlEnterCriticalSection:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	%rdi,%rcx
	sub	$32,%rsp
	call	*__imp_RtlEnterCriticalSection(%rip)
	leave
#elif defined(__aarch64__)
	mov	x0,#0
#endif
	ret
	.endfn	RtlEnterCriticalSection,globl
	.previous
