#include <common.h>

extern uint32_t _kernel_start;
extern uint32_t _kernel_end;

void checkmem() {
    free_mem = 0;
    usable_mem = 0;
    kprintf("MEM: KERNEL: [0x%_x] - [0x%_x]\n", (uint32_t)(&_kernel_start), 8, (uint32_t)(&_kernel_end), 8);
    for (multiboot_memory_map_t *mmap = (multiboot_memory_map_t *)mbi->mmap_addr; (uintptr_t)mmap < mbi->mmap_addr + mbi->mmap_length; mmap = (multiboot_memory_map_t *)((uintptr_t)mmap + mmap->size + sizeof(mmap->size))) {
	    if ((uint32_t)(mmap->addr) >= (uint32_t)(&_kernel_start) && (uint32_t)(mmap->addr) <= (uint32_t)(&_kernel_end)) {
	        int r = 4 - ((uint32_t)(mmap->addr) % 4);
	        mmap->len = (uint32_t)(mmap->len) - (uint32_t)&_kernel_end - (uint32_t)(mmap->addr) - r;
	        mmap->addr = (uint32_t)(&_kernel_end) + r;
        }
        usable_mem += (uint32_t)(mmap->len);
	    kprintf("MEM: [0x%_x] - [0x%_x]: ", (uint32_t)(mmap->addr), 8, (uint32_t)(mmap->addr + mmap->len) - 1, 8);
	    if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE) {
	        kputs("FREE");
	        free_mem += (uint32_t)(mmap->len);
        } else {
            kputs("USED");
        }
    }
}
