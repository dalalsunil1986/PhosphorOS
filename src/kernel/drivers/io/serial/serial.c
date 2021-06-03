#ifndef COM1
#define COM1 0x3f8
#endif

void init_serial(uint16_t port) {
    outb(port + 1, 0x00);
    outb(port + 3, 0x80);
    outb(port + 0, 0x03);
    outb(port + 1, 0x00);
    outb(port + 3, 0x03);
    outb(port + 2, 0xC7);
    outb(port + 4, 0x0B);
}
int serial_received(uint16_t port) {
    return inb(port + 5) & 1;
}

char XDev_Serial_read_serial(uint16_t port) {
    while(serial_received(port) == 0);
    return inb(port);
}

int serial_empty(uint16_t port) {
    return inb(port + 5) & 0x20;
}

void serial_putchar(uint16_t port, char ch) {
    while(serial_empty(port) == 0);
    outb(port, ch);
}

void serial_puts(uint16_t port, char* str) {
    for (int i = 0; str[i]; i++) {
        serial_putchar(port, str[i]);
    }  
}
