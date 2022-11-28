/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackclient.c (Chapter 19, page 494) */

// Ch19 Project 3
// Add 'int len' to stack_type to keep track how many items are currently stored in 
// a stack. Add new function length that has a Stack parameter and returns the value
// of the len member. 

// Ch19 Project 4
// Item type is no longer used. Instead, a stack stores void * as described in 
// section 19.5.

#include <stdio.h>
#include "stackADT_project4.h"

int main(void)
{
  Stack s1, s2;
  char *n;

  s1 = create();
  s2 = create();

  push(s1, "abcdefg");
  printf("Stack length: %d\n", length(s1));
  push(s1, "hijklmnop");
  printf("Stack length: %d\n", length(s1));

  n = pop(s1);
  printf("Popped %s from s1\n", n);
  printf("Stack length: %d\n", length(s1));

  push(s2, n);
  printf("Stack length: %d\n", length(s2));
  
  n = pop(s1);
  printf("Popped %s from s1\n", n);
  printf("Stack length: %d\n", length(s1));
  
  push(s2, n);
  printf("Stack length: %d\n", length(s2));

  destroy(s1);

  while (!is_empty(s2)){
    printf("Popped %s from s2\n", pop(s2));
    printf("Stack length: %d\n", length(s2));
  }

  push(s2, "ABCDEFG");
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}
