/********************************
 * Exercise 5 from chapter 15   *
 * ******************************/

#include <stdio.h>
#include "f1.h"
#include "f2.h"

void f2(int n, int m) {
    printf("this is f2() as defined in f2.c\n");
    printf("f2() is being called by f%d with a second varible m: %d.\n", n, m);
    printf("also calling f3() from f2:\n");
    f3();
}

