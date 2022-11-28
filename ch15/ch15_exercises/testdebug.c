/********************************
 * Exercise 4 from chapter 15   *
 * ******************************/

#include <stdio.h>

#include "debug.h"
#define DEBUG

int main(void) {
    int i = 1, j = 2, k = 3;

    printf("This is testdebug.\n");
    #ifdef DEBUG
        printf("Output if DEBUG is defined:\n");
    #else
        printf("Output if DEBUG is not defined:\n");
    #endif

    PRINT_DEBUG(i);
    PRINT_DEBUG(j);
    PRINT_DEBUG(k);
    PRINT_DEBUG(i + j);
    PRINT_DEBUG(2 * i + j - k);

    return 0;
}

/**** answer the following question***
 * 
 * a) what is the output when the program is executed?
 *  Output if DEBUG is defined:
 *  Value of i: 1 
 *  Value of j: 2 
 *  Value of k: 3 
 *  Value of i + j: 3 
 *  Value of 2 * i + j - k: 1
 * 
 * b) what is the output if #define directive is removed from testdebug.c?
 *  Output if DEBUG is not defined:
 * 
 * c) why the output is different in part (a) and (b)?
 *  In part b), since DEBUG is undefined, preprocessor will repalce "PRINT_DEBUG(n);"" with ";"
 * 
 * d) Is it necessary for the DEBUG macro to be defined before debug.h?
 *  Yes, it does matter. If DEBUG is defined after debug.h, preprocessor will not treat DEBUG as undefined
 *  when processing debug.h. When the program is executed, we will get:
 *  Output if DEBUG is defined:
 * 
 * **********************************/