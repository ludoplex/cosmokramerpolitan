#include "libc/nt/codegen.h"
.imp	comdlg32,__imp_ReplaceTextW,ReplaceTextW,125

	.text.windows
ReplaceText:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	%rdi,%rcx
	sub	$32,%rsp
	call	*__imp_ReplaceTextW(%rip)
	leave
#elif defined(__aarch64__)
	mov	x0,#0
#endif
	ret
	.endfn	ReplaceText,globl
	.previous
