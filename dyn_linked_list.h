#ifndef DYN_LINKED_LIST_H
#define DYN_LINKED_LIST_H

typedef struct node_s
{
    void            *key;
    struct node_s   *next_node_p;
    struct node_s   *previous_node_p;
}node_t;

typedef struct
{
    node_t  *head_p,
            *rear_p;

    size_t  key_size;
    int     n_elements;
}list_t;

//****MEMORY MANAGMENT****
//initialize the list
void    list_initialize(list_t *list, size_t key_size);
//allocate memory for a node and initialize it
node_t  *list_node_create(void *new_key, node_t *previous_node_p, node_t *next_node_p);
//free the memory of a node and update the list
int     list_node_destroy(node_t *node, list_t *list);

//****ELEMENT MANAGMENT****
//add an element to the rear of the list
int     list_element_add(void *new_key, list_t *list);
//return memory adress of an node that holds the key in question
node_t  *list_element_find(void *key, size_t key_size, node_t *head_p);
//free the node and update list -> will use destroy node
//int list_element_destroy(datatype_t element, node_t *head_p, )


//****QUEUE****
//remove the head, return the value as a pointer and update list
void    *list_element_dequeue(list_t *list);

//****STACK****
//removes the rear, returns the value as a pointer and updates list
void    *list_element_pop(list_t *list);

#endif // DYN_LINKED_LIST_H
