/******************************************************************
* queue.c: Circular queue implemented with array. When S_empty    *
*          and S_Remove are equal, the entire queue is counted    *
*          as empty (in a proper implementation of queue, when    *
*          S_empty == S_remove, the queue's status of being       *
*          empty or being full depends on the last action, e.g.,  *
*          if the last action is to remove, i.e., S_remove        *
*          advances and becomes equal to S_empty, then the queue  *
*          is empty. Otherwise, if the last action is to insert,  *
*          and S_empty advances and becomes equal to S_remove,    *
*          then the queue is full, S_count == MAX_QUEUE_SIZE).    *
*                                                                 *
*          Examples:                                              *
*                                                                 *
*          Case I:                                                *
*                                                                 *
*          S_empty = 3 (empty slot)                               * 
*          S_remove = 0 (slot to remove)                          *
*                                                                 *
*            0   1   2   3   4                                    *
*          |   |   |   | x |   |                                  *
*                        !   ^                                    *
*          Action: remove()                                       *
*            0   1   2   3   4                                    *
*          |   |   |   |   |   |                                  *
*                            !^                                   *           
*          The queue is empty. S_count == 0                       *
*                                                                 *
*          Case II:                                               *     
*                                                                 *
*          S_empty = 4, S_remove = 0                              *
*                                                                 *
*            0   1   2   3   4                                    *
*          | x | x | x | x |   |                                  *                         
*            !               ^                                    *
*                                                                 *
*          Action: insert()                                       *
*            0   1   2   3   4                                    *
*          | x | x | x | x | x |                                  *
*            ^!                                                   *
*          The queue is full, S_count == MAX_QUEUE_SIZE           *
*                                                                 *
*          Legends:  ! is S_remove,  ^ is S_empty                 *
*                                                                 *
******************************************************************/


#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG (0)
#define PUBLIC // empty
#define PRIVATE static
#define MAX_QUEUE_SIZE (5)

typedef struct node {
    item data;
    struct node *next;
} node;

PRIVATE node *S_remove = NULL;
PRIVATE node *S_empty = NULL;

PRIVATE int S_count = 0;

void insert_item(item new_item) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Unable to create new node, do nothing.\n");
        return;
    }
    new_node->data = new_item;    

    // Needd to initialize for first node
    if (S_count == 0) {
        S_empty = new_node;
        S_remove = S_empty;
    }    
    else {
        S_empty->next = new_node;
        S_empty = new_node;
    }    
    S_count++;
}

void remove_item(void) {

    if (is_empty()) {
        printf("Empty queue, nothing to remove.\n");
        return;
    }

    node *temp = S_remove;    
    S_remove = S_remove->next;
    free(temp);
    S_count--;
}

item get_first_item(void) {
    return S_remove->data;
}

item get_last_item(void) {
    return S_empty->data;
}

bool is_empty(void) {
    return (S_count == 0);
}