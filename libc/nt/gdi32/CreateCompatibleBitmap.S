#include "libc/nt/codegen.h"
.imp	gdi32,__imp_CreateCompatibleBitmap,CreateCompatibleBitmap,1063

	.text.windows
CreateCompatibleBitmap:
#ifdef __x86_64__
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_CreateCompatibleBitmap(%rip),%rax
	jmp	__sysv2nt
#elif defined(__aarch64__)
	mov	x0,#0
	ret
#endif
	.endfn	CreateCompatibleBitmap,globl
	.previous
