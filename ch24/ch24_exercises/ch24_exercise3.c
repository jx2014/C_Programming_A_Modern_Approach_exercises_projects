/*****************************************************************
* ch19_exercise7.c: This program is created to test drive        *
*                  stackADT2_exercise7.c. The push function will *
*                  allocate additional memory when full.         *
******************************************************************/

// this is modified for ch24, modified from ch19_exercise7.c, 
// where assert is used to test for errors instead of using if 
// statement.

#include <stdio.h>

#include "stackADT2.h" // used for stackADT2_exercise3.c

int main(void) {
    Stack test_stack, test_stack2;
    Item test_item;

    // create() test stack using stackADT2_exercise7.c
    test_stack = create(2);
    test_stack2 = create(2);

    push(test_stack, 1);
    push(test_stack, 2);
    push(test_stack, 3);
    push(test_stack, 4);
    push(test_stack, 5);
    push(test_stack, 6);
    push(test_stack, 7);
    push(test_stack, 8);
    push(test_stack, 9);
    push(test_stack, 10);

    test_item = peek(test_stack);
    test_item = peek(test_stack2);


    return 0;
}