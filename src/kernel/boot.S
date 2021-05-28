.include "stivale-header.S"

.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 65536
stack_top:

.section .text
.global _start
.type _start, @function

.global loadPageDirectory
loadPageDirectory:
push %ebp
mov %esp, %ebp
mov 8(%esp), %eax
mov %eax, %cr3
mov %ebp, %esp
pop %ebp
ret

.global enablePaging
enablePaging:
push %ebp
mov %esp, %ebp
mov %cr0, %eax
or $0x80000000, %eax
mov %eax, %cr0
mov %ebp, %esp
pop %ebp
ret

_start:
	cli
	mov %cr0, %edx
	and %edx, -13
	mov %edx, %cr0
	fninit
	fnstsw .fputestword
	cmpw $0, .fputestword
	jne _nofpu
	push $1
c:	push 8(%esp)
	call main
	cli
h:	hlt
	jmp h

.size _start, . - _start

.fputestword: .word 0x1

_nofpu: 
push $0
jmp c
