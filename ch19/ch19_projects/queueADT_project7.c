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

// Ch19 Project 7. Using linked-list instead of array

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

typedef struct node {
    Item data;
    struct node *next;
} *Node;

struct queue_type {
    Node S_empty;
    Node S_remove;
    int S_count;
    // size_t size; // size is useless, technically, unlimited size.     
};

/* size is not used for project 7 */
Queue create(size_t size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Unable to create new Queue.");
    }
    q->S_empty = NULL;
    q->S_remove = NULL;
    q->S_count = 0;   
    return q;
}

void destroy(Queue q) {
    Node temp = q->S_empty; 
    while (temp != NULL) {
        // calling remove to remove each item is very expensive.
        // remove_item(q);
        q->S_empty = q->S_empty->next;
        free(temp);
        temp = q->S_empty;
    }
    // at this point, both q->remove and q->next should be 
    // pointing at the same address.
    // q->remove == q->next;
    free(q);
}

void insert_item(Queue q, Item new_item) {

    Node temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Unable to insert more items.\n");
    } else {
        temp->next = q->S_empty;
        temp->data = new_item;
        q->S_empty = temp;
        q->S_count++;
        if (q->S_count == 1)
            q->S_remove = temp;
    }
}

void remove_item(Queue q) {    
    if (is_empty(q)) {
        printf("Queue is empty. There is nothing to remove.\n");
        return;
    }
    Node temp = q->S_empty;

    while ((temp->next != NULL) && (temp->next != q->S_remove)) {
        //q->S_remove = q->S_remove->next;
        temp = temp->next;
    }
    free(q->S_remove);
    q->S_count--;
    if (q->S_count == 0) {
        q->S_remove = NULL;
        q->S_empty = NULL;
    } else {
        q->S_remove = temp;
        q->S_remove->next = NULL;
    }    
}

Item get_first_item(Queue q) {
    return q->S_remove->data;
}

Item get_last_item(Queue q) {
    return q->S_empty->data;
}

bool is_empty(Queue q) {
    return (q->S_count <= 0 && (q->S_empty == q->S_remove));
}

void terminate(char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}
