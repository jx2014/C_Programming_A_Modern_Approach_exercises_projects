/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

typedef struct word {
  char word[MAX_WORD_LEN];
  struct word *next;
} Word_t;

typedef struct {
  size_t num_words;
  size_t line_len;
  Word_t* first_word;
} Line_t;

Line_t line = {.num_words = 0, .line_len=0, .first_word = NULL};
Word_t *last_word;

void clear_line(void)
{
  Word_t *p = line.first_word, *q;  
  while (p != NULL) {   
    q = p;
    p = p->next;
    free(q);    
  }
  line.num_words = 0;
  line.line_len = 0;
  line.first_word = NULL;
}

void add_word(const char *word) {
  Word_t *new_word;
  new_word = malloc(sizeof(Word_t));
  if (new_word == NULL) {
    printf("Unable to allocate new memory for new_word.\n");
    return;
  }

  new_word->next = NULL;
  //memset(new_word->word, '\0', sizeof(new_word->word));
  new_word->word[0] = '\0';
  strcat(new_word->word, word);

  if (line.num_words == 0) {
    line.first_word = new_word;
  } else {
    line.line_len++; // adding ' ' to line_len.
    last_word->next = new_word;      
  }
  line.num_words++;
  line.line_len += strlen(word);  
  last_word = new_word;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line.line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line.line_len;
  Word_t *p = line.first_word;
  for (i = 0; i < line.num_words; i++) {
    //if (line[i] != ' ')
    if (p != NULL) {
      //putchar(line[i]);
      fputs(p->word, stdout);    
      spaces_to_insert = extra_spaces / (line.num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
    }
    p = p->next;
  }
  putchar('\n');
}

void flush_line(void)
{ 
  if (line.line_len > 0) {
    write_line();
  }
}
