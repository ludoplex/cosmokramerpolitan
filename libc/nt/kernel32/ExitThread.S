#include "libc/nt/codegen.h"
.imp	kernel32,__imp_ExitThread,ExitThread,0

	.text.windows
ExitThread:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	%rdi,%rcx
	sub	$32,%rsp
	call	*__imp_ExitThread(%rip)
	leave
#elif defined(__aarch64__)
	mov	x0,#0
#endif
	ret
	.endfn	ExitThread,globl
	.previous
