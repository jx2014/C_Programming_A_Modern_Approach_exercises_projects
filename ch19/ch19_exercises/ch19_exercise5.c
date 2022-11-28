/*****************************************************************
* ch19_exercise5.c: This program is created to test drive        *
*                  queue_exercise5.c                             *
******************************************************************/


#include <stdio.h>
#include "queue_exercise5.h"

int main(void) {

    
    item a, b;
    Queue q1 = initialize_queue(), q2;

    insert_item(&q1, 1);
    insert_item(&q1, 2);
    insert_item(&q1, 3);
    insert_item(&q1, 4);
    insert_item(&q1, 5);
    insert_item(&q1, 6);
    insert_item(&q1, 7);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    insert_item(&q1, 8);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    insert_item(&q1, 1);
    insert_item(&q1, 2);
    insert_item(&q1, 3);
    if (!is_empty(&q1)) {
        a = get_first_item(&q1);
        b = get_last_item(&q1);
    }
    remove_item(&q1);
    insert_item(&q1, 3);
    insert_item(&q2, 3);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    remove_item(&q1);
    if (!is_empty(&q1)) {
        a = get_first_item(&q1);
        b = get_last_item(&q1);
    }
    
    return 0;
}
