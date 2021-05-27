#include <pit/pit.h>

void delay(uint64_t ms) {
    ms += ticks;
    while (ticks < ms) {
        asm("nop");
        if (ticks >= ms) break;
        asm("hlt");
    }
}
