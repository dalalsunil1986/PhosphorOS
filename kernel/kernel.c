#include <common.h>
#include <mem/gdt.h>
#include <mem/alloc.h>
#include <mem/paging.h>
#include <int/isr.h>
#include <int/idt.h>
#include <ps2/ps2.h>

void hang();

char phkver[] = "0.2";
char phkrev[] = "A";

void main(uint32_t mbm, void* mbh) {
    if (mbm != MULTIBOOT_BOOTLOADER_MAGIC) {
        kputs("Error: PhosphorOS requires a multiboot compliant bootloader.");
        hang();
    }
    mbi = (multiboot_info_t *)(mbh);
    if ((mbi->flags & (1<<6)) == 0) {
        kputs("Error: No multiboot memory map was provided.");
        hang();
    }
    mbi_start = (uint32_t)mbi;
    mbi_end = (uint32_t)(mbi + sizeof(multiboot_info_t));
    mbi_nff = 1;
    setvmode(0);
    gdt_install();
    paging_install();
    isr_install();
    irq_install();
    checkmem();
    kprintf("%_fWelcome %_fto %_fPhosphorOS %_fversion %_f%s %_frevision %_f%s%_f!\n", 15, 1, 9, 2, 10, phkver, 4, 12, phkrev, 15);
    kprintf("%_fUsable%_f memory:\t%_f%u %_fbytes\n%_fFree%_f memory:%_f\t%u %_fbytes\n", 14, 7, 12, usable_mem, 8, 10, 7, 12, free_mem, 8);
    for (bgc = 0; bgc < 8; bgc++) {
        __kputs("  ");
    }
    kputchar('\n');
    for (bgc = 8; bgc < 16; bgc++) {
        __kputs("  ");
    }
    bgc = 0;
    kputchar('\n');
    //__asm__ volatile ("int $1");
    //char* buf1 = (char *)malloc(32768 * sizeof(char));
    //free(buf1);
    //char* buf2 = (char *)malloc(256 * sizeof(char));
    //buf1[0] = '!';
    //buf2[0] = '!';
    //kprintf("%s, %d, %u, %d, 0x%_x, {%c}\n", "Test", -32, -1, 255, &buf1[0], 8, buf1[0]);
    //kprintf("%s, %d, %u, %d, 0x%_x, {%c}\n", "Test", -32, -1, 255, &buf2[0], 8, buf2[0]);
    //free(buf2);
    init_ps2();
    while (1) {}
}

void hang() {
    if (curx) _kputchar('\n');
    _kputs("System Halted.");
    while (1) {__asm__ volatile ("hlt");}
}
