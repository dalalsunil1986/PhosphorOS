#include <commondef.h>

#ifndef GDT_H
#define GDT_H

struct gdt_entry {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t granularity;
	uint8_t base_high;
} __attribute__((packed));

struct gdt_pointer {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed));

#define GDT_ACCESS_P_SHIFT     7
#define GDT_ACCESS_DPL_SHIFT   5
#define GDT_ACCESS_DT_SHIFT    4
#define GDT_ACCESS_TYPE_SHIFT  0

#define GDT_ACCESS_P_YES       1
#define GDT_ACCESS_P_NO        1
#define GDT_ACCESS_DPL_RING_0  0
#define GDT_ACCESS_DPL_RING_1  1
#define GDT_ACCESS_DPL_RING_2  2
#define GDT_ACCESS_DPL_RING_3  3

#define GDT_GRANULARITY_G      7
#define GDT_GRANULARITY_D      5
#define GDT_GRANULARITY_A      4

#include "gdt.c"

#endif
