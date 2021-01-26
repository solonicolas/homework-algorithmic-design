#include <node.h>

node_type *build_node(const unsigned int key) {
    
    node_type *node = (node_type *) malloc(sizeof(node_type));
    node->key = key;
    node->distance = UINT_MAX;
    node->predecessor = NULL;
	return node;
}

void update_distance(node_type *node, const unsigned int d) {
    node->distance = d;
}

void update_predecessor(node_type *node, const node_type *p) {
    node->predecessor = p;
}
