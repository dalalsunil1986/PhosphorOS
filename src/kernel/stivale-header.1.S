.section .stivalehdr, "aw", @progbits
.align 8

header_start:
    .long stack_top
    .long 0
    .hword 0b0000000000000000
    .hword 0
    .hword 0
    .hword 0
    .long _start
    .long 0

.section .gfxtextbuf, "aw", @nobits
.align 4

.global gfxtextbuf_begin
.global gfxbaktextbuf_begin

gfxtextbuf_begin:
gfxtextbuf_end:

gfxbaktextbuf_begin:
.skip 2000
gfxbaktextbuf_end:
