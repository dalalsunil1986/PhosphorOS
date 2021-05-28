#include <commondef.h>
#include <io/ports/ports.h>

void delay(uint64_t ms);

void init_beeper() {
    outb(0x61, inb(0x61) | 1);
}

void beep_tone(uint32_t freq) {
    uint32_t div;
    uint8_t tmp;
    div = 1193181 / freq;
    outb(0x43, 0xB6);
    outb(0x42, (uint8_t) (div) );
    outb(0x42, (uint8_t) (div >> 8));
    tmp = inb(0x61);
    if (tmp != (tmp | 3)) outb(0x61, tmp | 3);
}

void beep_notone() {
    outb(0x61, (uint8_t)(inb(0x61) & 0xFC));
}

static inline void beep(uint32_t freq, uint64_t ms) {
    beep_tone(freq);
    delay(ms);
    beep_notone();
}