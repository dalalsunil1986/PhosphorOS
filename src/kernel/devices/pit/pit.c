#include <io/ports/ports.h>
#include <common.h>

void timer_inc() {
    ticks++;
    outb(0x20, 0x20);
}

void gfxmode_int();

void init_pit(uint32_t freq) {
    ticks = 0;
    if (vmode) {
        register_interrupt_handler(IRQ0, gfxmode_int);
    } else {
        register_interrupt_handler(IRQ0, timer_inc);
    }
    uint32_t divisor = 1193181 / freq;
    outb(0x43, 0x36);
    outb(0x40, (uint8_t)(divisor & 0xFF));
    outb(0x40, (uint8_t)((divisor >> 8) & 0xFF));
}
