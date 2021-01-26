#include "select.h"
#include "swap.h"
#include <stdio.h>

// selection_sort
void sort(void *A,
          const unsigned int l,
          const unsigned int r,
          const size_t elem_size, 
          total_order leq)
{
    unsigned int i, j, max_j;   
    for (i = r; i > l; --i) {   
        max_j = l;  
        for (j = l+1; j <= i; ++j) {
            if (leq(A+max_j*elem_size, A+j*elem_size))  
                max_j = j; 
        } 
        swap(A+max_j*elem_size,A+i*elem_size, elem_size);  
    }  
}

// struct used for the three_way_partition
struct pivots {
    unsigned int lt;
    unsigned int gt;
};

struct pivots three_way_partition (void *A, const unsigned int  l, const unsigned int  r, const unsigned int  p,
                                const size_t elem_size, total_order leq)
{   
    swap(A+p*elem_size, A+l*elem_size, elem_size);

    unsigned int pp = l;
    unsigned int lt = l+1;
    unsigned int i = l+1;
    unsigned int gt = r;

    while(i <= gt) {
        if (leq(A+i*elem_size, A+pp*elem_size) && leq(A+pp*elem_size, A+i*elem_size)) {
            ++i;
        } else if (leq(A+i*elem_size, A+pp*elem_size)){
            swap(A+lt*elem_size, A+i*elem_size, elem_size);
            ++lt;
            ++i;
        } else {
            swap(A+i*elem_size, A+gt*elem_size, elem_size);
            --gt;
        }
    }
    
    swap(A+pp*elem_size, A+gt*elem_size, elem_size);
    struct pivots piv = {lt,gt};
    return piv;
}

unsigned int select_pivot(void *A,
                          const unsigned int  l,
                          const unsigned int  r,
                          const size_t elem_size, 
                          total_order leq)
{
    if(r-l<10) {
        sort(A, l, r, elem_size, leq);
        return (l+r)/2;
    }

    unsigned int c_l, c_r, chunks, c, remainder, rem, r_l;

    chunks = (r-l+1) / 5;
    remainder = (r-l+1) % 5;

    for(c=0; c<chunks; ++c) {
        c_l = l + c * 5;
        c_r = l + c * 5 + 4;
        sort(A, c_l, c_r, elem_size, leq);
        swap(A+(c_l+2)*elem_size, A+(l+c)*elem_size, elem_size);
    }

    // dealing with the remainder 
    for(rem=0; rem<remainder; ++rem) {
        r_l = l + chunks*5;
        swap(A+(r_l+rem)*elem_size, A+(l+chunks+rem)*elem_size, elem_size);
    }

    return select_index(A, l, l+chunks+remainder-1, l+((chunks+remainder)/2), elem_size, leq);
}

unsigned int select_index(void *A,
                          const unsigned int  l,
                          const unsigned int  r, 
                          const unsigned int i,
                          const size_t elem_size, 
                          total_order leq)
{
    if(r-l<10) {
        sort(A, l, r, elem_size, leq);
        return i;
    }
        
    // find the median - could be wrong
    const unsigned int wrong_med_pos = select_pivot(A, l, r, elem_size, leq);

    struct pivots k = three_way_partition(A, l, r, wrong_med_pos, elem_size, leq);

    if(i < k.lt) // search in S
        return select_index(A, l, k.lt-1, i, elem_size, leq); 
    else if(i > k.gt) // search in G
        return select_index(A, k.gt+1, r, i, elem_size, leq);
    else
        return i;
}

void quick_sort_select_rec(void *A,
                       const unsigned int  l,
                       const unsigned int  r, 
                       const size_t elem_size, 
                       total_order leq)
{ 
    if (l < r) {

        if(r-l<10) {
            sort(A, l, r, elem_size, leq);
        } else {
            // find the median and use it as pivot for partition
            const unsigned int med_pos = select_index(A, l, r, (r+l)/2, elem_size, leq);

            struct pivots p = three_way_partition(A, l, r, med_pos, elem_size, leq);

            if(p.lt != l)
                quick_sort_select_rec(A, l, p.lt-1, elem_size, leq); 
            if(p.gt != r)   
                quick_sort_select_rec(A, p.gt+1, r, elem_size, leq);   
        }
    } 
}

void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{ 
    quick_sort_select_rec(A, 0, n-1, elem_size, leq);
}