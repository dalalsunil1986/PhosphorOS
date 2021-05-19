#include <kstd.h>

char phkver[] = "0.1";
char phkrev[] = "A";

void main() {
    vmode(0);
    _kputs("PhosphorOS version ");
    _kputs(phkver);
    _kputs(" revision ");
    _kputs(phkrev);
    kputchar('\n');
    kputs("kputs() test");
}
