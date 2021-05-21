.set ALIGN,    1<<0
.set MEMINFO,  1<<1
.set FLAGS,    ALIGN | MEMINFO
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .multiboot_header
header_start:
    .quad 0xe85250d6                # magic number
    .quad 0                         # protected mode code
    .quad header_end - header_start # header length

    # checksum
    .quad 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    # required end tag
    .word 0    # type
    .word 0    # flags
    .quad 8    # size
header_end:

# Allocate the initial stack.
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
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
	mov %esp, stack_top
	push %ebx
	push %eax
	call main
	cli
1:	hlt
	jmp 1b

.size _start, . - _start
