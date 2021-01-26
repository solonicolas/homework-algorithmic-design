#include <queue_array.h>

queue_array *build_queue(graph_type *G) {

    queue_array *Q = (queue_array *) malloc(sizeof(queue_array));
    Q->nodes = G->lists;
    Q->num_of_elem = G->num_of_nodes;
    
    return Q;
}

void deallocate_queue(queue_array *Q) {
    free(Q);
}

int is_empty(const queue_array *Q) {
    return (Q->num_of_elem == 0);
}


list_type *extract_min_queue(queue_array *Q) {

    list_type *min_list = Q->nodes;
    list_type *candidate_list;
    
    
    for(unsigned int v=1; v<Q->num_of_elem; ++v) {
        candidate_list = Q->nodes+v;
        if(candidate_list->node->distance <= min_list->node->distance) {
            min_list = candidate_list;
        }
    }
    
    swap_lists( min_list, (Q->nodes)+(Q->num_of_elem-1) ); // put the minimum element in the last position
    Q->num_of_elem--;

    return (Q->nodes)+(Q->num_of_elem); // return the last element
}