#include <common.h>

void kpanic(int err, struct regs* r, char* str) {
    __asm__ volatile("cli");
    setvmode(0);
    vclearcolor(1);
    vcolor(1, 7); movecursor(34, 8); _kputs(" PhosphorOS "); vcolor(7, 1);
    if (err > 0) {
        movecursor(7, 11);
        _kputs("An unhandled exception has occurred and the system has been halted");
        movecursor(7, 13);
        kprintf("Exception code: %d", err);
        movecursor(7, 14);
        kprintf("Exception description: %s", exmsgs[err]);
    } else {
        movecursor(7, 12);
        _kputs(str);
    }
    while (1) {
        __asm__ volatile("hlt");
    }
}
