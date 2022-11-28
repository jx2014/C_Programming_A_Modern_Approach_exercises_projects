//#include "foo.c"
#include <stdio.h>
#include "bar.h"
#include "barz.h"

void main(void) {
    //f("calling f() from main.c");
    printf("This calls from bar_test main()\n");    
    bar_c();
    barz_c();
    printf("...press any key to exit...\n");
    getchar();
}