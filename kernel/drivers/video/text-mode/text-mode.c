#define TMW 80
#define TMH 25

#define TMC(f, b) ((((uint8_t)(f) & 0x0F) << 8) + (((uint8_t)(b) & 0x0F) << 12))

#include <stdint.h>
#include <io/ports/ports.h>

uint16_t* textmode_vbuf = (uint16_t *)0x000B8000;

static inline void textmode_setchar(int x, int y, char c) {
    textmode_vbuf[x + y * TMW] = c + TMC(fgc, bgc);
}

static inline char textmode_getchar(int x, int y) {
    return (char)textmode_vbuf[x + y * TMW];
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
            textmode_vbuf[x + y * TMW] = TMC(fgc, bgc);
        }
        y++;
    }
}

void textmode_updatecursor() {
    int pos = curx + screenw * cury;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void textmode_blankcolor(uint32_t color) {
    for (int i = 0; i < TMW * TMH; i++) {
        textmode_vbuf[i] = TMC(fgc, color);
    }
}

static inline void textmode_clearcolor(uint32_t color) {
    curx = 0; cury = 0;
    textmode_blankcolor(color);
}

void textmode_blanklinecolor(int l, uint32_t color) {
    l *= TMW;
    for (int i = 0; i < TMW; i++) {
        textmode_vbuf[i + l] = TMC(fgc, color);
    }
}

static inline void textmode_clearlinecolor(int l, uint32_t color) {
    curx = 0;
    textmode_blanklinecolor(l, color);
}


void initTextMode() {
    curx = 0;
    cury = 0;
    charw = 1;
    charh = 1;
    screenw = TMW;
    screenh = TMH;
    textw = TMW;
    texth = TMH;
    tab = 4;
    fgc = 7;
    bgc = 0;
    ksetchar = textmode_setchar;
    kgetchar = textmode_getchar;
    vscroll = textmode_vscroll;
    updatecursor = textmode_updatecursor;
    vblankcolor = textmode_blankcolor;
    vclearcolor = textmode_clearcolor;
    vblanklinecolor = textmode_blanklinecolor;
    vclearlinecolor = textmode_clearlinecolor;
}
