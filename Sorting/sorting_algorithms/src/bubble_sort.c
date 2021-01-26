#include "bubble_sort.h"
#include "swap.h"

void bubble_sort(void *A, const unsigned int n, 
                 const size_t elem_size, 
                 total_order leq)
{
    unsigned int i,j; 
    for(i = n-1; i > 0; --i) {  
        for (j = 0; j < i; ++j) {
            if (leq(A+(j+1)*elem_size,A+j*elem_size)) 
                swap(A+j*elem_size, A+(j+1)*elem_size, elem_size);
        }     
    } 
}