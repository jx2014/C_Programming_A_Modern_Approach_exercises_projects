#include <stdio.h>
#include "foo.h"

void f(const char *c) {
    const char *p;
    for (p = c; *p != '\n' && p < c + 1000; p++) {
        putchar(*p);
    }
    putchar('\n');
    
}