#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);

#endif