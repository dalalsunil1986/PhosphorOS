#ifndef COMMON_H
#define COMMON_H

#include <commondef.h>

bool keydown[384];

static char keymap_lower[128] =
"\e1234567890-=\b\tqwertyuiop[]\n\0asdfghjkl;'`\0\\zxcvbnm,./\0*\0 \0\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\0""789-456+1230.\0\0\0\x8B\x8C";

static char keymap_upper[128] =
"\e!@#$%^&*()_+\b\tQWERTYUIOP{}\r\0ASDFGHJKL:\"~\0|ZXCVBNM<>?\0*\0 \0\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\0""789-456+1230.\0\0\0\x8B\x8C";

static char keymap_special[128] =
"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0/\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x8D\0\0\x8E\0\x8F\0\0\x90\0\0\x7F\0\0\0\0\0";

static char keymap_ascii[128] =
"\e1234567890-=\b\t\x11\x17\x05\x12\x14\x19\x15\x09\x0F\x10[]\r\0\x01\x13\x04\x06\x07\x08\x0A\x0B\x0C;'`\0\\\x1A\x18\x03\x16\x02\x0E\x0D,./\0*\0 \0\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\0""789-456+1230.\0\0\0\x8B\x8C";

bool c_lock = false, n_lock = false, s_lock = false;
bool lsft_d = false, lctl_d = false, lalt_d = false;
bool rsft_d = false, rctl_d = false, ralt_d = false;

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

struct stivale_struct* stivale_info;
bool fpupresent = false;

//#include <video/video.h>
#include <kstd.h>
//#include <util.h>
//#include <panic.h>
//#include <stivale.h>

static uint32_t free_mem;
static uint32_t usable_mem;

uint64_t ticks;

uint64_t boot_ticks;

#endif