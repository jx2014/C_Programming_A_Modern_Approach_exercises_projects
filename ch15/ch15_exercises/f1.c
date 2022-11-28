/********************************
 * Exercise 5 from chapter 15   *
 * ******************************/

#include <stdio.h>
#include "f1.h"
#include "f2.h"

void f1(int n) {
    printf("\n");
    printf("this is f1() as defined in f1.c\n");
    printf("n from f1(int n) is: %d\n", n);
    printf("also calling f2() from f1().\n");
    f2(1, 13);
}

void f3(void) {    
    printf("this is f3() as defined in f1.c\n\
    someone else will call f3().\n");
}