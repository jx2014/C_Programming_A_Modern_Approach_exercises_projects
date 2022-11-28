/******************************************************************
* ch19_exercise3.c: This program is created to test drive queue.c *
******************************************************************/


#include <stdio.h>
#include "queue.h"

int main(void) {

    
    item a, b;

    insert_item(1);
    insert_item(2);
    insert_item(3);
    insert_item(4);
    insert_item(5);
    insert_item(6);
    insert_item(7);
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    insert_item(8);
    remove_item();
    remove_item();
    remove_item();
    insert_item(1);
    insert_item(2);
    insert_item(3);
    if (!is_empty()) {
        a = get_first_item();
        b = get_last_item();
    }
    remove_item();
    insert_item(3);
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    remove_item();
    if (!is_empty()) {
        a = get_first_item();
        b = get_last_item();
    }
    
    return 0;
}
