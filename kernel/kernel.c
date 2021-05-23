#include <common.h>
#include <mem/gdt.h>
#include <int/isr.h>
#include <int/idt.h>
#include <ps2/ps2.h>
#include "panic.h"

char phkver[] = "0.4";
char phkrev[] = "A";

void main(struct stivale_struct* info) {
    setvmode(0);
    vga_noblink();
    vclear();
    init_gdt();
    isr_install();
    irq_install();
    init_ps2();
    kprintf("MEM MAP AT 0x%_x:\n", (uint32_t)info->memory_map_addr, 8);
    struct stivale_mmap_entry* memmap = (struct stivale_mmap_entry*)(intptr_t)(info->memory_map_addr);
    for (size_t i = 0; i < info->memory_map_entries; i++) {
        struct stivale_mmap_entry e = memmap[i];
        kprintf("MEM %_x: [0x%_x - 0x%_x] (0x%_x) ", i, 2, (uint32_t)e.base, 8, (uint32_t)(e.base + e.length) - 1, 8, (unsigned int)e.type, 4);
        switch (e.type) {
            case STIVALE_MMAP_USABLE:
                usable_mem += e.length;
                free_mem += e.length;
                kprintf("[FREE: %u bytes]\n", e.length);
                break;
            case STIVALE_MMAP_RESERVED:
                usable_mem += e.length;
                kputs("[RESERVED]");
                break;
            case STIVALE_MMAP_ACPI_RECLAIMABLE:
                usable_mem += e.length;
                kputs("[ACPI RECLAIMABLE]");
                break;
            case STIVALE_MMAP_ACPI_NVS:
                kputs("[ACPI NVS]");
                break;
            case STIVALE_MMAP_BAD_MEMORY:
                kputs("[BAD]");
                break;
            case STIVALE_MMAP_KERNEL_AND_MODULES:
                usable_mem += e.length;
                kputs("[KERNEL/MODULES]");
                break;
            case STIVALE_MMAP_BOOTLOADER_RECLAIMABLE:
                usable_mem += e.length;
                kputs("[BOOTLOADER RECLAIMABLE]");
                break;
            case STIVALE_MMAP_FRAMEBUFFER:
                usable_mem += e.length;
                kputs("[FRAMEBUFFER]");
                break;
            default:
                kputs("[UNKNOWN]");
                break;
        }
    }
    anykey();
    kprintf("%_fWelcome %_fto %_fPhosphorOS %_fversion %_f%s %_frevision %_f%s%_f!\n", 15, 1, 9, 2, 10, phkver, 4, 12, phkrev, 15);
    kprintf(
        "%_fUsable%_f memory:\t%_f%u %_fbytes (%_f%u %_fKiB)\n"
        "%_fFree%_f memory:%_f\t%u %_fbytes (%_f%u %_fKiB)\n"
        "%_fUsed%_f memory:%_f\t%u %_fbytes (%_f%u %_fKiB)\n",
        14, 7, 11, usable_mem, 8, 11, usable_mem >> 10, 8,
        10, 7, 11, free_mem, 8, 11, free_mem >> 10, 8,
        12, 7, 11, usable_mem - free_mem, 8, 11, (usable_mem - free_mem) >> 10, 8
    );
    for (bgc = 0; bgc < 16; bgc++) {
        __kputs("  ");
    }
    kputchar('\n');
    for (bgc = 7; bgc < -1; bgc--) {
        fgc = 15 - bgc;
        __kputs("\xB1\xB1");
    }
    for (fgc = 8; fgc < 16; fgc++) {
        bgc = fgc - 8;
        __kputs("\xB1\xB1");
    }
    vcolor(7, 0);
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
    idleKeyboard();
    hang();
}
