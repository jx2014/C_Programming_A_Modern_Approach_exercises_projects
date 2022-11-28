#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// int contents[100];
// int top = 0;
struct node *expression_list = NULL;

void make_empty(void) {
    struct node *temp;
    for (; expression_list != NULL;) {
        temp = expression_list;
        expression_list = expression_list->next;
        free(temp); // free previous node
    }
}

int is_empty(void) {
    return (expression_list == NULL);
}

int push(int i) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {        
        return 0;
    } else {
        new_node->value = i;
        new_node->next = expression_list;
        expression_list = new_node;
        return 1;
    }
}

int pop(void) {
    int value;
    struct node *temp;
    if (is_empty()) {
        printf("Not enough operands in expression.\n");
    } else {
        temp = expression_list;
        value = expression_list->value;
        expression_list = expression_list->next;
        free(temp);
        return value;
    }
}