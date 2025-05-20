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

    int     n_elements;
}list_t;

//****MEMORY MANAGMENT****
//initialize the list
void    list_initialize(list_t *list);
//allocate memory for a node and initialize it
node_t  *list_node_create(void *new_key, node_t *previous_node_p, node_t *next_node_p);
//free the memory of a node and update the list
int     list_node_destroy(node_t *node, list_t *list);

//****ELEMENT MANAGMENT****
//add an element to the rear of the list
int     list_element_add(void *new_key, list_t *list);
//return memory adress the key you are looking for
void    *list_element_find(void *key, size_t key_size, list_t *list_p);
//return a complete node pointer by searching for its key
node_t  *list_element_find_node(void *key, size_t key_size, list_t *list_p); // -> maybe change to void* return to key

//****QUEUE****
//remove the head, return the value as a pointer and update list
void    *list_element_dequeue(list_t *list);

//****STACK****
//removes the rear, returns the value as a pointer and updates list
void    *list_element_pop(list_t *list);

//****DATA****
//gives back an array of pointers to all the keys in the linked list
void    **list_elements_show(list_t *list);

#endif // DYN_LINKED_LIST_H
