AS = as
ASFLAGS = --32

ASM = nasm
ASMFLAGS = -f elf32

C = gcc
CFLAGS = -m32 -funsigned-char -ffreestanding -O2

all: build run

clean:
	rm -rf build
	rm -rf image
	rm -f PhOS.iso

build: clean
	mkdir build
	$(AS) $(ASFLAGS) kernel/boot.s -o build/boot.o
	$(ASM) $(ASMFLAGS) kernel/devices/mem/gdt.asm -o build/gdt.o
	$(ASM) $(ASMFLAGS) kernel/devices/int/interrupt.asm -o build/interrupt.o
	$(C) -Ikernel/devices -Ikernel/drivers -Ikernel/lib $(CFLAGS) -c kernel/kernel.c -std=c99 -o build/kernel.o
	$(C) -T kernel/linker.ld -o build/phos.bin $(CFLAGS) -nostdlib build/* -lgcc
	mkdir -p image/boot/grub
	cp grub.cfg image/boot/grub/grub.cfg
	cp build/phos.bin image/boot/PhOS.bin
	grub-mkrescue -o PhOS.iso image

run:
	qemu-system-i386 -cdrom PhOS.iso -m 256
