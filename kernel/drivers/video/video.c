#include <stdint.h>
#include <io/ports/ports.h>

void vmode(unsigned int mode) {
    switch (mode) {
        case 0:
            initTextMode();
            break;
        default:
            initTextMode();
            break;
    }
}
