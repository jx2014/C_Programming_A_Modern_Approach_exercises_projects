#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int contents[100];
int top = 0;

void make_empty(void) {
    top = 0;
}

int is_empty(void) {
    return (top == 0);
}

int is_full(void) {
    return (top == 100);
}

void push(int i) {
    if (is_full()) {
        printf("Expression is too complex.\n");
        exit(EXIT_FAILURE);
    } else {
        contents[top] = i;
        top++;
    }
}

int pop(void) {
    if (is_empty()) {
        printf("Not enough operands in expression.\n");
        exit(EXIT_FAILURE);
    } else {            
        return contents[--top];
    }
}