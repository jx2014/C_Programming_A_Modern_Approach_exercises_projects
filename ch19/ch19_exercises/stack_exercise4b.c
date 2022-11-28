/****************************************************
 * Ch19 Exercise 4 part (b).                        *
 *                                                  *
 * Write an implementation of the stack type, using *
 * linked-list representation.                      *
 * *************************************************/

#include "stack_exercise4b.h"
#include <stdio.h>
#include <stdlib.h>

PRIVATE void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC void create_stack(Stack *s) {
    // incorrect version:
    (*s) = malloc(sizeof(Stack));
    // correct version:
    // (*s) = malloc(sizeof(struct node));
    if ((*s) == NULL)
        terminate("Unable to create a pointer to stack");
    (*s) = NULL; // need to initialize the first node.
}

PUBLIC void make_empty(Stack *s) {    
    while (!is_empty(s))
        pop(s);
}

PUBLIC bool is_empty(const Stack *s) {
    return (*s == NULL);
}

PUBLIC bool is_full(const Stack *s) {
    return false;
}

PUBLIC void push(Stack *s, int i) {
    //Stack new_node = malloc(sizeof(struct node));
    // incorrect:
    Stack new_node = malloc(sizeof(Stack));

    // book answer:
    // struct node *new_node2 = malloc(sizeof(struct node));
    // sizeof(new_node2) is the same as sizeof(new_node)
    if (new_node == NULL) {
        terminate("Unable to allocate memory for Stack.\n");
    }        
    new_node->data = i;
    new_node->next = *s;
    *s = new_node;
}

PUBLIC int pop(Stack *s) {
    if (is_empty(s))
        terminate("Stack is empty.");
    int value = (*s)->data;
    Stack temp_node = *s;
    *s = (*s)->next;
    free(temp_node);
    return value;    
}
