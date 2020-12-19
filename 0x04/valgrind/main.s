	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.intel_syntax noprefix
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	dword ptr [rbp - 4], 0
	call	_alfa
	mov	edi, 3
	call	_sleep
	xor	edi, edi
	mov	dword ptr [rbp - 8], eax ## 4-byte Spill
	call	_exit
	.cfi_endproc
                                        ## -- End function
	.globl	_alfa                   ## -- Begin function alfa
	.p2align	4, 0x90
_alfa:                                  ## @alfa
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 208
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	mov	dword ptr [rbp - 196], 0
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 196], 15
	jge	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	xor	eax, eax
	mov	esi, eax
	mov	eax, dword ptr [rbp - 196]
	movsxd	rcx, dword ptr [rbp - 196]
	mov	dword ptr [rbp + 4*rcx - 192], eax
	movsxd	rcx, dword ptr [rbp - 196]
	shl	rcx, 3
	lea	rdx, [rbp - 128]
	add	rdx, rcx
	movsxd	rcx, dword ptr [rbp - 196]
	shl	rcx, 2
	lea	rdi, [rbp - 192]
	add	rdi, rcx
	mov	qword ptr [rbp - 208], rdi ## 8-byte Spill
	mov	rdi, rdx
	lea	rdx, [rip + _imprimir_msg]
	mov	rcx, qword ptr [rbp - 208] ## 8-byte Reload
	call	_pthread_create
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	mov	eax, dword ptr [rbp - 196]
	add	eax, 1
	mov	dword ptr [rbp - 196], eax
	jmp	LBB1_1
LBB1_4:
	mov	dword ptr [rbp - 200], 0
LBB1_5:                                 ## =>This Inner Loop Header: Depth=1
	cmp	dword ptr [rbp - 200], 15
	jge	LBB1_8
## %bb.6:                               ##   in Loop: Header=BB1_5 Depth=1
	xor	eax, eax
	mov	esi, eax
	movsxd	rcx, dword ptr [rbp - 200]
	mov	rdi, qword ptr [rbp + 8*rcx - 128]
	call	_pthread_join
## %bb.7:                               ##   in Loop: Header=BB1_5 Depth=1
	mov	eax, dword ptr [rbp - 200]
	add	eax, 1
	mov	dword ptr [rbp - 200], eax
	jmp	LBB1_5
LBB1_8:
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	rcx, qword ptr [rbp - 8]
	cmp	rax, rcx
	jne	LBB1_10
## %bb.9:
	add	rsp, 208
	pop	rbp
	ret
LBB1_10:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_imprimir_msg           ## -- Begin function imprimir_msg
	.p2align	4, 0x90
_imprimir_msg:                          ## @imprimir_msg
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rax, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rax]
	mov	dword ptr [rbp - 12], ecx
	mov	esi, dword ptr [rbp - 12]
	lea	rdi, [rip + L_.str]
	lea	rdx, [rip + L___FUNCTION__.imprimir_msg]
	mov	al, 0
	call	_printf
	xor	ecx, ecx
	mov	edx, ecx
	mov	dword ptr [rbp - 16], eax ## 4-byte Spill
	mov	rax, rdx
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"estou na thread %d na fun\303\247\303\243o %s\n"

L___FUNCTION__.imprimir_msg:            ## @__FUNCTION__.imprimir_msg
	.asciz	"imprimir_msg"

.subsections_via_symbols
