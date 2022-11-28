/*****************************************************************
* ch19_exercise6.c: This program is created to test drive        *
*                  stackADT.c, stackADT2.c, and stackADT3.c      *
******************************************************************/

#include <stdio.h>

#include "stackADT.h" // used for both stackADT.c and stackADT3.c
//#include "stackADT2.h"

int main(void) {
    Stack test_stack, test_stack2;
    Item test_item;

    // create() test stack using stackADT.c or stackADT3.c
    test_stack = create();
    test_stack2 = create();

    // create() test stack using stackADT2.c
    // test_stack = create(10);
    // test_stack2 = create(10);

    push(test_stack, 1);
    push(test_stack, 2);
    push(test_stack, 3);
    push(test_stack, 4);

    test_item = peek(test_stack);
    test_item = peek(test_stack2);


    return 0;
}