AS = as
ASFLAGS = --32

C = gcc
CFLAGS = -m32 -ffreestanding -O2 -fPIE

all: build run

clean:
	rm -rf build
	rm -rf image
	rm -f PhOS.iso

build: clean
	mkdir build
	$(AS) $(ASFLAGS) kernel/boot.s -o build/boot.o
	$(C) -Ikernel/lib -Ikernel/drivers -c kernel/kernel.c -std=c99 -o build/kernel.o $(CFLAGS)
	$(C) -T kernel/linker.ld -o build/phos.bin $(CFLAGS) -nostdlib -nostartfiles build/* -lgcc
	mkdir -p image/boot/grub
	cp grub.cfg image/boot/grub/grub.cfg
	cp build/phos.bin image/boot/PhOS.bin
	grub-mkrescue -o PhOS.iso image

run:
	qemu-system-i386 -cdrom PhOS.iso 
