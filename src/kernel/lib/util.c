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
}

void idleKeyboard() {
    int tmp = 0;
    static int lastfc = 0;
    while (1) {
        char ch = kbgetchar();
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
        switch (ch) {
            case '\b':
                do {
                    _kputchar('\b');
                } while (curx && !vgetchar(curx - 1, cury));
                updatecursor();
                break;
            case 12:
                do {
                    tmp = ((uint8_t)(rand()) % 3) + 1;
                } while (tmp == lastfc);
                fancyClear(tmp);
                lastfc = tmp;
                //fancyClear(4);
                break;
            case 0x8D:
                if (cury > 0) cury--;
                updatecursor();
                break;
            case 0x90:
                if (cury < texth - 1) cury++;
                updatecursor();
                break;
            case 0x8E:
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
            case 0x88:
                vunshiftline(cury);
                break;
            case 0x89:
                vshiftline(cury);
                break;
            case 0x8F:
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
            case 0x8C:
                if (lctl_d || rctl_d) asm("int $1");
                break;
            default:
                kputchar(ch);
                break;
        }
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
