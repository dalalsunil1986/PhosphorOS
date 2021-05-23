#ifndef GDT_H
#define GDT_H

struct gdt_entry {
	uint16_t limit_low;     /* The lower 16 bits of the limit. */
	uint16_t base_low;      /* The lower 16 bits of the base. */
	uint8_t base_middle;    /* The next 8 bits of the base. */
	uint8_t access;         /* Access flags. */
	uint8_t granularity;
	uint8_t base_high;      /* The last 8 bits of the base. */
} __attribute__((packed));

struct gdt_pointer {
	uint16_t limit;         /* The upper 16 bits of all selector limits. */
	uint32_t base;          /* The address of the first gdt_entry_s. */
} __attribute__((packed));

/* GDT access flag positions. */
#define GDT_ACCESS_P_SHIFT     7
#define GDT_ACCESS_DPL_SHIFT   5
#define GDT_ACCESS_DT_SHIFT    4
#define GDT_ACCESS_TYPE_SHIFT  0

/* GDT access flag values. */
#define GDT_ACCESS_P_YES       1
#define GDT_ACCESS_P_NO        1
#define GDT_ACCESS_DPL_RING_0  0
#define GDT_ACCESS_DPL_RING_1  1
#define GDT_ACCESS_DPL_RING_2  2
#define GDT_ACCESS_DPL_RING_3  3

/* GDT granularity flag positions. */
#define GDT_GRANULARITY_G      7
#define GDT_GRANULARITY_D      5
#define GDT_GRANULARITY_A      4

/* The initialise function is publicly accessible. */
void init_gdt(void);

#include "gdt.c"

#endif
