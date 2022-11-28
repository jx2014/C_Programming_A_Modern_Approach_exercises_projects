/*********************************************************
 * Ch19 Exercise 4, header file for part (b),            *
 * implementing stack type using linked-list             *
 * representation.                                       *
 *********************************************************/

#ifndef STACK_EXERCISE4B_H
#define STACK_EXERCISE4B_H

#define PUBLIC
#define PRIVATE static

#include <stdbool.h>   /* C99 only */

/*
PUBLIC typedef struct node {
    int data;
    struct node* next;
} Stack;
*/

// book answer:
PUBLIC typedef struct node {
    int data;
    double data2;
    long long data3;
    long long data4;
    long double data5;
    struct node* next;
} *Stack;

//typedef struct node *Stack;

PRIVATE void terminate(const char *message);
PUBLIC void create_stack(Stack *s);
PUBLIC void make_empty(Stack *s);
PUBLIC bool is_empty(const Stack *s);
PUBLIC bool is_full(const Stack *s);
PUBLIC void push(Stack *s, int i);
PUBLIC int pop(Stack *s);

#endif
