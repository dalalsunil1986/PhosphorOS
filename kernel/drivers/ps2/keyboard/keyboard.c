#include <stdbool.h>

unsigned int kbin;
bool key = false;

bool c_lock = false, n_lock = false, s_lock = false;

bool keydown[0x80];

static void kpb() {
    key = true;
    kbin = inb(0x60);
    kprintf("Keyboard: 0x%_x\n", kbin, 2);
    register_interrupt_handler(IRQ1, kpb);
}

void init_keyboard() {
    register_interrupt_handler(IRQ1, kpb);
    key = false;
}