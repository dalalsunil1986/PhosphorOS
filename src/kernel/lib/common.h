#ifndef COMMON_H
#define COMMON_H

#include <commondef.h>

#define kbmodifers() (lsft_d || lctl_d || lalt_d || rsft_d || rctl_d || ralt_d)

char *exmsgs[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

static struct stivale_struct* stivale_info;
bool fpupresent = false;

//#include <video/video.h>
#include <kstd.h>
//#include <util.h>
//#include <panic.h>
//#include <stivale.h>

static uint32_t free_mem;
static uint32_t usable_mem;
static uint32_t alloc_mem;

uint64_t ticks;

uint64_t boot_ticks;

#endif