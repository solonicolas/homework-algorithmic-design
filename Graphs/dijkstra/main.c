#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/graph.h"

int main()
{   
    // generation of random big graphs and timing
    printf("\nn.\tdijkstra_array\tdijkstra_heap\n");
    size_t n = 1 << 12;
    graph_type *G1, *G2;
    for (size_t i = 2; i <= n; i *= 2) {

        printf("%ld\t", i);
        fflush(stdout);
        
        G1 = build_random_graph(i);
        G2 = build_random_graph(i);

        printf("%f\t", test(dijkstra_array, G1, 0));
        fflush(stdout);
        printf("%f\n", test(dijkstra_heap, G2, 0));
        fflush(stdout);
        
        deallocate_graph(G1);
        deallocate_graph(G2);
    }
    
    return 0;
}



