#include <video/video.h>
#include <sound/beeper/beeper.h>
#include <stdarg.h>

void (* _kputchar)(char c);

static inline void _std_kputchar(char c) {
    if (!c) return;
    int tmptab;
    switch (c) {
        case '\n':
            curx = 0;
            if (cury >= texth - 1) {
                vscroll(1);
            } else {
                cury += 1;
            }
            break;
        case '\r':
            curx = 0;
            break;
        case '\f':
            for (int i = 0; i < 80; i++) {
                _kputchar('\n');
            }
            curx = cury = 0;
            break;
        case '\t':
            tmptab = tab - (curx % tab);
            for (int i = 0; i < tmptab; i++) {
                _kputchar(' ');
                if (curx > textw - 1) {
                    _kputchar('\n');
                    break;
                }
            }
            break;
        case '\b':
            if (curx + cury) {
                curx--;
                if (curx < 0) {
                    curx = textw - 1;
                    cury--;
                    if (cury < 0) {
                        cury = 0;
                        curx = 0;
                    }
                }
                vsetchar(curx, cury, 0);
            }
            break;
        case 7:
            beep(900, 150);
            break;
        case 127:
            vsetchar(curx, cury, 0);
            break;
        default:
            vsetchar(curx, cury, c);
            curx += 1;
            if (curx > textw - 1) {
                curx = 0;
                if (cury >= texth - 1) {
                    vscroll(1);
                } else {
                    cury += 1;
                }
            }
            break;
    }
}

inline void kwritechar(char c) {
    vsetchar(curx, cury, c);
    curx += 1;
    if (curx > textw - 1) {
        curx = 0;
        if (cury >= texth - 1) {
            vscroll(1);
        } else {
            cury += 1;
        }
    }
}

static inline void movecursor(int x, int y) {
    curx = x;
    cury = y;
    updatecursor();
}

void kputchar(char c) {
    if (c) {
        _kputchar(c);
        updatecursor();
    }
}

void __kputs(char* s) {
    char* t = s;
    while (*t) {
        _kputchar(*t);
        t++;
    }
}

static inline void _kputs(char* s) {
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

char *convert(uint64_t num, int base) { 
    static char chars[] = "0123456789ABCDEF";
    static char buffer[64];
    char *ptr;
    ptr = (char *)&buffer;
    *ptr = 0;
    do {
        ptr--;
        *ptr = chars[num % base];
        num /= base;
    } while (num != 0);
    return ptr;
}

unsigned int kstrlen(char* str);

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
                    _kputchar(va_arg(arg, unsigned int));
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
                        case 'c':
                            vsetchar(curx, cury, va_arg(arg, unsigned int));
                            curx += 1;
                            if (curx > textw - 1) {
                                curx = 0;
                                if (cury >= texth - 1) {
                                    vscroll(1);
                                } else {
                                    cury += 1;
                                }
                            }
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

int atoi(char* str) {
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        res = res * 10 + str[i] - '0';
    }
    return res;
}

void* kmemset(void* b, int c, int len) {
    unsigned char *p = b;
    while (len > 0) {
        *p = c;
        p++;
        len--;
    }
    return b;
}

unsigned int kstrlen(char* str) {
    if (!str) return 0;
    unsigned int len = 0;
    while (str[len]) {len++;}
    return len;
}

char* kstrcpy(char* str2, char* str1) {
    if (!str2) return NULL;
    if (!str1) {str2[0] = 0; return str2;}
    int i;
    for (i = 0; str1[i]; i++) {str2[i] = str1[i];}
    str2[i] = 0;
    return str2;
}

char* kstrncpy(char* str2, char* str1, int n) {
    if (!str2) return NULL;
    if (!str1 || !n) {str2[0] = 0; return str2;}
    int i;
    for (i = 0; i < n; i++) {str2[i] = str1[i];}
    str2[i] = 0;
    return str2;
}
