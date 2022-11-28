/*********************************************************
 * Ch19 Exercise 4, header file for part (a),            *
 * implementing stack type using fixed-length array.     *
 *********************************************************/

#ifndef STACK_EXERCISE4A_H
#define STACK_EXERCISE4A_H

#include <stdbool.h>   /* C99 only */

#define MAX_STACK_SIZE (10)

typedef struct {
    int top;
    int contents[MAX_STACK_SIZE];
} Stack;

//bool create_stack(Stack **s);
void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);

#endif
