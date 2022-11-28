#include "test_lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

nodeFromLib_t *private_list;
nodeFromLib_t *private_list_last_item;

typedef struct {
    size_t num_nodes;
    nodeFromLib_t *first;
} NodeList_t;

NodeList_t a_list;


void create_node(nodeFromLib_t** current_node, int value, nodeFromLib_t** last_node) {
    (*current_node)->next = malloc(sizeof(nodeFromLib_t));
    if ((*current_node)->next == NULL) return;
    *last_node = (*current_node)->next;
    (*last_node)->value = value;
    (*last_node)->next = NULL; 
}

// experiment to create and modify private nodes (main() has no visibility of this node)
void init_private_node(int n) {
    a_list.first = malloc(sizeof(nodeFromLib_t));
    if (a_list.first == NULL) {
        printf("Failed to initialize.\n");        
    } else {
        a_list.first->value = n;
        a_list.first->next = NULL;
        private_list_last_item = a_list.first;
        a_list.num_nodes++;
    }
}

void add_private_list(int n) {
    if (a_list.num_nodes > 0) {
        private_list_last_item->next = malloc(sizeof(nodeFromLib_t));
        if (private_list_last_item->next == NULL) {
            printf("Failed to initialize.\n");
        } else {
            private_list_last_item->next->value = n;
            private_list_last_item->next->next = NULL;
            private_list_last_item = private_list_last_item->next;
            a_list.num_nodes++;
        }
    } else {
        init_private_node(n);
    }
}

nodeFromLib_t* get_private_list(void) {
    return private_list;
}

void clear_private_list(void) {
    nodeFromLib_t *p, *q;
    p = a_list.first;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    a_list.num_nodes = 0;
    a_list.first = NULL;

}
