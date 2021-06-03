#include <io/ports/ports.h>
#include <common.h>

bool rtc_ticks_sync = true;

uint64_t rtc_sync_val = 0;
int rtc_sync_sec = 0;
bool rtc_sync_setup = false;
bool rtc_sync_first = true;

void timer_inc() {
    ticks++;
    if (rtc_ticks_sync) {
        if (!rtc_sync_setup) {
            rtc_sync_val = ticks;
            rtc_sync_setup = true;
        }
        outb(0x70, 0x0A);
        if (!(inb(0x71) & 0x80)) {
            outb(0x70, 0x00);
            int new_rtc_sync_sec = inb(0x71);
            if (new_rtc_sync_sec != rtc_sync_sec) {
                rtc_sync_sec = new_rtc_sync_sec;
                if (!rtc_sync_first) rtc_sync_val += 1000;
                if (rtc_sync_first) rtc_sync_first = false;
                if (ticks < rtc_sync_val) ticks = rtc_sync_val;
            }
        }
    }
}

void gfxmode_int();

void init_pit(uint32_t freq) {
    ticks = 0;
    if (vmode == 1) {
        register_interrupt_handler(IRQ0, gfxmode_int);
    } else {
        register_interrupt_handler(IRQ0, timer_inc);
    }
    uint32_t divisor = 1193181 / freq;
    outb(0x43, 0x36);
    outb(0x40, (uint8_t)(divisor & 0xFF));
    outb(0x40, (uint8_t)((divisor >> 8) & 0xFF));
}
