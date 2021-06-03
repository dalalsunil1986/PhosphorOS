#include <commondef.h>
#include <io/ports/ports.h>

void setvmode(uint16_t mode) {
    vmode = mode;
    switch (mode) {
        case 0:
            initTextMode();
            break;
        case 1:
            initGfxMode();
            break;
        default:
            initTextMode();
            break;
    }
}

void vcolor(uint8_t f, uint8_t b) {
    fgc = f;
    bgc = b;
}

void vblank() {
    vblankcolor(bgc);
}

void vclear() {
    vclearcolor(bgc);
}

void vblankline(int l) {
    vblanklinecolor(l, bgc);
}

void vclearline(int l) {
    vclearlinecolor(l, bgc);
}

void vshowcursor() {
    vcursorstyle(curtop, curbtm);
}