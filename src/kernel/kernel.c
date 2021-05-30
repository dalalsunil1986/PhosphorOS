#define GFX_FANCY_TEXT

#include "init.c"
#include "panic.h"
#include <common.h>
#include <delay.h>
#include <stivale.h>
#include <font.h>

char phkver[] = "0.8";
char phkrev[] = "B";

void main(struct stivale_struct* boot_info, int hasfpu) {
    stivale_info = boot_info;
    fpupresent = (bool)hasfpu;
    if ((uint32_t)(stivale_info->framebuffer_addr)) {
        setvmode(1);
    } else {
        setvmode(0);
        vga_noblink();
    }
    vclear();
    init();
    txtdiv();
    kprintf("Booted in %ums\n", boot_ticks);
    outb(0x70, 0x00);
    seed = inb(0x71) * (ticks + 1) * (boot_ticks + 1);
    outb(0x70, 0x02);
    seed = seed / ((inb(0x71) + (ticks + 1) * (boot_ticks + 1) - (ticks + 1) * (boot_ticks + 1)) + 5);
    kprintf("Random number generator seeded with %u\n", seed);
    kprintf("%_fWelcome %_fto %_fPhosphorOS %_fversion %_f%s %_frevision %_f%s%_f!\n", 15, 1, 9, 2, 10, phkver, 4, 12, phkrev, 15);
    beep(900, 150);
    delay(100);
    beep(900, 150);
    kprintf(
        "%_fUsable%_f memory:\t%_f%u %_fbytes (%_f%u %_fKiB)\n"
        "%_fFree%_f memory:%_f\t%u %_fbytes (%_f%u %_fKiB)\n"
        "%_fUsed%_f memory:%_f\t%u %_fbytes (%_f%u %_fKiB)\n",
        14, 7, 11, usable_mem, 7, 11, usable_mem >> 10, 7,
        10, 7, 11, free_mem, 7, 11, free_mem >> 10, 7,
        12, 7, 11, usable_mem - free_mem, 7, 11, (usable_mem - free_mem) >> 10, 7
    );
    vcolor(7, 0);
    txtdiv();
    sysmsg(1, "Press the arrow keys to move the cursor");
    sysmsg(1, "F1-F8 = fg color 0-7, SHIFT+F1-F8 = fg color 8-15, CTRL = bg color");
    sysmsg(1, "Press CTRL+ESC to cause a crash");
    idleKeyboard();
    hang();
}
