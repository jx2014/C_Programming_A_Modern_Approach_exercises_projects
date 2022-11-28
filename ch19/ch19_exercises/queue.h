#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int item;

void insert_item(item new_item);
void remove_item(void);
item get_first_item(void);
item get_last_item(void);
bool is_empty(void);

#endif