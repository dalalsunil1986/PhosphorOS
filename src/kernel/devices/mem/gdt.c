extern void gdt_flush(uint32_t);

static struct gdt_entry gdt_entries[5];
static struct gdt_pointer gdt_p;

static void gdt_set_gate(int32_t number, uint32_t base, uint32_t limit,  uint8_t access, uint8_t granularity)
{
	gdt_entries[number].base_low     = (base & 0xFFFF);
	gdt_entries[number].base_middle  = (base >> 16) & 0xFF;
	gdt_entries[number].base_high    = (base >> 24) & 0xFF;
	gdt_entries[number].limit_low    = (limit & 0xFFFF);
	gdt_entries[number].granularity  = (limit >> 16) & 0x0F;
	gdt_entries[number].granularity |= granularity & 0xF0;
	gdt_entries[number].access       = access;
}

void init_gdt() {
	gdt_p.limit = (sizeof(struct gdt_entry) * 5) - 1;
	gdt_p.base  = (uint32_t)&gdt_entries;
	gdt_set_gate(0, 0, 0x00000000, 0x00, 0x00);
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
	gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
	gdt_flush((uint32_t)&gdt_p);
}

void tfault() {
    struct gdt_entry null_gdt_entry[1];
    struct gdt_pointer null_gdt_p;
    null_gdt_p.limit = sizeof(struct gdt_entry) - 1;
    null_gdt_p.base  = (uint32_t)&null_gdt_entry;
    gdt_flush((uint32_t)&null_gdt_p);
}
