#include <stdint.h>
#include <font.h>

#define GMC(f, b) ((((uint8_t)(f) & 0x0F) << 8) + (((uint8_t)(b) & 0x0F) << 12))

__attribute__((used))uint16_t* gfxmode_vbuf = 0;
__attribute__((used))uint16_t* gfxmode_bakbuf = 0;

__attribute__((used))static volatile uint32_t* gfxmode_ptr = 0;

int gfx_pitch = 0;

static bool gfx_fancy_text = true;
static int gfx_fancy_gradient = 0x05;

static uint32_t gfxmode_colors[16] = {
    0x000000,
    0x0000AA,
    0x00AA00,
    0x00AAAA,
    0xAA0000,
    0xAA00AA,
    0xAAAA00,
    0xAAAAAA,
    0x555555,
    0x5555FF,
    0x55FF55,
    0x55FFFF,
    0xFF5555,
    0xFF55FF,
    0xFFFF55,
    0xFFFFFF,
};

void gfxmode_drawcursor(int bx, int by, uint8_t c) {
    int base = (bx * charw + by * screenw * charh);
    for (int y = 0; y < charh; y++) {
        for (int x = 0; x < charw; x++) {
            if (y >= curtop && y <= curbtm) {
                gfxmode_ptr[base] = gfxmode_colors[c];
                base++;
            } else {
                base++;
            }
        }
        base += (gfx_pitch / 4) - charw;
    }
}    

char *convert(uint64_t num, int base);

uint32_t fsub;
uint32_t tmpcolor;
int div;

static void gfxmode_writechar(int bx, int by, char c, uint8_t fg, uint8_t bg) {
    int base = (bx * charw + by * screenw * charh);
    if (gfx_fancy_text) {
        div = charh / 2;
        fsub = 0;
        for (int y = 0; y < div; y++) {
            for (int x = 0; x < charw; x++) {
                if ((font[(unsigned)c][y] & (1 << x))) {
                    if (gfxmode_colors[fg]) {
                        tmpcolor = 0;
                        if ((gfxmode_colors[fg] & 0x0000FF) - fsub <= (gfxmode_colors[fg] & 0x0000FF)) tmpcolor += (gfxmode_colors[fg] & 0x0000FF) - fsub;
                        if (((gfxmode_colors[fg] & 0x00FF00) - (fsub << 8)) <= (gfxmode_colors[fg] & 0x00FF00)) tmpcolor += (gfxmode_colors[fg] & 0x00FF00) - (fsub << 8);
                        if (((gfxmode_colors[fg] & 0xFF0000) - (fsub << 16)) <= (gfxmode_colors[fg] & 0xFF0000)) tmpcolor += (gfxmode_colors[fg] & 0xFF0000) - (fsub << 16);
                        gfxmode_ptr[base] = tmpcolor;
                    } else {
                        gfxmode_ptr[base] = 0;
                    }
                } else {
                    gfxmode_ptr[base] = gfxmode_colors[bg];
                }
                base++;
            }
            fsub += gfx_fancy_gradient;
            base += (gfx_pitch / 4) - charw;
        }
        div = charh / 2;
        for (int y = div; y < charh; y++) {
            for (int x = 0; x < charw; x++) {
                if ((font[(unsigned)c][y] & (1 << x))) {
                    if (gfxmode_colors[fg]) {
                        tmpcolor = 0;
                        if ((gfxmode_colors[fg] & 0x0000FF) - fsub <= (gfxmode_colors[fg] & 0x0000FF)) tmpcolor += (gfxmode_colors[fg] & 0x0000FF) - fsub;
                        if (((gfxmode_colors[fg] & 0x00FF00) - (fsub << 8)) <= (gfxmode_colors[fg] & 0x00FF00)) tmpcolor += (gfxmode_colors[fg] & 0x00FF00) - (fsub << 8);
                        if (((gfxmode_colors[fg] & 0xFF0000) - (fsub << 16)) <= (gfxmode_colors[fg] & 0xFF0000)) tmpcolor += (gfxmode_colors[fg] & 0xFF0000) - (fsub << 16);
                        gfxmode_ptr[base] = tmpcolor;
                    } else {
                        gfxmode_ptr[base] = 0;
                    }
                } else {
                    gfxmode_ptr[base] = gfxmode_colors[bg];
                }
                base++;
            }
            fsub -= gfx_fancy_gradient;
            base += (gfx_pitch / 4) - charw;
        }
    } else {
        for (int y = 0; y < charh; y++) {
            for (int x = 0; x < charw; x++) {
                if ((font[(unsigned char)c][y] & (1 << x))) {
                    gfxmode_ptr[base] = gfxmode_colors[fg];
                } else {
                    gfxmode_ptr[base] = gfxmode_colors[bg];
                }
                base++;
            }
            base += (gfx_pitch / 4) - charw;
        }
    }
}

void gfxmode_drawchar(int x, int y, char c, uint8_t fg, uint8_t bg) {
    uint16_t tmp = c + GMC(fg, bg);
    if (gfxmode_vbuf[x + y * textw] == tmp) return;
    gfxmode_vbuf[x + y * textw] = tmp;
    gfxmode_writechar(x, y, c, fg, bg);
}

void gfxmode_setchar(int x, int y, char c) {
    gfxmode_drawchar(x, y, c, fgc, bgc);
}

char gfxmode_getchar(int x, int y) {
    return (char)gfxmode_vbuf[x + y * textw];
}

int ccurx = 0, ccury = 0;
bool gfx_cursor_old;
bool gfx_cursor = true;

void gfxmode_updatecursor() {

}

void gfxmode_setfgc(int x, int y, uint8_t c) {
    gfxmode_drawchar(x, y, gfxmode_getchar(x, y), c, (gfxmode_vbuf[x + y * textw] >> 12) & 0x0F);
}

void gfxmode_setbgc(int x, int y, uint8_t c) {
    gfxmode_drawchar(x, y, gfxmode_getchar(x, y), (gfxmode_vbuf[x + y * textw] >> 8) & 0x0F, c);
}

void gfxmode_vscroll(int l) {
    if (!l) return;
    if (l > 0) {
        int y = 0;
        int e = texth - l;
        while (y < e) {
            for (int x = 0; x < textw; x++) {
                gfxmode_drawchar(x, y, (char)gfxmode_vbuf[x + (y + l) * textw], (gfxmode_vbuf[x + (y + l) * textw] >> 8) & 0x0F, (gfxmode_vbuf[x + (y + l) * textw] >> 12) & 0x0F);
            }
            y++;
        }
        while (y < texth) {
            for (int x = 0; x < textw; x++) {
                gfxmode_setchar(x, y, 0);
            }
            y++;
        }
    } else {
        l *= -1;
        int y = texth - 1;
        int e = l - 1;
        while (y > e) {
            for (int x = 0; x < textw; x++) {
                gfxmode_drawchar(x, y, (char)gfxmode_vbuf[x + (y - l) * textw], (gfxmode_vbuf[x + (y - l) * textw] >> 8) & 0x0F, (gfxmode_vbuf[x + (y - l) * textw] >> 12) & 0x0F);
            }
            y--;
        }
        while (y > -1) {
            for (int x = 0; x < textw; x++) {
                gfxmode_setchar(x, y, 0);
            }
            y--;
        }
    }
}

void gfxmode_shiftline(int l) {
    for (int x = textw - 1; x > 0; x--) {
        gfxmode_drawchar(x, l, gfxmode_vbuf[(x - 1) + l * textw], (gfxmode_vbuf[(x - 1) + l * textw] >> 8) & 0x0F, (gfxmode_vbuf[(x - 1) + l * textw] >> 12) & 0x0F);
    }
    gfxmode_setchar(0, l, 0);
}

void gfxmode_unshiftline(int l) {
    for (int x = 0; x < textw - 1; x++) {
        gfxmode_drawchar(x, l, gfxmode_vbuf[x + 1 + l * textw], (gfxmode_vbuf[x + 1 + l * textw] >> 8) & 0x0F, (gfxmode_vbuf[x + 1 + l * textw] >> 12) & 0x0F);
    }
    gfxmode_setchar(textw - 1, l, 0);
}

void gfxmode_blankcolor(uint8_t color) {
    for (int y = 0; y < texth; y++) {
        for (int x = 0; x < textw; x++) {
            gfxmode_drawchar(x, y, 0, fgc, color);
        }
    }
}

void gfxmode_clearcolor(uint8_t color) {
    curx = 0; cury = 0;
    gfxmode_blankcolor(color);
    gfxmode_updatecursor();
}

void gfxmode_blanklinecolor(int l, uint8_t color) {
    for (int i = 0; i < textw; i++) {
        gfxmode_drawchar(i, l, 0, fgc, color);
    }
}

void gfxmode_clearlinecolor(int l, uint8_t color) {
    curx = 0;
    gfxmode_blanklinecolor(l, color);
    gfxmode_updatecursor();
}

uint8_t gfxmode_getfgc(int x, int y) {
    return (uint8_t)((gfxmode_vbuf[x + y * textw] >> 8) & 0x0F);
}

uint8_t gfxmode_getbgc(int x, int y) {
    return (uint8_t)((gfxmode_vbuf[x + y * textw] >> 12) & 0x0F);
}

void gfxmode_hidecursor() {
    gfx_cursor = false;
    gfxmode_writechar(ccurx, ccury, gfxmode_vbuf[ccurx + ccury * textw], gfxmode_getfgc(ccurx, ccury), gfxmode_getbgc(ccurx, ccury));
}

void timer_inc();
uint64_t ticks;

bool dcur = false;

void gfxmode_cursorstyle(uint8_t top, uint8_t bottom) {
    curtop = top;
    curbtm = bottom;
    gfx_cursor = true;
    if ((ticks & (1 << 8))) {
        gfxmode_drawcursor(ccurx, ccury, gfxmode_getfgc(ccurx, ccury));
    } else {
        gfxmode_writechar(ccurx, ccury, gfxmode_vbuf[ccurx + ccury * textw], gfxmode_getfgc(ccurx, ccury), gfxmode_getbgc(ccurx, ccury));
    }
}

void gfxmode_int() {
    timer_inc();
    if (gfx_cursor != gfx_cursor_old) {
        gfxmode_writechar(ccurx, ccury, gfxmode_vbuf[ccurx + ccury * textw], gfxmode_getfgc(ccurx, ccury), gfxmode_getbgc(ccurx, ccury));
        gfx_cursor_old = gfx_cursor;
    }
    if (!gfx_cursor) return;
    dcur = !(uint8_t)ticks;
    if (ccurx != curx || ccury != cury) {
        gfxmode_writechar(ccurx, ccury, gfxmode_vbuf[ccurx + ccury * textw], gfxmode_getfgc(ccurx, ccury), gfxmode_getbgc(ccurx, ccury));
        ccurx = curx;
        ccury = cury;
        dcur = true;
    }
    if ((ticks & (1 << 8))) {
        if (dcur) gfxmode_drawcursor(ccurx, ccury, gfxmode_getfgc(ccurx, ccury));
    } else {
        if (dcur) gfxmode_writechar(ccurx, ccury, gfxmode_vbuf[ccurx + ccury * textw], gfxmode_getfgc(ccurx, ccury), gfxmode_getbgc(ccurx, ccury));
    }
}

int gtcurx, gtcury;

void gfxmode_savebuf() {
    gfxmode_writechar(ccurx, ccury, gfxmode_vbuf[ccurx + ccury * textw], gfxmode_getfgc(ccurx, ccury), gfxmode_getbgc(ccurx, ccury));
    int max = textw * texth;
    for (int i = 0; i < max; i++) {
        gfxmode_bakbuf[i] = gfxmode_vbuf[i];
    }
    gtcurx = curx;
    gtcury = cury;
}

void gfxmode_restorebuf() {
    gfxmode_writechar(ccurx, ccury, gfxmode_vbuf[ccurx + ccury * textw], gfxmode_getfgc(ccurx, ccury), gfxmode_getbgc(ccurx, ccury));
    for (int y = 0; y < texth; y++) {
        for (int x = 0; x < textw; x++) {
            gfxmode_drawchar(x, y, gfxmode_bakbuf[x + y * textw], (uint8_t)((gfxmode_bakbuf[x + y * textw] >> 8) & 0x0F), (uint8_t)((gfxmode_bakbuf[x + y * textw] >> 12) & 0x0F));
        }
    }
    curx = gtcurx;
    cury = gtcury;
    gfxmode_updatecursor();
}

void initGfxMode() {
    gfxmode_ptr = (uint32_t*)(uintptr_t)(stivale_info->framebuffer_addr);
    curx = 0;
    cury = 0;
    charw = 8;
    charh = 16;
    screenw = (int)(stivale_info->framebuffer_width);
    screenh = (int)(stivale_info->framebuffer_height);
    gfx_pitch = (int)(stivale_info->framebuffer_pitch);
    gfx_fancy_gradient = 0x07;
    textw = screenw / charw;
    texth = screenh / charh;
    gfxmode_vbuf = (uint16_t*)malloc((textw * texth) * sizeof(uint16_t));
    gfxmode_bakbuf = (uint16_t*)malloc((textw * texth) * sizeof(uint16_t));
    tab = 4;
    fgc = 7;
    bgc = 0;
    vsetchar = gfxmode_setchar;
    vgetchar = gfxmode_getchar;
    vsetfgc = gfxmode_setfgc;
    vsetbgc = gfxmode_setbgc;
    vscroll = gfxmode_vscroll;
    updatecursor = gfxmode_updatecursor;
    vblankcolor = gfxmode_blankcolor;
    vclearcolor = gfxmode_clearcolor;
    vblanklinecolor = gfxmode_blanklinecolor;
    vclearlinecolor = gfxmode_clearlinecolor;
    vshiftline = gfxmode_shiftline;
    vunshiftline = gfxmode_unshiftline;
    vgetfgc = gfxmode_getfgc;
    vgetbgc = gfxmode_getbgc;
    vcursorstyle = gfxmode_cursorstyle;
    vhidecursor = gfxmode_hidecursor;
    vsavebuf = gfxmode_savebuf;
    vrestorebuf = gfxmode_restorebuf;
}
