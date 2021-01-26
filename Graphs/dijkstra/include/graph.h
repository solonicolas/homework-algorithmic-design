#ifndef __GRAPH__
#define __GRAPH__

#include <list.h>

typedef struct {
    list_type *lists; // array of adjacency lists
    unsigned int num_of_nodes;
} graph_type;

graph_type *build_graph(const unsigned int num_of_nodes);

void deallocate_graph(graph_type* G);

void add_edge(graph_type *G, const unsigned int src, const unsigned int dest, const unsigned int w);

void dijkstra_array(graph_type *G, const unsigned int source);

void dijkstra_heap(graph_type *G, const unsigned int source);

// functions for printing purposes
void printGraph(const graph_type *G);
void printSSSP(const graph_type *G);

// functions for testing purposes
graph_type *build_random_graph(const unsigned int num_of_nodes);
double test(void (*dunc)(graph_type *, const unsigned int), graph_type *G, const unsigned int source);

#endif // __GRAPH__