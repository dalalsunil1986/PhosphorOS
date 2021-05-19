#include <video/video.h>

static inline void _kputchar(char c) {
    switch (c) {
        case 0:
            break;
        case '\n':
            curx = 0;
            if (cury >= screenh - charh) {
                vscroll(1);
            } else {
                cury += charh;
            }
            break;
        case '\r':
            curx = 0;
            break;
        case '\t':
            for (int i = 0; i < tab; i++) {
                _kputchar(' ');
            }
            break;
        default:
            ksetchar(curx, cury, c);
            curx += charw;
            if (curx > screenw - charw) {
                curx = 0;
                if (cury >= screenh - charh) {
                    vscroll(1);
                } else {
                    cury += charh;
                }
            }
            break;
    }
}

void kputchar(char c) {
    _kputchar(c);
    int pos = curx + screenw * cury;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void _kputs(char* s) {
    char* t = s;
    while (*s) {
        _kputchar(*s);
        *s++;
    }
    int pos = curx + screenw * cury;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void kputs(char* s) {
    char* t = s;
    while (*s) {
        _kputchar(*s);
        *s++;
    }
    kputchar('\n');
}
