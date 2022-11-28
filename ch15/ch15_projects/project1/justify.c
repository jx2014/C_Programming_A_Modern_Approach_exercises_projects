/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */

#include <stdio.h>
#include <string.h>
#include "line.h"
#include "word.h"
#include <stdlib.h>

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
  char word[MAX_WORD_LEN+2];
  int word_len;
  // printf("Enter : ");

  // testing the ability to pass argument
  // to cmake debugger 
/*   printf("argument used: %d\n", argc);
  if (argc <= 1) {
    printf("Need some arguments.\n");
    return EXIT_FAILURE;
  } else {
    for(int i = 0; i < argc; i++) {
      printf("argv[%d]: %s\n", i, argv[i]);
    }
  } */


  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN+1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }
}
