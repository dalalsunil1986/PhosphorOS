#define TMW 80
#define TMH 25

#define TMC(f, b) ((((uint8_t)(f) & 0x0F) << 8) + (((uint8_t)(b) & 0x0F) << 12))

#include <stdint.h>
#include <io/ports/ports.h>

uint16_t* gfxbaktextbuf_begin = 0;

uint16_t* textmode_vbuf = (uint16_t *)0x000B8000;

void textmode_setchar(int x, int y, char c) {
    textmode_vbuf[x + y * TMW] = c + TMC(fgc, bgc);
}

char textmode_getchar(int x, int y) {
    return (char)textmode_vbuf[x + y * TMW];
}

void textmode_vscroll(int l) {
    if (!l) return;
    if (l > 0) {
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
    } else {
        l *= -1;
        int y = TMH - 1;
        int e = l - 1;
        while (y > e) {
            for (int x = 0; x < TMW; x++) {
                textmode_vbuf[x + y * TMW] = textmode_vbuf[x + (y - l) * TMW];
            }
            y--;
        }
        while (y > -1) {
            for (int x = 0; x < TMW; x++) {
                textmode_vbuf[x + y * TMW] = TMC(fgc, bgc);
            }
            y--;
        }
    }
}

void textmode_updatecursor() {
    int pos = curx + screenw * cury;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void textmode_blankcolor(uint8_t color) {
    for (int i = 0; i < TMW * TMH; i++) {
        textmode_vbuf[i] = TMC(fgc, color);
    }
}

void textmode_clearcolor(uint8_t color) {
    curx = 0; cury = 0;
    textmode_blankcolor(color);
    textmode_updatecursor();
}

void textmode_blanklinecolor(int l, uint8_t color) {
    l *= TMW;
    for (int i = 0; i < TMW; i++) {
        textmode_vbuf[i + l] = TMC(fgc, color);
    }
}

void textmode_clearlinecolor(int l, uint8_t color) {
    curx = 0;
    textmode_blanklinecolor(l, color);
    textmode_updatecursor();
}

void textmode_shiftline(int l) {
    for (int x = TMW - 1; x > 0; x--) {
        textmode_vbuf[x + l * TMW] = textmode_vbuf[(x - 1) + l * TMW];
    }
    textmode_vbuf[l * TMW] = TMC(fgc, bgc);
}

void textmode_unshiftline(int l) {
    for (int x = 0; x < TMW - 1; x++) {
        textmode_vbuf[x + l * TMW] = textmode_vbuf[x + 1 + l * TMW];
    }
    textmode_vbuf[(l + 1) * TMW - 1] = TMC(fgc, bgc);
}

uint8_t textmode_getfgc(int x, int y) {
    return (uint8_t)((textmode_vbuf[x + y * TMW] >> 8) & 0x0F);
}

uint8_t textmode_getbgc(int x, int y) {
    return (uint8_t)((textmode_vbuf[x + y * TMW] >> 12) & 0x0F);
}

void textmode_cursorstyle(uint8_t top, uint8_t bottom) {
    curtop = top;
    curbtm = bottom;
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) & 0xC0) | top);
    outb(0x3D4, 0x0B);
    outb(0x3D5, (inb(0x3D5) & 0xE0) | bottom);
}

void textmode_hidecursor() {
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}

void textmode_setfgc(int x, int y, uint8_t c) {
    textmode_vbuf[x + y * TMW] = textmode_getchar(x, y) + TMC(c, textmode_getbgc(x, y));
}

void textmode_setbgc(int x, int y, uint8_t c) {
    textmode_vbuf[x + y * TMW] = textmode_getchar(x, y) + TMC(textmode_getfgc(x, y), c);
}

int tcurx, tcury;

void textmode_savebuf() {
    int max = TMW * TMH;
    for (int i = 0; i < max; i++) {
        gfxbaktextbuf_begin[i] = textmode_vbuf[i];
    }
    tcurx = curx;
    tcury = cury;
}

void textmode_restorebuf() {
    int max = TMW * TMH;
    for (int i = 0; i < max; i++) {
        textmode_vbuf[i] = gfxbaktextbuf_begin[i];
    }
    curx = tcurx;
    cury = tcury;
    updatecursor();
}

void initTextMode() {
    gfxbaktextbuf_begin = (uint16_t*)malloc((TMW * TMH) * sizeof(uint16_t));
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
    vsetchar = textmode_setchar;
    vgetchar = textmode_getchar;
    vsetfgc = textmode_setfgc;
    vsetbgc = textmode_setbgc;
    vscroll = textmode_vscroll;
    updatecursor = textmode_updatecursor;
    vblankcolor = textmode_blankcolor;
    vclearcolor = textmode_clearcolor;
    vblanklinecolor = textmode_blanklinecolor;
    vclearlinecolor = textmode_clearlinecolor;
    vshiftline = textmode_shiftline;
    vunshiftline = textmode_unshiftline;
    vgetfgc = textmode_getfgc;
    vgetbgc = textmode_getbgc;
    vcursorstyle = textmode_cursorstyle;
    vhidecursor = textmode_hidecursor;
    vsavebuf = textmode_savebuf;
    vrestorebuf = textmode_restorebuf;
}
