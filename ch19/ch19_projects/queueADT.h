#ifndef QUEUEADT_H
#define QUEUEADT_H
#include "stdbool.h"

typedef struct queue_type *Queue;
typedef int Item;

// for project 7, size is useless.
Queue create(size_t size); 
void destroy(Queue q);
void insert_item(Queue q, Item new_item);
void remove_item(Queue q);
Item get_first_item(Queue q);
Item get_last_item(Queue q);
bool is_empty(Queue q);
void terminate(char *msg);


#endif