#include "insertion_sort.h"
#include "swap.h"

void insertion_sort(void *A, const unsigned int n, const size_t elem_size, total_order leq)
{
    unsigned int j, i;
    for(i = 1; i<n; ++i) {
        j = i;
        while(j > 0 && leq(A+j*elem_size,A+(j-1)*elem_size)) {
            swap(A+(j-1)*elem_size, A+j*elem_size, elem_size);
            --j;
        }
    } 
}