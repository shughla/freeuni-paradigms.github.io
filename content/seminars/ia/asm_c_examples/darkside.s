	.file	"darkside.cpp"
	.text
	.align 2
	.globl	_ZN10jedimaster4lukeEPS_S_
	.type	_ZN10jedimaster4lukeEPS_S_, @function
_ZN10jedimaster4lukeEPS_S_:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -32(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movzwl	80(%rax), %eax
	movswq	%ax, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rdx
	leaq	-32(%rbp), %rcx
	leaq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZN10jedimaster6anakinEPsRS_@PLT
	movl	(%rax), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_ZN10jedimaster4lukeEPS_S_, .-_ZN10jedimaster4lukeEPS_S_
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
