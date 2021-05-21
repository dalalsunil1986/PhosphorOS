#ifndef COMMON_H
#define COMMON_H

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

#include <stddef.h>
#include <stdint.h>
#include <video/video.h>
#include <kstd.h>
#include <util.h>
#include "../panic.h"
#include "../multiboot.h"

multiboot_info_t* mbi;
uint32_t mbi_start;
uint32_t mbi_end;
uint32_t mbi_nff;

static uint32_t free_mem;
static uint32_t usable_mem;

#define assert(x) if (x) return

#endif