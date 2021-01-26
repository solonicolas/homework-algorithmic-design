#include "heap_sort.h"
#include "binheap.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void heap_sort(void *A, const unsigned int n, 
               const size_t elem_size, 
               total_order leq)
{
    binheap_type *maxH = build_heap(A, n, n, elem_size, geq_int);

    for(unsigned int i = n-1; i >0; --i) {
        extract_min(maxH);
    }
    delete_heap(maxH);
}