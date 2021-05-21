#include <video/video.h>
#include <stdarg.h>

static inline void _kputchar(char c) {
    int tmptab;
    switch (c) {
        case 0:
            break;
        case '\n':
            curx = 0;
            if (cury >= screenh - charh) {
                vscroll(1);
            } else {
                cury += charh;
            }
            break;
        case '\r':
            curx = 0;
            break;
        case '\t':
            tmptab = 4 - (curx % 4);
            for (int i = 0; i < tmptab; i++) {
                _kputchar(' ');
                if (curx > screenw - charw) {
                    _kputchar('\n');
                    break;
                }
            }
            break;
        default:
            ksetchar(curx, cury, c);
            curx += charw;
            if (curx > screenw - charw) {
                curx = 0;
                if (cury >= screenh - charh) {
                    vscroll(1);
                } else {
                    cury += charh;
                }
            }
            break;
    }
}

static inline void movecursor(int x, int y) {
    curx = x;
    cury = y;
    updatecursor();
}

void kputchar(char c) {
    _kputchar(c);
    updatecursor();
}

void __kputs(char* s) {
    char* t = s;
    while (*t) {
        _kputchar(*t);
        t++;
    }
}

void _kputs(char* s) {
    char* t = s;
    while (*t) {
        _kputchar(*t);
        t++;
    }
    updatecursor();
}

void kputs(char* s) {
    char* t = s;
    while (*t) {
        _kputchar(*t);
        t++;
    }
    kputchar('\n');
}

unsigned int kstrlen(const char *str) {
    unsigned int l = 0;
    while (str[l]) {l++;}
    return l;
}
    

char *convert(unsigned int num, int base) { 
    static char chars[]= "0123456789ABCDEF";
    static char buffer[64];
    char *ptr;
    ptr = &buffer[64];
    *ptr = '\0';
    do {
        ptr--;
        *ptr = chars[num % base];
        num /= base;
    } while (num != 0);
    return ptr;
}

void kprintf(char* s, ...) {
    char* tmp;
    va_list arg;
    va_start(arg, s);
    int d;
    char* str;
    int tfgc = fgc, tbgc = bgc;
    for (tmp = s; *tmp; tmp++) {
        if (*tmp == '%') {
            tmp++;
            switch (*tmp) {
                case 'c':
                    _kputchar(va_arg(arg, int));
                    break;
                case 's':
                    __kputs(va_arg(arg, char*));
                    break;
                case 'd':
                    d = va_arg(arg, int);
                    if (d < 0) {d = -d; _kputchar('-');}
                    __kputs(convert(d, 10));
                    break;
                case 'u':
                    __kputs(convert(va_arg(arg, unsigned int), 10));
                    break;
                case 'x':
                    __kputs(convert(va_arg(arg, unsigned int), 16));
                    break;
                case 'o':
                    __kputs(convert(va_arg(arg, unsigned int), 8));
                    break;
                case '%':
                    _kputchar('%');
                    break;
                case '_':
                    tmp++;
                    switch (*tmp) {
                        case 'f':
                            fgc = va_arg(arg, unsigned int);
                            break;
                        case 'b':
                            bgc = va_arg(arg, unsigned int);
                            break;
                        case 'x':
                            str = convert(va_arg(arg, unsigned int), 16);
                            d = va_arg(arg, unsigned int) - kstrlen(str);
                            while (d > 0) {_kputchar('0'); d--;}
                            __kputs(str);
                            break;
                        default:
                            __kputs("%_");
                            _kputchar(*tmp);
                    }
                    break;
                default:
                    _kputchar('%');
                    _kputchar(*tmp);
                    break;
            }
        } else {
            _kputchar(*tmp);
        }
    }
    fgc = tfgc; bgc = tbgc;
    updatecursor();
}

unsigned int seed;

#define srand(n) seed = (unsigned int)n

int rand() {
    unsigned int next = seed;
    int result;
    next *= 1103515245;
    next += 12345;
    result = (unsigned int) (next / 65536) % 2048;
    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int) (next / 65536) % 1024;
    next *= 1103515245;
    next += 12345;
    result <<= 10;
    result ^= (unsigned int) (next / 65536) % 1024;
    seed = next;
    return result;
}
