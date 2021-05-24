.section .stivalehdr, "aw", @progbits
.align 8
header_start:
    .long stack_top
    .long 0
    .hword 0b0000000000000000
    .hword 0
    .hword 0
    .hword 0
    .long main
    .long 0

.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 32768
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
