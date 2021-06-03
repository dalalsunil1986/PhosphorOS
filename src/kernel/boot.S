.include "stivale-header.S"

.section .text
.global _start
.type _start, @function

.global stack_top
stack_bottom:
.skip 65536
stack_top:

.global mem_ent_begin
mem_ent_begin:
.skip 131072
mem_ent_end:

_start:
	cli
	mov %cr0, %edx
	and %edx, -13
	mov %edx, %cr0
	fninit
	fnstsw .fputestword
	cmpw $0, .fputestword
	jne n
	push $1
c:	push 8(%esp)
	call main
	cli
h:	hlt
	jmp h
n:	push $0
	jmp c
.size _start, . - _start

.fputestword: .word 0xFFFFFFFF
