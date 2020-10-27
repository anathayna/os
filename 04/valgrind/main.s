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
	lea	rdi, [rip + L___FUNCTION__.main]
	call	_trace
	call	_func
	xor	edi, edi
	call	_exit
	.cfi_endproc
                                        ## -- End function
	.globl	_trace                  ## -- Begin function trace
	.p2align	4, 0x90
_trace:                                 ## @trace
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rsi, qword ptr [rbp - 8]
	lea	rdi, [rip + L_.str.1]
	mov	al, 0
	call	_printf
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_func                   ## -- Begin function func
	.p2align	4, 0x90
_func:                                  ## @func
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	lea	rdi, [rip + L___FUNCTION__.func]
	call	_trace
	lea	rax, [rip + L_.str]
	mov	qword ptr [rbp - 8], rax
	mov	rdi, qword ptr [rbp - 8]
	call	_puts
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L___FUNCTION__.main:                    ## @__FUNCTION__.main
	.asciz	"main"

L___FUNCTION__.func:                    ## @__FUNCTION__.func
	.asciz	"func"

L_.str:                                 ## @.str
	.asciz	"ana thayna"

L_.str.1:                               ## @.str.1
	.asciz	"estou na fun\303\247\303\243o nomeada '%s'\n"

.subsections_via_symbols
