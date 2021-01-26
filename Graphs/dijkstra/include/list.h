#ifndef __LIST__
#define __LIST__

#include <node.h>

typedef struct {
    node_type *node; // current node
    struct list_type *next; // pointer to the next node in the adj_list
    unsigned int weight;    // weight of the edge
} list_type;

list_type *build_list(node_type *node, const unsigned int w);

void update_weight(list_type *list, const unsigned int w);

void swap_lists(list_type* n1, list_type* n2);

#endif // __LIST__