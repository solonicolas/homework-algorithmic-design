#include <list.h>

list_type *build_list(node_type *node, const unsigned int w) {
    
    list_type *list = (list_type *) malloc(sizeof(list_type));
    list->node = node;
    list->next = NULL;
    list->weight = w;
    
	return list;
}

void update_weight(list_type *list, const unsigned int w) {
    list->weight = w;
}

void swap_lists(list_type* n1, list_type* n2){

    list_type* temp_list = malloc(sizeof(list_type));
    
    *temp_list = *n1;
    *n1 = *n2;
    *n2 = *temp_list;

    free(temp_list);
}