#include <stdbool.h>
#include <common.h>

unsigned int kbin, kbcode;
bool key = false;

char c;

bool c_lock = false, n_lock = false, s_lock = false;
bool lsft_d = false, lctl_d = false, lalt_d = false;
bool rsft_d = false, rctl_d = false, ralt_d = false;

bool xE0 = false;

static void kpb() {
    key = true;
    kbcode = kbin = inb(0x60);
    if (kbin == 0xE0) {
        xE0 = true;
        return;
    }
    c = 0;
    //kprintf("Keyboard: 0x%_x [%d] ", kbin, 2, xE0);
    if (kbin < 128) {
        if (xE0) {
            switch (kbin) {
                case 0x1D:
                    rctl_d = true;
                    break;
                case 0x38:
                    ralt_d = true;
                    break;
                default:
                    c = keymap_special[(kbin - 1)];
                    keydown[kbin + 127] = true;
                    break;
            }
            xE0 = false;
        } else {
            switch (kbin) {
                case 0x1D:
                    lctl_d = true;
                    break;
                case 0x2A:
                    lsft_d = true;
                    break;
                case 0x36:
                    rsft_d = true;
                    break;
                case 0x38:
                    lalt_d = true;
                    break;
                case 0x3A:
                    c_lock = !c_lock;
                    break;
                case 0x45:
                    n_lock = !n_lock;
                    break;
                case 0x46:
                    s_lock = !s_lock;
                    break;
                default:
                    if (lsft_d || rsft_d) {
                        c = keymap_upper[(kbin - 1)];
                    } else {
                        c = keymap_lower[(kbin - 1)];
                    }
                    keydown[kbin - 1] = true;
                    break;
            }
        }
    } else {
        kbin -= 128;
        if (xE0) {
            switch (kbin) {
                case 0x1D:
                    rctl_d = false;
                    break;
                case 0x38:
                    ralt_d = false;
                    break;
                default:
                    keydown[kbin + 127] = false;
                    break;
            }
            xE0 = false;
        } else {
            switch (kbin) {
                case 0x1D:
                    lctl_d = false;
                    break;
                case 0x2A:
                    lsft_d = false;
                    break;
                case 0x36:
                    rsft_d = false;
                    break;
                case 0x38:
                    lalt_d = false;
                    break;
                case 0x3A:
                    break;
                case 0x45:
                    break;
                case 0x46:
                    break;
                default:
                    keydown[kbin - 1] = false;
                    break;
            }
        }
    }
    kputchar(c);
    //kputchar('\n');
}

void init_keyboard() {
    for (int i = 0; i < 384; i++) {keydown[i] = false;}
    register_interrupt_handler(IRQ1, kpb);
    key = false;
}