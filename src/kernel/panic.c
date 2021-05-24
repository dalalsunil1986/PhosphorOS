#include <commondef.h>

void kph();

//#define WIN_9X_BSOD

/*
struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;
};
*/
void kpanic(int err, struct regs* r, char* str) {
    __asm__ volatile("cli");
    setvmode(0);
    vcolor(7, 0); 
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
    } else {
        movecursor(7, 12);
        _kputs(str);
    }
    #else
    vclearcolor(0);
    vcolor(4, 7); movecursor(3, 2); _kputs(" PhosphorOS ");
    vcolor(12, 0);
    movecursor(3, 5); __kputs("Unhandled exception!");
    movecursor(3, 7); kprintf("Exception code: %d", r->int_no);
    movecursor(3, 8); kprintf("Exception error: %d", r->err_code);
    movecursor(3, 9); kprintf("Exception description: %s", exmsgs[err]);
    movecursor(3, 11); __kputs("Registers:");
    movecursor(3, 12); kprintf("cs: [0x%_x] ds: [0x%_x] es: [0x%_x]", (uint32_t)(r->cs), 4, (uint32_t)(r->ds), 4, (uint32_t)(r->es), 4);
    movecursor(3, 13); kprintf("fs: [0x%_x] gs: [0x%_x] ss: [0x%_x]", (uint32_t)(r->fs), 4, (uint32_t)(r->gs), 4, (uint32_t)(r->ss), 8);
    movecursor(3, 14); kprintf("eax: [0x%_x] ebx: [0x%_x]", (uint32_t)(r->eax), 8, (uint32_t)(r->ebx), 8);
    movecursor(3, 15); kprintf("ecx: [0x%_x] edx: [0x%_x]", (uint32_t)(r->ecx), 8, (uint32_t)(r->edx), 8);
    movecursor(3, 16); kprintf("ebp: [0x%_x] eip: [0x%_x]", (uint32_t)(r->ebp), 8, (uint32_t)(r->eip), 8, (uint32_t)(r->esp), 8);
    movecursor(3, 17); kprintf("edi: [0x%_x] esi: [0x%_x]", (uint32_t)(r->edi), 8, (uint32_t)(r->esi), 8);
    movecursor(3, 18); kprintf("esp: [0x%_x]", (uint32_t)(r->esp), 8);
    movecursor(3, 19); kprintf("eflags: [0x%_x]", (uint32_t)(r->eflags), 8);
    vcolor(7, 0);
    movecursor(3, 22); _kputs("System halted, press CTRL+ALT+DEL to reboot.");    
    #endif
    while (1) {
        kph();
        //asm("hlt");
    }
}
