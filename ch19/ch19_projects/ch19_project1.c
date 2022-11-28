#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT2.h"

#define INITIAL_STACK_SIZE (10)
/******************************************************************
* Ch19 Project 1: This project modifies the Project 1 from        *
*                 Chapter 10. A user is prompt to enter           *
*                 parentheses and/or braces: ((){}{()}), and      *
*                 print out whether or not the parentheses are    *
*                 nested properly. Implemented using one of the   *
*                 stackADTs.                                      *
******************************************************************/
int main(void) {

    Stack a_string = create(INITIAL_STACK_SIZE);
    bool b_bad_nest = false;
    char c;

    printf("Enter parentheses and/or braces: ");
    
    for (c = getchar(); c != '\n'; c = getchar()) {
        switch (c) {
            case '(': case '{': case '[':
                push(a_string, (Item) c);
                break;
            case ')':
                if ( pop(a_string) != (Item)'(' ) {
                    b_bad_nest = true;                    
                }
                break;
            case ']':
                if ( pop(a_string) != (Item)'[' ) {
                    b_bad_nest = true;                    
                }
                break;
            case '}':
                if ( pop(a_string) != (Item)'{' ) {
                    b_bad_nest = true;                    
                }                     
                break;       
        }
    }
    if (b_bad_nest)
        printf("Parentheses/braces are nested incorrectly.\n");
    else
        printf("Parentheses/braces are nested properly.\n");


    return 0;
}