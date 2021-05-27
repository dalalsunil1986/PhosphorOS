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
	#mov %esp, stack_top
	#push %ebx
	#push %eax
	call main
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
