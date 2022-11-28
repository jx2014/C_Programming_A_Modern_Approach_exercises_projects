/******************************************************************
* queue_exercise5.c                                               *
*          Modify queue.h, using a Queue type for a fixed-length  *
*          array.                                                 *
*          Circular queue implemented with array. When S_empty    *
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


#include "queue_exercise5.h"
#include <stdbool.h>
#include <stdio.h>

#define DEBUG (1)
#define PUBLIC // empty
#define PRIVATE static


// PRIVATE item queue_list[MAX_QUEUE_SIZE];

// S_empty - 1 is always the last item.
// S_remove always points to the first item.
/*
PRIVATE int S_empty = 0, \
            S_remove = 0,\
            S_count = 0;
*/

PUBLIC Queue initialize_queue(void) {
    Queue new_queue = {.S_empty = 0,  \
                       .S_remove = 0, \
                       .S_count = 0,  \
                       .queue_list = {0}};
    return new_queue;
}

PUBLIC void insert_item(Queue *q, item new_item) {
    // queue is full, unable to insert
    // Technically, S_count will never be > MAX_QUEUE_SIZE
    if (q->S_count >= MAX_QUEUE_SIZE) {
        printf("Queue is full, unable to insert.\n");
        return;
    }

    q->queue_list[q->S_empty++] = new_item;

    // wrap around, next empty space is 0
    if (q->S_empty >= MAX_QUEUE_SIZE) {
        q->S_empty = 0;
    }

    if (q->S_count < MAX_QUEUE_SIZE)
        q->S_count++;
}

PUBLIC void remove_item(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty, unable to remove.\n");
        return;
    }

    // technically, there is no need to set the slot to 0
    // after removal. 
    #if DEBUG
    q->queue_list[q->S_remove] = 0;
    #endif
    
    q->S_remove++;
    q->S_count--;
    // wrap around, next empty space is 0
    if (q->S_remove >= MAX_QUEUE_SIZE) {
        q->S_remove = 0;
    }
}

PUBLIC bool is_empty(Queue *q) {
    return (q->S_count <= 0);
}

PUBLIC item get_first_item(Queue *q){
    return q->queue_list[q->S_remove];
}

PUBLIC item get_last_item(Queue *q){
    return q->queue_list[q->S_empty == 0 ?  \
            MAX_QUEUE_SIZE - 1 :            \
            q->S_empty-1];
}