#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define MAX_QUEUE_SIZE (5)

typedef int item;

typedef struct {
    int S_empty; // the idx of next empty slot
    int S_remove; // the idx of first slot
    int S_count; // number of slots with items in it.
    item queue_list[MAX_QUEUE_SIZE];
} Queue;

Queue initialize_queue(void);
void insert_item(Queue *q, item new_item);
void remove_item(Queue *q);
item get_first_item(Queue *q);
item get_last_item(Queue *q);
bool is_empty(Queue *q);

#endif