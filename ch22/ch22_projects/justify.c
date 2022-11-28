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

// chapter 22 project 15
// modify justify.c from Section 15.3 so that it reads from one text file
// and writes to another. The program will obtain the names of both files
// from the command line

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
  char word[MAX_WORD_LEN+2];
  int word_len;
  FILE *fp_in, *fp_out;

    if (argc != 3) {
        fprintf(stderr, "Usage: justify.exe input.txt output.txt");
        exit(EXIT_FAILURE);
    }

    if ((fp_in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
        
    if ((fp_out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Unable to create file %s.\n", argv[2]);
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }
 
  while (!feof(fp_in) && !ferror(fp_in)) {
    read_word(fp_in, word, MAX_WORD_LEN+1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(fp_out);
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(fp_out);
      clear_line();
    }
    add_word(word);
  }
  
}
