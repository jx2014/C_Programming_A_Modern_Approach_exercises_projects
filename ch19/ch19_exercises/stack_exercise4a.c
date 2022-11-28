/****************************************************
 * Ch19 Exercise 4 part (a).                        *
 *                                                  *
 * Write an implementation of the stack type,       *
 * assuming that Stack is a structure containing a  *
 * fixed-length array.                              *
 * *************************************************/

#include "stack_exercise4a.h"
#include <stdio.h>
#include <stdlib.h>

// book answer:
static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

/*

#include <stdlib.h>
bool create_stack(Stack **s) {
    (*s) = malloc(sizeof(Stack));
    return !((*s) == NULL);
}
*/


void make_empty(Stack *s) {
    s->top = 0;
}

bool is_empty(const Stack *s) {
    return (s->top <= 0);
}

bool is_full(const Stack *s) {
    return (s->top >= MAX_STACK_SIZE);
}

void push(Stack *s, int i) {
    if (is_full(s)){
        terminate("Failed to push, Stack is full.");
    } else {        
        (s->contents)[s->top++] = i;
    }
}

int pop(Stack *s) {
    if (is_empty(s))
        terminate("Stack is empty.");
    return (s->contents)[--(s->top)];
}
