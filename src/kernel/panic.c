#include <commondef.h>

void kph();
char kbgetchar();

//#define WIN_9X_BSOD

int _panic_margin = 0;

static inline void _panic_kputchar(char c) {
    if (!c) return;
    int tmptab;
    switch (c) {
        case '\n':
            curx = _panic_margin;
            if (cury >= texth - 1) {
                vscroll(1);
            } else {
                cury += 1;
            }
            break;
        case '\t':
            tmptab = tab - (curx % tab);
            for (int i = 0; i < tmptab; i++) {
                _kputchar(' ');
                if (curx > textw - _panic_margin - 1) {
                    _kputchar('\n');
                    break;
                }
            }
            break;
        default:
            vsetchar(curx, cury, c);
            curx += 1;
            if (curx > textw - _panic_margin - 1) {
                curx = _panic_margin;
                if (cury >= texth - 1) {
                    vscroll(1);
                } else {
                    cury += 1;
                }
            }
            break;
    }
}

void kpanic(int err, struct regs* r, char* str) {
    asm("cli");
    _kputchar = _panic_kputchar;
    #ifdef WIN_9X_BSOD
    vclearcolor(1);
    vcolor(1, 7); movecursor(34, 8); _kputs(" PhosphorOS "); vcolor(7, 1);
    if (err > 0) {
        movecursor(7, 11);
        _kputs("An unhandled exception has occurred and the system has been halted");
        movecursor(7, 13);
        kprintf("Exception code: %d", err);
        movecursor(7, 14);
        kprintf("Exception description: %s", exmsgs[err]);
        movecursor(7, 16);
        _kputs("Press CTRL+ALT+DEL to reboot.");
    } else {
        movecursor(7, 12);
        _kputs(str);
    }
    (void)r;
    while (1) {
        kph();
    }
    #else
    vsavebuf();
    vclearcolor(0);
    _panic_margin = 3;
    vcolor(4, 7); movecursor(3, 2); _kputs(" PhosphorOS ");
    vcolor(12, 0);
    if (str) {
        movecursor(3, 5); __kputs(str);
    } else {
        movecursor(3, 5);
        kputs("Unhandled exception!\n");
        kprintf("Exception code: %d\n", r->int_no);
        kprintf("Exception error: %d\n", r->err_code);
        kprintf("Exception description: %s\n\n", exmsgs[err]);
        kputs("Registers:");
        kprintf("cs: [0x%_x] ds: [0x%_x] es: [0x%_x]\n", (uint32_t)(r->cs), 4, (uint32_t)(r->ds), 4, (uint32_t)(r->es), 4);
        kprintf("fs: [0x%_x] gs: [0x%_x] ss: [0x%_x]\n", (uint32_t)(r->fs), 4, (uint32_t)(r->gs), 4, (uint32_t)(r->ss), 8);
        kprintf("eax: [0x%_x] ebx: [0x%_x]\n", (uint32_t)(r->eax), 8, (uint32_t)(r->ebx), 8);
        kprintf("ecx: [0x%_x] edx: [0x%_x]\n", (uint32_t)(r->ecx), 8, (uint32_t)(r->edx), 8);
        kprintf("ebp: [0x%_x] eip: [0x%_x]\n", (uint32_t)(r->ebp), 8, (uint32_t)(r->eip), 8, (uint32_t)(r->esp), 8);
        kprintf("edi: [0x%_x] esi: [0x%_x]\n", (uint32_t)(r->edi), 8, (uint32_t)(r->esi), 8);
        kprintf("esp: [0x%_x]\n", (uint32_t)(r->esp), 8);
        kprintf("eflags: [0x%_x]\n", (uint32_t)(r->eflags), 8);
    }
    vcolor(7, 0);
    movecursor(3, texth - 3); _kputs("Press CTRL+ALT+DEL to reboot or ENTER to resume.");    
    while (1) {
        kph();
        if (kbgetchar() == '\n') break;
    }
    asm("sti");
    vrestorebuf();
    while (kbgetchar()) {}
    #endif
}
