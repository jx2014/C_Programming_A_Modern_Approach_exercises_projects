/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackADT3.c (Chapter 19, page 500) */

// Exercise 6(c):
// Add a peek runction to stackADT3.c. This function will have a parameter of type
// Stack. When called, it returns the top iten on the stack but doesn't modify the slack.

// Ch19 Project 3
// Add 'int len' to stack_type to keep track how many items are currently stored in 
// a stack. Add new function length that has a Stack parameter and returns the value
// of the len member. 

#include <stdio.h>
#include <stdlib.h>
#include "stackADT_project4.h"

struct node {
  void *data;
  struct node *next;
};

struct stack_type {
  int len;
  struct node *top;
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(void)
{
  // Stack s = malloc(sizeof(struct stack_type));
  Stack s = malloc(sizeof(Stack));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->top = NULL;
  s->len = 0;
  return s;
}

void destroy(Stack s)
{
  make_empty(s);
  free(s);
}

void make_empty(Stack s)
{
  while (!is_empty(s))
    pop(s);
}

bool is_empty(Stack s)
{
  return s->top == NULL;
}

bool is_full(Stack s)
{
  return false;
}

void push(Stack s, void *str)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    terminate("Error in push: stack is full.");

  new_node->data = str;
  new_node->next = s->top;
  s->top = new_node;
  s->len++;
}

void *pop(Stack s)
{
  struct node *old_top;
  void *i;

  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  old_top = s->top;
  i = old_top->data;
  s->top = old_top->next;
  s->len--;
  free(old_top);
  return i;
}

void *peek(Stack s) {
    if (is_empty(s))
      terminate("Error in pop: stack is empty.");
  return s->top->data;

}

int length(Stack s) {
    return s->len;
}