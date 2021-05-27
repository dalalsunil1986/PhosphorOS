#include <commondef.h>
#include <io/ports/ports.h>

void setvmode(unsigned int mode) {
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

static inline void vcolor(uint8_t f, uint8_t b) {
    fgc = f;
    bgc = b;
}

inline void vblank() {
    vblankcolor(bgc);
}

inline void vclear() {
    vclearcolor(bgc);
}

inline void vblankline(int l) {
    vblanklinecolor(l, bgc);
}

inline void vclearline(int l) {
    vclearlinecolor(l, bgc);
}

inline void vshowcursor() {
    vcursorstyle(curtop, curbtm);
}