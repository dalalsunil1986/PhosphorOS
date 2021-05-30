[GLOBAL gdt_flush]

; This takes the first parameter passed to it (in esp+4), loads the value it
; points to into the GDT, then loads the segment selectors for the data and
; code segments. Notice that each GDT entry is 8 bytes, and the kernel code
; descriptor is the second segment, so it's offset is 0x08.
gdt_flush:
	mov	eax,	[esp+4]  ; Get the pointer to the GDT, passed as parameter.
	lgdt	[eax]            ; Load the new GDT pointer

	mov	ax,     0x10	 ; 0x10 is the offset in the GDT to our data segment.
	mov	ds,	ax	 ; Load all data segment selectors
	mov	es,	ax
	mov 	fs,	ax
	mov	gs,	ax
	mov 	ss,	ax
	jmp	0x08:.flush	 ; 0x08 is the offset to our code segment: Far jump!

.flush:
	ret
