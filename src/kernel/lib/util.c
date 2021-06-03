#include <commondef.h>
#include <kstd.h>
#include <video/video.h>

void hang() {
    if (curx) _kputchar('\n');
    asm("cli");
    _kputs("System Halted.");
    while (1) {asm("hlt");}
}

#define halt hang

void reboot() {
    asm("cli");
    uint8_t good = 0x02;
    while (good & 0x02) {
        good = inb(0x64);
    }
    outb(0x64, 0xFE);
    tfault();
    if (curx) kputchar('\n');
    kputs("Please manually reboot your computer.");
    hang();
}

#include <ps2/keyboard/keyboard.h>

void fancyClear(int n) {
    int max = 0;
    vhidecursor();
    bool tmp_gfx_fancy_text = gfx_fancy_gradient;
    gfx_fancy_text = false;
    switch (n) {
        case 1:
            for (int i = 0; i < textw; i++) {
                for (int y = 0; y < texth; y++) {
                    if (y % 2) {
                        vunshiftline(y);
                    } else {
                        vshiftline(y);
                    }
                }
                delay(15);
            }
            break;
        case 2:
            for (int y = 0; y < texth; y++) {
                for (int x = 0; x < textw; x++) {
                    if (vgetchar(x, y) != 0) max++;
                }
            }
            for (int i = 0; i < max; i++) {
                int x, y;
                do {
                    x = rand() % textw;
                    y = rand() % texth;
                } while (vgetchar(x, y) == 0);
                vsetchar(x, y, 0);
                delay(1);
            }
            vblank();
            break;
        case 3:
            for (int i = 0; i < texth; i++) {
                vscroll(-1);
                delay(50);
            }
            break;
        case 4:
            for (int y = 0; y < texth; y++) {
                for (int x = 0; x < textw; x++) {
                    if ((vgetfgc(x, y) != fgc || vgetbgc(x, y) != bgc) || (vgetchar(x, y) == 0 && vgetbgc(x, y) != bgc)) max++;
                }
            }
            for (int i = 0; i < max; i++) {
                int x, y;
                do {
                    x = rand() % textw;
                    y = rand() % texth;
                } while ((vgetfgc(x, y) == fgc && vgetbgc(x, y) == bgc) && (vgetchar(x, y) != 0 || vgetbgc(x, y) == bgc));
                vsetbgc(x, y, bgc);
                vsetfgc(x, y, fgc);
                delay(2);
            }
            max = 0;
            for (int y = 0; y < texth; y++) {
                for (int x = 0; x < textw; x++) {
                    if (vgetchar(x, y) != 0) max++;
                }
            }
            for (int i = 0; i < max; i++) {
                int x, y;
                do {
                    x = rand() % textw;
                    y = rand() % texth;
                } while (vgetchar(x, y) == 0);
                vsetchar(x, y, 0);
                delay(1);
            }
            vblank();
            break;
        default:
            vclear();
            break;
    }
    curx = 0; cury = 0;
    updatecursor();
    vshowcursor();
    gfx_fancy_text = tmp_gfx_fancy_text;
}
/*
int cur_x_old = 0;
int cur_y_old = 0;
int tmp_mouse_x = 0;
int tmp_mouse_y = 0;

void mouse_handler();
*/
void idleKeyboard() {
    //init_mouse();
    int tmp = 0;
    static int lastfc = 0;
    //mouse_handler();
    /*
    uint8_t tmpfgc = fgc;
    uint8_t tmpbgc = bgc;
    tmp_mouse_x = mouse_x;
    tmp_mouse_y = mouse_y;
    fgc = 15 - vgetfgc(tmp_mouse_x, tmp_mouse_y);
    bgc = 15 - vgetbgc(tmp_mouse_x, tmp_mouse_y);
    vsetchar(tmp_mouse_x, tmp_mouse_y, vgetchar(tmp_mouse_x, tmp_mouse_y));
    fgc = tmpfgc;
    bgc = tmpbgc;
    cur_x_old = tmp_mouse_x;
    cur_y_old = tmp_mouse_y;
    */
    while (1) {
        /*
        tmp_mouse_x = mouse_x;
        tmp_mouse_y = mouse_y;
        tmpfgc = fgc;
        tmpbgc = bgc;
        fgc = 15 - vgetfgc(cur_x_old, cur_y_old);
        bgc = 15 - vgetbgc(cur_x_old, cur_y_old);
        vsetchar(cur_x_old, cur_y_old, vgetchar(cur_x_old, cur_y_old));
        fgc = tmpfgc;
        bgc = tmpbgc;
        cur_x_old = tmp_mouse_x;
        cur_y_old = tmp_mouse_y;
        */
        char ch = kbgetchar();
        if (kb_alt_char) {
            kputchar(ch);
            if (!vgetchar(curx, cury)) vsetfgc(curx, cury, fgc);
            continue;
        }
        if (ch >= 0x80 && ch < 0x88) {
            uint8_t tmpcolor = ch - 0x80;
            if (lsft_d || rsft_d) tmpcolor += 8;
            if (lctl_d || rctl_d) {
                bgc = tmpcolor;
            } else {
                fgc = tmpcolor;
            }
            if (!vgetchar(curx, cury)) vsetchar(curx, cury, vgetchar(curx, cury));
            continue;
        }
        if (kbmodifers()) {
            switch (ch) {
                case 0:
                    break;
                case '\e':
                    if (lctl_d || rctl_d) asm("int $1");
                    break;
                case 12:
                    do {
                        tmp = (((uint8_t)(rand())) % 4) + 1;
                    } while (tmp == lastfc);
                    fancyClear(tmp);
                    lastfc = tmp;
                    break;
                default:
                    kputchar(ch);
                    if (!vgetchar(curx, cury)) vsetfgc(curx, cury, fgc);
                    break;
            }
        } else {
            switch (ch) {
                case 0:
                    break;
                case '\b':
                    do {
                        _kputchar('\b');
                    } while (curx && !vgetchar(curx - 1, cury));
                    updatecursor();
                    break;
                case 0x88:
                    vunshiftline(cury);
                    break;
                case 0x89:
                    vshiftline(cury);
                    break;
                case 0x8C:
                    if (cury > 0) cury--;
                    updatecursor();
                    break;
                case 0x8D:
                    if (curx + cury) {
                        curx--;
                        if (curx < 0) {
                            curx = textw - 1;
                            cury--;
                            if (cury < 0) {
                                cury = 0;
                                curx = 0;
                            }
                        }
                    }
                    updatecursor();
                    break;
                case 0x8E:
                    if (curx < textw && cury < texth) {
                        curx++;
                        if (curx >= textw) {
                            curx = 0;
                            cury++;
                            if (cury >= texth) {
                                cury = texth - 1;
                                curx = textw - 1;
                            }
                        }
                    }
                    updatecursor();
                    break;
                case 0x8F:
                    if (cury < texth - 1) cury++;
                    updatecursor();
                    break;
                case 0x90:
                    curx = 0;
                    updatecursor();
                    break;
                case 0x91:
                    curx = textw - 1;
                    updatecursor();
                    break;
                case 0x92:
                    if (cury > 0) cury--;
                    vscroll(1);
                    updatecursor();
                    break;
                case 0x93:
                    if (cury < texth - 1) cury++;
                    vscroll(-1);
                    updatecursor();
                    break;
                case 0x94:
                    if (curbtm == 15) {
                        switch (curtop) {
                            case 0:
                                vcursorstyle(14, 15);
                                break;
                            case 14:
                                vcursorstyle(0, 15);
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                default:
                    kputchar(ch);
                    if (!vgetchar(curx, cury)) vsetfgc(curx, cury, fgc);
                    break;
            }
        }
        //if (cur_x_old != mouse_x || cur_y_old != mouse_y) {
        //mouse_handler();
        /*
        tmpfgc = fgc;
        tmpbgc = bgc;
        fgc = 15 - vgetfgc(cur_x_old, cur_y_old);
        bgc = 15 - vgetbgc(cur_x_old, cur_y_old);
        vsetchar(cur_x_old, cur_y_old, vgetchar(cur_x_old, cur_y_old));
        fgc = tmpfgc;
        bgc = tmpbgc;
        cur_x_old = tmp_mouse_x;
        cur_y_old = tmp_mouse_y;
        */
        asm("hlt");
    }
}

void anykey(bool enter, bool clearln, char* str) {
    if (!str) str = "continue...";
    if (enter) {
        kprintf("Press ENTER to %s", str);
    } else {
        kprintf("Press any key to %s", str);
    }
    char ch = 0;
    do {
        asm("hlt");
        ch = kbgetchar();
    } while (ch);
    if (enter) {
        do {
            asm("hlt");
            ch = kbgetchar();
        } while (ch != '\n');
    } else {
        do {
            asm("hlt");
            ch = kbgetchar();
        } while (!ch);
    }
    if (clearln) {
        vclearline(cury);
    } else {
        kputchar('\n');
    }
}

void sysmsg(int code, char *s, ...)
{
    va_list args;
    uint32_t tmpfgc = fgc;
    switch (code) {
        case 0:
            kprintf("%_fDEBUG", 6);
            break;
        case 1:
            kprintf("%_fINFO", 11);
            break;
        case 2:
            kprintf("%_fOK", 10);
            break;
        case 3:
            kprintf("%_fLOADING", 15);
            break;
        case 4:
            kprintf("%_fWARNING", 14);
            break;
        case 5:
            kprintf("%_fALERT", 14);
            break;
        case 6:
            kprintf("%_fERROR", 12);
            break;
        case 7:
            kprintf("%_fFATAL", 4);
            break;
        default:
            kprintf("%_f[%_f%d%_f]", 8, 15, code, 8);
            break;
    }
    kprintf("%_f: ", 7);
    va_start(args, s);
    kprintf(s, *args);
    kputchar('\n');
    va_end(args);
    fgc = tmpfgc;
}

void vga_noblink() {
    asm("cli");
    asm("movw $0x03DA, %dx");
    asm("inb %dx, %al");
    asm("movw $0x03C0, %dx");
    asm("movb $0x30, %al");
    asm("outb %al, %dx");
    asm("incb %dl");
    asm("inb %dx, %al");
    asm("andb $0xF7, %al");
    asm("decb %dl");
    asm("outb %al, %dx");
}

void txtdiv() {
    for (int i = 0; i < textw; i++) {
        kputchar(196);
    }
}

static inline uint64_t rdtsc() {
    uint64_t ret;
    asm("rdtsc": "=A"(ret));
    return ret;
}
