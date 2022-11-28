#ifndef TEST_LIB_H
#define TEST_LIB_H

typedef struct node_lib {
    int value;
    struct node_lib *next;
} nodeFromLib_t;



// this function works to create a new node from current_node,
// then save the new node address to last node, and modify the value
// in the last node.
// i.e., create_node will append the new node to the last node. 
void create_node(nodeFromLib_t** current_node, int value, nodeFromLib_t** last_node);

// experiment to create and modify private nodes (main() has no visibility of this node)
void init_private_node(int n);
void add_private_list(int n);
nodeFromLib_t* get_private_list(void);
void clear_private_list(void);

#endif