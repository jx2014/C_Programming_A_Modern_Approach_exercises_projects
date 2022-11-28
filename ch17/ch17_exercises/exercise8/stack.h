#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};



int push(int n);
int pop(void);
void make_empty(void);
int is_empty(void);

//void make_empty(void);
//int is_empty(void);
//int is_full(void);
//int push(int i);
//int pop(void);



#endif