#ifndef __QUEUE_ARRAY__
#define __QUEUE_ARRAY__

#include <graph.h>

typedef struct {
    list_type *nodes;         // this is the array used to represent the priority queue
    unsigned int num_of_elem; // this is the number of elements of the queue
} queue_array;

queue_array *build_queue(graph_type *G);

void deallocate_queue(queue_array *Q);

int is_empty(const queue_array *Q);

list_type *extract_min_queue(queue_array *Q);

#endif // __QUEUE_ARRAY__