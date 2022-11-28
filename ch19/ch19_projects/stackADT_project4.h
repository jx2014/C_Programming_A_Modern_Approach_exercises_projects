/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackADT.h (Chapter 19, page 496) */

// Exercise 6(a):
// Add a peek runction to stackADT. c. This function will have a parameter of type
// Stack. When called. ic returns the top iten, on the stack but doesn't modify the slack.

#ifndef STACKADT_PROJECT4_H
#define STACKADT_PROJECT4_H

#include <stdbool.h>   /* C99 only */

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, void *str);
void *pop(Stack s);
void *peek(Stack s);
int length(Stack s);

#endif
