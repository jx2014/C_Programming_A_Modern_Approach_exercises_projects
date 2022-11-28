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

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
    int S_empty;
    int S_remove;
    int S_count;
    size_t size;
    Item *contents;
};

Queue create(size_t size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Unable to create new Queue.");
    }
    q->S_empty = 0;
    q->S_remove = 0;
    q->S_count = 0;
    q->contents = malloc(sizeof(Item) * size);
    if (q->contents == NULL) {
        free(q);
        terminate("Unable to create array for new Queue.");
    }
    q->size = size;;    
    return q;
}

void destroy(Queue q) {
    free(q->contents);
    free(q);
}

void insert_item(Queue q, Item new_item) {
    if (q->S_count >= q->size) {
        printf("Queue if full, unable to insert.\n");
        return;
    }

    q->contents[q->S_empty++] = new_item;
    
    // wrap around, next empty space is 0
    if ((q->S_empty) >= q->size) {
        q->S_empty = 0;
    }

    if (q->S_count < q->size) {
        q->S_count++;
    }
}

void remove_item(Queue q) {
    if (is_empty(q)) {
        printf("Queue is empty, unable to remove.\n");
        return;
    }
    q->contents[q->S_remove] = 0;
    q->S_remove++;
    q->S_count--;

    // wrap around, next empty space is 0
    if ((q->S_remove) >= q->size) {
        q->S_remove = 0;
    }
}

Item get_first_item(Queue q) {
    return q->contents[q->S_remove];
}

Item get_last_item(Queue q) {
    return q->contents[q->S_empty == 0 ? \
            q->size - 1 : q->S_empty - 1];
}

bool is_empty(Queue q) {
    return q->S_count <= 0;
}

void terminate(char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}
