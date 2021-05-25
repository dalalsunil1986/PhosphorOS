#include "init.c"
#include "panic.h"
#include <common.h>
#include <delay.h>
#include <stivale.h>

char phkver[] = "0.6";
char phkrev[] = "B";

void main(struct stivale_struct* boot_info) {
    stivale_info = boot_info;
    setvmode(0);
    vga_noblink();
    vclear();
    init();
    uint64_t boot_ticks = ticks;
    anykey(true, true, NULL);
    kprintf("Booted in %ums\n", boot_ticks);
    outb(0x70, 0x00);
    seed = inb(0x71) * ticks * boot_ticks;
    outb(0x70, 0x02);
    seed = seed / inb(0x71) + ticks * boot_ticks - ticks * boot_ticks;
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
    sysmsg(0, "Press the arrow keys to move the cursor");
    sysmsg(0, "F1-F8 = fg color 0-7, Shift+F1-F8 = fg color 8-15, Ctrl = bg color");
    sysmsg(0, "Press Ctrl + F12 to cause a crash");
    delay(40);
    for (bgc = 0; bgc < 16; bgc++) {
        delay(10);
        _kputs("  ");
    }
    kputchar('\n');
    delay(20);
    for (bgc = 7; bgc < -1; bgc--) {
        delay(10);
        fgc = 15 - bgc;
        _kputs("\xB1\xB1");
    }
    for (fgc = 8; fgc < 16; fgc++) {
        delay(10);
        bgc = fgc - 8;
        _kputs("\xB1\xB1");
    }
    kputchar('\n');
    delay(20);
    for (int i = 0; i < 16; i++) {
        delay(10);
        bgc = rand() % 16;
        _kputs("  ");
    }
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
