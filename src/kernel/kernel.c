#define GFX_FANCY_TEXT

#include "init.c"
#include "panic.h"
#include <common.h>
#include <delay.h>
#include <stivale.h>
#include <font.h>

char phkver[] = "0.7";
char phkrev[] = "B";

void main(struct stivale_struct* boot_info) {
    stivale_info = boot_info;
    if ((uint32_t)(stivale_info->framebuffer_addr)) {
        setvmode(1);
    } else {
        setvmode(0);
        vga_noblink();
    }
    vclear();
    init();
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
        14, 7, 11, usable_mem, 8, 11, usable_mem >> 10, 8,
        10, 7, 11, free_mem, 8, 11, free_mem >> 10, 8,
        12, 7, 11, usable_mem - free_mem, 8, 11, (usable_mem - free_mem) >> 10, 8
    );
    sysmsg(1, "Press the arrow keys to move the cursor");
    sysmsg(1, "F1-F8 = fg color 0-7, Shift+F1-F8 = fg color 8-15, Ctrl = bg color");
    sysmsg(1, "Press Ctrl + F12 to cause a crash");
    delay(40);
    for (bgc = 0; bgc < 16; bgc++) {
        delay(10);
        _kputs("  ");
    }
    bgc = 0;
    fgc = 7;
    kputchar('\n');
    delay(20);
    for (bgc = 7; bgc < (uint8_t)-1; bgc--) {
        delay(10);
        fgc = 15 - bgc;
        _kputs("\xB1\xB1");
    }
    for (fgc = 8; fgc < 16; fgc++) {
        delay(10);
        bgc = fgc - 8;
        _kputs("\xB1\xB1");
    }
    bgc = 0;
    fgc = 7;
    kputchar('\n');
    delay(20);
    for (int i = 0; i < 16; i++) {
        delay(10);
        bgc = rand() % 16;
        _kputs("  ");
    }
    bgc = 0;
    fgc = 7;
    kputchar('\n');
    delay(20);
    for (int i = 0; i < 16; i++) {
        delay(10);
        fgc = rand() % 16;
        bgc = rand() % 16;
        _kputs("\xB1\xB1");
    }
    vcolor(7, 0);
    kputchar('\n');
    /*
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < 16; x++) {
            kwritechar(x + y * 16);
        }
        kputchar('\n');
    }
    */
    idleKeyboard();
    hang();
}
