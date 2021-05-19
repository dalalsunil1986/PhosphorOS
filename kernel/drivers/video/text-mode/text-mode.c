#define TMW 80
#define TMH 25

#include <stdint.h>

uint16_t* textmode_vbuf = (uint16_t *)0xB8000;

static inline void textmode_setchar(int x, int y, char c) {
    textmode_vbuf[x + y * TMW] = c + (fgc << 8) + (bgc << 16);
}

void textmode_vscroll(int l) {
    int y = 0;
    int e = TMH - l;
    while (y < e) {
        for (int x = 0; x < TMW; x++) {
            textmode_vbuf[x + y * TMW] = textmode_vbuf[x + (y + l) * TMW];
        }
        y++;
    }
    while (y < TMH) {
        for (int x = 0; x < TMW; x++) {
            textmode_vbuf[x + y * TMW] = (fgc << 8) + (bgc << 16);
        }
        y++;
    }
}

void initTextMode() {
    curx = 0;
    cury = 0;
    charw = 1;
    charh = 1;
    screenw = TMW;
    screenh = TMH;
    tab = 4;
    fgc = 7;
    bgc = 0;
    ksetchar = textmode_setchar;
    vscroll = textmode_vscroll;
}
