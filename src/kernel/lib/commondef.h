#ifndef COMMONDEF_H
#define COMMONDEF_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct regs
{
    unsigned int gs, fs, es, ds;
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
    unsigned int int_no, err_code;
    unsigned int eip, cs, eflags, useresp, ss;
};

typedef struct {
   uint32_t ds;
   uint32_t edi, esi, ebp, useless, ebx, edx, ecx, eax;
   uint32_t int_no, err_code;
   uint32_t eip, cs, eflags, esp, ss;
} registers_t;

#define assert(x) if (x) return

#define asm(s) __asm__ volatile (s)

#endif
