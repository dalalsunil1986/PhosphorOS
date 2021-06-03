AS = as
ASFLAGS = --32 -Ikernel/

ASM = nasm
ASMFLAGS = -f elf32

C = gcc
CFLAGS = -m32 -funsigned-char -ffreestanding -O2 -Wall -Wextra

EMU = qemu-system-i386
#EMUFLAGS = -cdrom PhOS.iso -m 256M -soundhw pcspk -serial stdio
EMUFLAGS = -cdrom PhOS.iso -m 256M -serial stdio

all: build run

clean:
	rm -rf build
	rm -rf image
	rm -f PhOS.iso
	rm -f kernel/stivale-header.S

build: clean
	mkdir build
	$(ASM) $(ASMFLAGS) kernel/devices/mem/gdt.asm -o build/gdt.o
	$(ASM) $(ASMFLAGS) kernel/devices/int/interrupt.asm -o build/interrupt.o
	$(C) -Ikernel/devices -Ikernel/drivers -Ikernel/lib -Ikernel/ $(CFLAGS) -c kernel/kernel.c -std=c99 -o build/kernel.o
	mkdir -p image/boot
	mkdir -p image/phos
	
	cp kernel/stivale-header.0.S kernel/stivale-header.S
	$(AS) $(ASFLAGS) kernel/boot.S -o build/boot.o
	$(C) -Tkernel/linker.ld -o build/phos.bin $(CFLAGS) -nostdlib build/* -lgcc
	cp build/phos.bin image/phos/phos.bin
	rm -f kernel/stivale-header.S build/phos.bin
	
	cp kernel/stivale-header.1.S kernel/stivale-header.S
	$(AS) $(ASFLAGS) kernel/boot.S -o build/boot.o
	$(C) -Tkernel/linker.ld -o build/phos.bin $(CFLAGS) -nostdlib build/* -lgcc
	cp build/phos.bin image/phos/phos-tm.bin
	rm -f kernel/stivale-header.S build/phos.bin
	
	cp limine.cfg limine/limine.sys limine/limine-cd.bin image/boot
	xorriso -as mkisofs -b boot/limine-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table -part_like_isohybrid \
	--mbr-force-bootable -no-emul-boot image -isohybrid-gpt-basdat -o PhOS.iso
	./limine/limine-install PhOS.iso || true
run:
	$(EMU) $(EMUFLAGS)

debug:
	$(EMU) $(EMUFLAGS) -d int --no-reboot --no-shutdown
