#include "libc/nt/codegen.h"
.imp	user32,__imp_ShowCaret,ShowCaret,2411

	.text.windows
ShowCaret:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	%rdi,%rcx
	sub	$32,%rsp
	call	*__imp_ShowCaret(%rip)
	leave
#elif defined(__aarch64__)
	mov	x0,#0
#endif
	ret
	.endfn	ShowCaret,globl
	.previous
