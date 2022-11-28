/******************************************************************
* Ch19 Exercise 4: Part (a), This program test drive the          *
*                  implementation of the stack type with a        *
*                  fixed-length array.                            *
******************************************************************/

#include <stdio.h>
#include <stdbool.h>
#define EXERCISE_4A (0)
#define EXERCISE_4B (1)

#if (EXERCISE_4A)
#include "stack_exercise4a.h" // stack using fixed-length array
#endif

#if (EXERCISE_4B)
#include <stdlib.h>
#include "stack_exercise4b.h" // stack using linked-list
#endif

int main(void) {

#if (EXERCISE_4A)
    Stack s1, s2, s3;
    int a, b;
    bool c;
    
    //make_empty(&s1);
    //make_empty(&s2);
    //make_empty(&s3);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);
    push(&s1, 6);
    push(&s1, 7);
    push(&s1, 8);
    push(&s1, 9);
    push(&s1, 10);
    push(&s1, 11);
    push(&s1, 12);
    c = is_full(&s1);
    c = is_full(&s2);
    c = is_empty(&s1);
    c = is_empty(&s2);

    a = pop(&s1);
    b = pop(&s2);
#endif
    
#if (EXERCISE_4B)
    Stack *s1 = malloc(sizeof(Stack));
    (*s1) = NULL; // initialize s1
    Stack *s2; // a second method to create stack pointer
    int a, b;
    bool c;
    //make_empty(s1);
    //make_empty(s2);
    //make_empty(s3);

    //create_stack(s1);
    create_stack(s2);
    //create_stack(&s3);
    
    c = is_empty(s1);
    c = is_empty(s2);
    push(s2, 1);
    push(s2, 2);
    push(s2, 3);
    push(s2, 4);
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    push(s1, 6);
    push(s1, 7);
    push(s1, 8);
    push(s1, 9);
    push(s1, 10);
    push(s1, 11);
    push(s1, 12);
    c = is_full(s1);
    c = is_full(s2);
    c = is_empty(s1);
    c = is_empty(s2);
    a = pop(s1);
    b = pop(s2);
    make_empty(s1);
    make_empty(s2);
    c = is_empty(s1);
    c = is_empty(s2);
    a = pop(s1);

#endif

    return 0;
}