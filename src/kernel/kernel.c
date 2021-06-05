#define COM1 0x3f8

#include <commondef.h>

#ifdef _LIBALLOC_H
void *malloc(size_t);
void *realloc(void *, size_t);
void *calloc(size_t, size_t);
void free(void *);
#else
void* malloc(uint32_t);
void* realloc(void*, uint32_t);
void* calloc(uint32_t, uint32_t);
void free(void*);
#endif

#include "init.c"
#include "panic.h"
#include <common.h>
#include <delay.h>
#include <stivale.h>
#include <font.h>

char phkver[] = "0.9";
char phkrev[] = "C";

void main(struct stivale_struct* boot_info, int hasfpu) {
    boot_cycles = rdtsc();
    stivale_info = boot_info;
    fpupresent = (bool)hasfpu;
    init_mem();
    if ((uint32_t)(stivale_info->framebuffer_addr)) {
        setvmode(1);
    } else {
        setvmode(0);
        vga_noblink();
    }
    _kputchar = _std_kputchar;
    vclear();
    init();
    boot_cycles = rdtsc() - boot_cycles;
    anykey(true, true, NULL);
    txtdiv();
    outb(0x70, 0x00);
    seed = (unsigned int)((ticks + 1) * rdtsc() * inb(0x71) * (ticks + 1) * (boot_ticks + 1) - rdtsc());
    outb(0x70, 0x02);
    seed -= rdtsc() * (inb(0x71) + 1) * (ticks + 1);
    kprintf("Booted in %u milliseconds, %lu cycles.\n", (uint32_t)boot_ticks, (uint64_t)boot_cycles);
    kprintf("Random number generator seeded with %u.\n", (unsigned int)seed);
    txtdiv();
    kprintf("%_fWelcome %_fto %_fPhosphorOS %_fversion %_f%s %_frevision %_f%s%_f!\n", 15, 1, 9, 2, 10, phkver, 4, 12, phkrev, 15);
    beep(900, 150);
    delay(100);
    beep(900, 150);
    //char* buf1 = (char *)malloc(4262144 * sizeof(char));
    //char* buf2 = (char *)malloc(256 * sizeof(char));
    //buf1 = realloc(buf1, 32768);
    kprintf(
        "%_fUsable%_f memory:\t%_f%u %_fbytes (%_f%u %_fKiB)\n"
        "%_fFree%_f memory:%_f\t%u %_fbytes (%_f%u %_fKiB)\n"
        "%_fAllocated%_f memory:%_f\t%u %_fbytes (%_f%u %_fKiB)\n"
        "%_fUsed%_f memory:%_f\t%u %_fbytes (%_f%u %_fKiB)\n",
        14, 7, 11, usable_mem, 7, 11, usable_mem >> 10, 7,
        10, 7, 11, free_mem, 7, 11, free_mem >> 10, 7,
        9, 7, 11, alloc_mem, 7, 11, alloc_mem >> 10, 7,
        12, 7, 11, usable_mem - free_mem + alloc_mem, 7, 11, (usable_mem - free_mem + alloc_mem) >> 10, 7
    );
    vcolor(7, 0);
    /*
    txtdiv();
    buf1[0] = '!';
    buf2[0] = '@';
    kprintf("%s, %d, %u, %d, 0x%_x, {%c}\n", "Test", -32, -1, 255, &buf1[0], 8, buf1[0]);
    kprintf("%s, %d, %u, %d, 0x%_x, {%c}\n", "Test", -32, -1, 255, &buf2[0], 8, buf2[0]);
    free(buf1);
    free(buf2);
    */
    txtdiv();
    sysmsg(1, "Press the arrow keys to move the cursor");
    sysmsg(1, "F1-F8 = fg color 0-7, SHIFT+F1-F8 = fg color 8-15, CTRL = bg color");
    sysmsg(1, "Press CTRL+ESC to cause a crash");
    txtdiv();
    idleKeyboard();
    hang();
}
