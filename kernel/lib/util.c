#define xor(bool1, bool2) ((bool1 || bool2) && (bool1 != bool2))
#include <kstd.h>
#include <ps2/keyboard/keyboard.h>

void idleKeyboard() {
    while (1) {
        char ch = kbgetchar();
        switch (ch) {
            case '\b':
                do {
                    kputchar('\b');
                } while (curx && !kgetchar(curx - 1, cury));
                break;
            default:
                kputchar(ch);
                break;
        }
        __asm__ volatile("hlt");
    }
}

static inline void anykey() {
    _kputs("Press any key to continue...");
    char ch = 0;
    do {
        __asm__ volatile("hlt");
        ch = kbgetchar();
    } while (ch);
    do {
        __asm__ volatile("hlt");
        ch = kbgetchar();
    } while (!ch);
    vclearline(cury);
}

void hang() {
    if (curx) _kputchar('\n');
    __asm__ volatile ("cli");
    _kputs("System Halted.");
    while (1) {__asm__ volatile ("hlt");}
}

void vga_noblink() {
    asm("cli");
    asm("movw $0x03DA, %dx");
    asm("inb %dx, %al");
    asm("movw $0x03C0, %dx");
    asm("movb $0x30, %al");
    asm("outb %al, %dx");
    asm("incb %dl");
    asm("inb %dx, %al");
    asm("andb $0xF7, %al");
    asm("decb %dl");
    asm("outb %al, %dx");
}