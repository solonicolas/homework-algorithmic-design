#ifndef __NODE__
#define __NODE__

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int key;               // unique value to identify the node
    struct node_type *predecessor;  // predecessor in the path from a source node
    unsigned int distance;          // candidate distance for the dijkstra algorithm
} node_type;

node_type *build_node(const unsigned int key);

void update_distance(node_type *node, const unsigned int d);

void update_predecessor(node_type *node, const node_type *p);

#endif // __NODE__