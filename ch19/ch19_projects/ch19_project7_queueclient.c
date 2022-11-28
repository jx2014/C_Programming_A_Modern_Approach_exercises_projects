/******************************************************************
* queueclient: Ch19 Project 5. Using a type *Queue to create      *
*              queue object. The *Queue type is an arbitrary      *
*              type. The queue.h and queue.c are modified to      *
*              inlucde the usage of this arbitrary type.          *
*              Project 6, the create function takes an integer    *
*              and dynamically allocate memory for the array.     *
******************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdbool.h>
#include <crtdbg.h>
#include "queueADT.h"

int main(void) {

    Queue q1 = create(0);
    Queue q2 = create(0);
    Item a, b;

    
    insert_item(q1, 1);
    insert_item(q1, 2);
    insert_item(q1, 3);
    insert_item(q1, 4);
    insert_item(q1, 5);
    insert_item(q1, 6);
    insert_item(q1, 7);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    insert_item(q1, 8);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    insert_item(q1, 1);
    insert_item(q1, 2);
    insert_item(q1, 3);
    if (!is_empty(q1)) {
        a = get_first_item(q1);
        b = get_last_item(q1);
    }
    remove_item(q1);
    insert_item(q1, 3);
    insert_item(q2, 3);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    remove_item(q1);
    if (!is_empty(q1)) {
        a = get_first_item(q1);
        b = get_last_item(q1);
    }
    insert_item(q1, 1);
    insert_item(q1, 2);
    insert_item(q1, 3);
    destroy(q1); //TODO: need to verify
    
    int c;
     c = _CrtDumpMemoryLeaks();
    return 0;
}

