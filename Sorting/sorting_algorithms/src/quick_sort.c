#include "quick_sort.h"
#include "swap.h"

int partition (void *A, const unsigned int  l, const unsigned int  r, const unsigned int  p,
                                const size_t elem_size, total_order leq)
{   
    swap(A+l*elem_size, A+p*elem_size, elem_size);

    unsigned int pp = l;
    unsigned int ll = l+1;
    unsigned int rr = r;

    while(ll <= rr) {
        if (leq(A+ll*elem_size, A+pp*elem_size)) {
            ++ll;
        } else {
            swap(A+ll*elem_size, A+rr*elem_size, elem_size);
            --rr;
        }
    }
    swap(A+pp*elem_size, A+rr*elem_size, elem_size); 

    return rr;
} 

void quick_sort_rec(void *A, const unsigned int  l, const unsigned int  r, 
                                const size_t elem_size, total_order leq) 
{ 
    if (l < r) { 
        unsigned int p = partition(A, l, r, l, elem_size, leq);  
        if(p != l)
            quick_sort_rec(A, l, p-1, elem_size, leq); 
        if(p != r)   
            quick_sort_rec(A, p+1, r, elem_size, leq); 
    }
} 

void quick_sort(void *A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq)
{
    quick_sort_rec(A, 0, n-1, elem_size, leq);
}