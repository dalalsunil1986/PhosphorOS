#include <common.h>

extern uint8_t* mem_ent_begin;
static uint8_t* page_map = (uint8_t*)&mem_ent_begin;

uint32_t next_free_page = 0;

void set_page_use(uint32_t page_no, bool val) {
    page_map[page_no / 8] ^= (-val ^ page_map[page_no / 8]) & (1UL << (page_no % 8));
}

bool get_page_use(uint32_t page_no) {
    return (bool)((page_map[page_no / 8] >> (page_no % 8)) & 1U);
}

void* next_page() {
    while (get_page_use(next_free_page)) {
        next_free_page++;
    }
    uint32_t addr = next_free_page * 4096;
    set_page_use(next_free_page, 1);
    alloc_mem += 4096;
    do {
        next_free_page++;
    } while (get_page_use(next_free_page));
    return (void*)addr;
}

void* next_pages(uint32_t ct) {
    uint32_t tmpct = 0;
    for (uint32_t i = next_free_page; i < 131072; i++) {
        if (!get_page_use((unsigned int)next_free_page + tmpct)) {
            tmpct++;
            if (tmpct == ct) {
                uint32_t page_addr = next_free_page * 4096;
                for (uint32_t i = 0; i < ct; i++) {
                    set_page_use(next_free_page, 1);
                    next_free_page++;
                    alloc_mem += 4096;
                }
                return (void*)page_addr;
            }
        } else {
            do {
                next_free_page++;
            } while (get_page_use(next_free_page));
            tmpct = 0;
        }
    }
    return (void*)NULL;
}

void free_page(uint32_t page_addr) {
    page_addr /= 4096;
    set_page_use(page_addr, 0);
    alloc_mem -= 4096;
    next_free_page = page_addr;
    while (next_free_page > 0 && !get_page_use(next_free_page - 1)) {
        next_free_page--;
    }
}

void free_pages(uint32_t page_addr, uint32_t ct) {
    page_addr /= 4096;
    for (uint32_t i = 0; i < ct; i++) {
        set_page_use(page_addr + i, 0);
        alloc_mem -= 4096;
    }
    next_free_page = page_addr;
    while (next_free_page > 0 && !get_page_use(next_free_page - 1)) {
        next_free_page--;
    }
}

void init_mem() {
    for (int i = 0; i < 131072; i++) {
        page_map[i] = 255;
    }
    struct stivale_mmap_entry* memmap = (struct stivale_mmap_entry*)(uintptr_t)(stivale_info->memory_map_addr);
    for (size_t i = 0; i < stivale_info->memory_map_entries; i++) {
        struct stivale_mmap_entry e = memmap[i];
        for (uint32_t len = 0; len + 4096 <= e.length; len += 4096) {
            if (e.type == STIVALE_MMAP_USABLE)
            set_page_use(((unsigned int)(e.base + len) / 4096), 0);
        }
    }
}

void* malloc(uint32_t size) {
    if (!size) return (void*)NULL;
    size += 16;
    uint32_t len = ((unsigned int)(size) / 4096) + 1;
    uint32_t* pages = next_pages(len);
    if (!pages) return (void*)NULL;
    pages[0] = len;
    return (void*)&pages[4];
}

void* calloc(uint32_t size, uint32_t t_size) {
    size *= t_size;
    uint8_t* array = (uint8_t*)malloc(size);
    if (!array) return (void*)NULL;
    for (uint32_t i = 0; i < size; i++) {
        array[i] = 0;
    }
    return (void*)array;
}

void free(void* ptr) {
    if (!ptr) return;
    uint32_t* pages = (uint32_t*)ptr;
    if (!pages[-4]) return;
    free_pages((uint32_t)&pages[-4], pages[-4]);
    pages[-4] = 0;
}

void* realloc(void* tmpptr, uint32_t size) {
    uint8_t* ptr = (uint8_t*)(uintptr_t)tmpptr;
    if (!ptr) return malloc(size);
    uint8_t* array = (uint8_t*)malloc(size);
    for (uint32_t i = 0; i < size; i++) {
        array[i] = ptr[i];
    }
    free(ptr);
    return (void*)array;
}
