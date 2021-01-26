#include <binheap.h>
#include <string.h>
#include <stdio.h>

#define PARENT(node) ((node-1)/2)
#define LEFT_CHILD(node) (2*(node)+1)
#define RIGHT_CHILD(node) (2*(node+1))

// an index for a node is valid if its smaller than the size of the heap
#define VALID_NODE(H, node) ((H)->num_of_elem>(node)) 

#define ADDR(H, pos) ((H)->A+(pos)*((H)->key_size)) // for a given position in A, the address
#define INDEX_OF(H, addr) ((addr-((H)->A))/((H)->key_size)) // for a given address, the node number

#define POS(H, node) ((H)->key_pos[node]) // for a given node, the position in A
#define NODE(H, pos) ((H)->rev_pos[pos]) // for a given position in A, the node

int is_heap_empty(const binheap_type *H)
{
    return (H->num_of_elem==0);
}

const void *min_value(const binheap_type *H)
{
    if(is_heap_empty(H))
        return NULL;

    return ADDR(H, NODE(H, 0));;
}

void swap_keys(binheap_type *H, unsigned int n_a, unsigned int n_b)
{
    // get the real positions
    unsigned int p_a = POS(H, n_a);
    unsigned int p_b = POS(H, n_b);
    unsigned int temp = POS(H, n_a);

    // change key_pos
    POS(H, n_a) =  POS(H, n_b);
    POS(H, n_b) = temp;

    // change rev_pos
    NODE(H, p_a) = n_b;
    NODE(H, p_b) = n_a;
}

void heapify(binheap_type *H, unsigned int node){

    unsigned int dst_node, child, node_pos, child_pos;

    do {
        dst_node = node;
        node_pos = POS(H, node);

        child_pos = RIGHT_CHILD(node_pos);

        if (VALID_NODE(H,child_pos)){
            child = NODE(H, child_pos);

            if(H->leq(ADDR(H, child), ADDR(H, dst_node)))
                dst_node = child;
        }
                
        child_pos = LEFT_CHILD(node_pos);

        if (VALID_NODE(H,child_pos)){
            child = NODE(H, child_pos);

            if(H->leq(ADDR(H, child), ADDR(H, dst_node)))
                dst_node = child;
        }

        // if we found another min, swap the keys
        if(dst_node != node)
            swap_keys(H, dst_node, node);

    } while( dst_node != node);
}

const void *extract_min(binheap_type *H)
{
    if (is_heap_empty(H))
        return NULL;

    swap_keys(H, NODE(H, 0), NODE(H, H->num_of_elem-1));
    H->num_of_elem--;

    heapify(H, NODE(H, 0));

    return ADDR(H, NODE(H, H->num_of_elem));
}

const void *find_the_max(void *A, 
            const unsigned int num_of_elem,
            const size_t key_size,
            total_order_type leq)
{
    if(num_of_elem == 0)
        return NULL;

    const void *max_value = A;
    for(const void *addr=A+key_size; addr!=A+(num_of_elem-1)*key_size; addr+=key_size) {
        if(!leq(addr, max_value))
            max_value = addr;
    }

    return max_value;
}

binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
                         const size_t key_size, 
                         total_order_type leq)
{
    binheap_type *H = (binheap_type *)malloc(sizeof(binheap_type));

    H->A = A;
    
    H->key_pos = (unsigned int *)malloc(sizeof(unsigned int)*max_size);
    H->rev_pos = (unsigned int *)malloc(sizeof(unsigned int)*max_size);

    for(unsigned int i=0; i< max_size; ++i) {
        H->key_pos[i] = i;
        H->rev_pos[i] = i;
    }

    H->num_of_elem = num_of_elem;
    H->max_size = max_size;
    H->key_size = key_size;
    H->leq = leq;
    
    // maximum value handled by the data structure until a certain point
    H->max_order_value = malloc(key_size);

    if( num_of_elem == 0)
        return H;
    
    const void *value = find_the_max(A, num_of_elem, key_size, leq);
    
    memcpy(H->max_order_value, value, key_size);

    for(unsigned int i=num_of_elem/2; i>0; --i)
        heapify(H, i);
    heapify(H, 0);

    return H;
}

void delete_heap(binheap_type *H)
{
    free(H->max_order_value);
    free(H);
}

const void *decrease_key(binheap_type *H, void *node, const void *value)
{
    if(H->num_of_elem == 1)
        return NULL;

    unsigned int node_idx = INDEX_OF(H, node);
    unsigned int node_pos = POS(H, node_idx);

    // if the value is greater than the maximum
    if(!(H->leq(value, node)))
        return NULL;

    memcpy(node, value, H->key_size);

    unsigned int parent_idx = NODE(H, PARENT(node_pos));
    void *parent = ADDR(H, parent_idx);

    while ((node_pos != 0) && (!H->leq(parent, node))) {
        
        swap_keys(H, parent_idx, node_idx);
        node_pos = POS(H, node_idx);

        if(VALID_NODE(H, PARENT(node_pos))){
            parent_idx = NODE(H, PARENT(node_pos));
            parent = ADDR(H, parent_idx);
        } else
        {
            break;
        }
    }
    return NULL;
}

const void *insert_value(binheap_type *H, const void *value)
{
    if(H->max_size == H->num_of_elem)
        return NULL;

    if(H->num_of_elem == 0 || !H->leq(value, H->max_order_value))
        memcpy(H->max_order_value, value, H->key_size); // the new value is now the max_order_value

    // new node in the last position
    void *new_node_addr = ADDR(H, H->num_of_elem);

    // copy there the max_order_value
    memcpy(new_node_addr, H->max_order_value, H->key_size);
    
    H->num_of_elem++;

    return decrease_key(H, new_node_addr, value);
}

void print_heap(const binheap_type *H, 
                void (*key_printer)(const void *value))
{
    unsigned int next_level_node = 1;
    
    for(unsigned int node = 0; node < H->num_of_elem; ++node) {
        if(node==next_level_node) {
            printf("\n");
            next_level_node = LEFT_CHILD(node);
        } else {
            printf("\t"); 
        }
        key_printer(ADDR(H, NODE(H, node)));
    } 
    printf("\n");
}