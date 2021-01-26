#include <graph.h>
#include <queue_array.h>
#include <binheap.h>
#include <time.h>

graph_type *build_graph(const unsigned int num_of_nodes) {
    
    graph_type *G = (graph_type *) malloc(sizeof(graph_type));

    G->lists = (list_type *) malloc(sizeof(list_type)*num_of_nodes);

    for(unsigned int v=0; v<num_of_nodes; ++v)
        memcpy(G->lists+v, build_list( build_node(v), 0 ), sizeof(list_type));
    
    G->num_of_nodes = num_of_nodes;
    return G;
}

void deallocate_graph(graph_type* G){
    free(G->lists);
    free(G);
}

void add_edge(graph_type *G, const unsigned int src, const unsigned int dest, const unsigned int w) {

    list_type *list = (G->lists+src);
    node_type *new_edge = (G->lists+dest)->node;

    while(list->next != NULL)
        list = list->next;

    list->next = build_list(new_edge, w);
}

void init_SSSP(graph_type *G) {
    node_type *node;
    for(unsigned int v=0; v<G->num_of_nodes; ++v) {
        node = (G->lists+v)->node;
        update_distance(node, UINT_MAX);
        update_predecessor(node, NULL);
    }
}

void relax(node_type *u, node_type *v, const unsigned int w) {
    if(u->distance + w < v->distance) {
        update_distance(v, u->distance + w);
        update_predecessor(v, u);
    }
}

void node_printer(const void *n) {
    node_type* node = ((list_type *)n)->node; 
    if (node->distance == UINT_MAX)
        printf("%u,inf",node->key);
    else
        printf("%u,%u",node->key, node->distance);
}

int leq_node(const void *a, const void *b) {
    return (  ((list_type *)a)->node->distance <= ((list_type *)b)->node->distance);
}

void printGraph(const graph_type *G) {

    printf("GRAPH\n");
    node_type *node;
    list_type *list;
    for (unsigned int v = 0; v < G->num_of_nodes; ++v) {
        list = (G->lists+v);
        node = list->node;
        if(node->distance == UINT_MAX)
            printf("(%u,inf)", node->key); 
        else
            printf("(%u,%u)", node->key, node->distance);
        
        list = list->next;
        while(list != NULL) {
            printf("\t->\t%u\t->\t", list->weight);
            node = list->node;
            if(node->distance == UINT_MAX)
                printf("(%u,inf)", node->key);
            else
                printf("(%u,%u)", node->key, node->distance);
            list = list->next;   
        }
        printf("\n");   
    } 
    printf("\n");
} 

void printSSSP(const graph_type *G) {

    printf("\nPRINTING PATHS FROM THE SOURCE TO ALL REACHABLE NODES\n");
    node_type *source, *predecessor;
    for (unsigned int v = 0; v < G->num_of_nodes; ++v) {
        source = (G->lists+v)->node;
        if(source->distance == UINT_MAX)
            printf("\nThe node %u is not reachable from the source\n", source->key);
        else {
            printf("\nPath to node %u in distance %u\n", source->key, source->distance);
            printf("Steps: %u", source->key);
            while(source->predecessor != NULL) {
                predecessor = source->predecessor;
                printf(" <- %u", predecessor->key);
                source = predecessor;
            }
            printf("\n");
        }
    }
}

void dijkstra_array(graph_type *G, const unsigned int source) {

    init_SSSP(G);
    update_distance((G->lists+source)->node, 0);
    queue_array *Q = build_queue(G);
    
    list_type *u, *v; 

    while(!is_empty(Q)){
        u = extract_min_queue(Q);
        v = u -> next;

        if(u->node->distance != UINT_MAX) {
            while(v != NULL) {
                relax(u->node, v->node, v->weight);
                v = v->next;
            }
        }
    }
    deallocate_queue(Q);
}

void dijkstra_heap(graph_type *G, const unsigned int source) {

    init_SSSP(G);
    
    update_distance((G->lists+source)->node, 0);
    binheap_type *Q = build_heap(G->lists, G->num_of_nodes, G->num_of_nodes, sizeof(list_type), leq_node);
    
    list_type *u, *v; 
    while(!is_heap_empty(Q)){
        u = min_value(Q);
        v = u -> next;

        if(u->node->distance != UINT_MAX) {
            while(v != NULL) {
                relax(u->node, v->node, v->weight);
                v = v->next;
            }
        }
        extract_min(Q);
    }
    delete_heap(Q);
}


/**
 * functions for testing purposes
 */
graph_type *build_random_graph(const unsigned int num_of_nodes){
    
    graph_type *G = build_graph(num_of_nodes); 

    srand(10);
    unsigned int w;
    for(size_t i = 0; i < num_of_nodes; ++i){
        for(size_t j = 0; j < num_of_nodes; ++j){

            w = rand(); // random weight between 0 and RAND_MAX
            if(w > RAND_MAX*0.4)
                add_edge(G, i, j, w);
        }
    }
    return G;
}

double test(void (*func)(graph_type *, const unsigned int), graph_type *G, const unsigned int source){
    
    struct timespec requestStart, requestEnd;
    double accum;
    size_t rep = 10;

    clock_gettime(CLOCK_REALTIME, &requestStart);
    for(size_t i = 0; i < rep; ++i){
        func(G, source);
    }
    clock_gettime(CLOCK_REALTIME, &requestEnd);

    accum = (requestEnd.tv_sec - requestStart.tv_sec) + 
            (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  return accum / rep;
}
