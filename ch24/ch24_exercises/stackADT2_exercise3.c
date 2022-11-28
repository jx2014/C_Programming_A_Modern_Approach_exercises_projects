/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackADT2.c (Chapter 19, page 498) */

// Exercise 6(b):
// Add a peek runction to stackADT2. c. This function will have a parameter of type
// Stack. When called, it returns the top iten on the stack but doesn't modify the slack.

// Exercise 7:
// The stack will automatically doubles in size when it becomes full. 
// The push function dynamically allocate a new array that's twice as large as the old one
// and then copy the stack contents from the old array to the new one. Then deallocate the
// old array once the data has been copied. 

// Chapter 24 exercise 3.
// Using assert instead of if statement to check for errors.
// Modified from stackADT2_exercise7.c from chapter 19

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

#define ARRAY_INCREMENT (2)

struct stack_type {
  Item *contents;
  int top;
  int size;
};

// with the use of assert, terminate is no longer needed.
static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(int size)
{
  Stack s = malloc(sizeof(struct stack_type));
  assert(s != NULL);
  /*
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  */
  s->contents = malloc(size * sizeof(Item));

  assert(s->contents != NULL);
  /*
  if (s->contents == NULL) {
    free(s);
    terminate("Error in create: stack could not be created.");
  }
  */
  s->top = 0;
  s->size = size;
  return s;
}

void destroy(Stack s)
{
  free(s->contents);
  free(s);
}

void make_empty(Stack s)
{
  s->top = 0;
}

bool is_empty(Stack s)
{
  return s->top == 0;
}

bool is_full(Stack s)
{
  return s->top == s->size;
}

void push(Stack s, Item i)
{
  if (is_full(s)) {
    // terminate("Error in push: stack is full.");
    // if use realloc, then no need to call free() later on.
    // Item *temp = realloc(s->contents, (s->size)*2*sizeof(Item));

    // using malloc and free()
    Item *temp = malloc(sizeof(Item) * ((s->size) + ARRAY_INCREMENT)); 
    /*
    if (temp == NULL)
        terminate("Error in push: stack is full and is not able to acquire additional memory.");
    */
    assert(temp != NULL);
    // the following two lines are only required if using malloc.
    // copy over the content from the old array to the new array
    for (int i=0; i< s->size; i++) {
       temp[i] = (s->contents)[i];       
    }
    free(s->contents);      // free the location pointed by s->contents.

    s->contents = temp;
    s->size += ARRAY_INCREMENT;
  }
  s->contents[s->top++] = i;
}

Item pop(Stack s)
{
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
  return s->contents[--s->top];
}

Item peek(Stack s) {
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
  return s->contents[(s->top) - 1];
}