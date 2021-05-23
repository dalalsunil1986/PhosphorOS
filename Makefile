AS = as
ASFLAGS = --32

ASM = nasm
ASMFLAGS = -f elf32

C = gcc
CFLAGS = -m32 -funsigned-char -ffreestanding -O2

EMU = qemu-system-i386
EMUFLAGS = -cdrom PhOS.iso -m 256M

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
	$(C) -Ikernel/devices -Ikernel/drivers -Ikernel/lib -Ikernel/ $(CFLAGS) -c kernel/kernel.c -std=c99 -o build/kernel.o
	$(C) -T kernel/linker.ld -o build/phos.elf $(CFLAGS) -nostdlib build/* -lgcc
	mkdir -p image/limine
	cp build/phos.elf limine.cfg limine.cfg limine/limine.sys limine/limine-cd.bin limine/limine-eltorito-efi.bin image/
	xorriso -as mkisofs -b limine-cd.bin \
        -no-emul-boot -boot-load-size 4 -boot-info-table -part_like_isohybrid \
        --mbr-force-bootable \
        -eltorito-alt-boot -e limine-eltorito-efi.bin \
        -no-emul-boot image -isohybrid-gpt-basdat -o PhOS.iso
	./limine/limine-install PhOS.iso || true
run:
	$(EMU) $(EMUFLAGS)

debug:
	$(EMU) $(EMUFLAGS) -d int --no-reboot --no-shutdown
