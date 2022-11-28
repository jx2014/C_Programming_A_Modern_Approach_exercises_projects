#include "test_lib.h"

#include <stdio.h>
#include <stdlib.h>


struct node_main {
    int value;
    struct node_main *next;
} Node;

typedef struct type_node {
    struct node_main *node1;
    struct node_main *node2;
} *Node_Ptr;

int main() {

    Node_Ptr pNode1, pNode2;
    pNode1 = malloc(sizeof(struct type_node));
    pNode2 = malloc(sizeof(struct type_node));
    pNode1->node1 = malloc(sizeof(Node));
    pNode1->node2 = pNode1->node1;
    pNode1->node1 == pNode1->node2; // will result in 1
    
    struct node_main *a_new_node;
    a_new_node = malloc(sizeof(struct node_main));
    
    if (a_new_node == NULL) {
        printf("Unable to allocate memory for new a_new_node\n");
        exit(EXIT_FAILURE);
    }

    nodeFromLib_t *a_list, *last_item;

    // public node test
    a_list = malloc(sizeof(nodeFromLib_t));

    if (a_list == NULL) {
        printf("Unable to allocate memory for new a_new_node\n");
        exit(EXIT_FAILURE);
    }
    a_list->value = 1;

    create_node(&a_list, 2, &last_item);
    create_node(&last_item, 3, &last_item);

    // private node test
    add_private_list(1);
    add_private_list(2);
    add_private_list(3);
    nodeFromLib_t *some_list;
    some_list = get_private_list();
    add_private_list(4);
    clear_private_list();
    add_private_list(11);
    add_private_list(12);
    add_private_list(13);



    return 0;
}