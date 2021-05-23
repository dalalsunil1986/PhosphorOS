#include <stdint.h>
#include <io/ports/ports.h>

void setvmode(unsigned int mode) {
    vmode = mode;
    switch (mode) {
        case 0:
            initTextMode();
            break;
        default:
            initTextMode();
            break;
    }
}

static inline void vcolor(uint32_t f, uint32_t b) {
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
