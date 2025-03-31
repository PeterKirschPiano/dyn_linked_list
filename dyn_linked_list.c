#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dyn_linked_list.h"

#define ERROR 0
#define SUCCESS 1

//init the list
void list_initialize(list_t *list, size_t key_size)
{
    list->head_p = NULL;
    list->rear_p = NULL;
    list->n_elements = 0;
    list->key_size = key_size;
}

//allocate memory for a node and initialize it
node_t *list_node_create(void *new_key, node_t *previous_node_p, node_t *next_node_p)
{
    node_t *temp_p = calloc(1, sizeof(node_t));

    if(temp_p == NULL)
        return NULL;

    temp_p->key = new_key;
    temp_p->previous_node_p = previous_node_p;
    temp_p->next_node_p = next_node_p;

    return temp_p;
}

int list_node_destroy(node_t *node, list_t *list)
{
    if(node == NULL || list == NULL)
        return ERROR;

    //update list
    //if the node is the head
    if(node == list->head_p)
    {
        //if the list is empty
        if(node->next_node_p == NULL)
        {
            //the head_pointer has to be set to NULL
            list->head_p = NULL;
        }
        //if the list is not empty
        else
        {
            //the head pointer has to set to its next node pointer
            list->head_p = list->head_p->next_node_p;
            //set the new head's pointers neighbour to NULL
            list->head_p->previous_node_p = NULL;
        }
    }
    //if the node is the rear
    else if(node == list->rear_p)
    {
        //set its previous node to be the new rear
        list->rear_p = list->rear_p->previous_node_p;
        //set the new rear's pointers neighbour to NULL
        list->rear_p->next_node_p = NULL;
    }
    else
    {
        node->previous_node_p->next_node_p = node->next_node_p;
        node->next_node_p->previous_node_p = node->previous_node_p;
    }

    //free the node
    free(node);

    list->n_elements--;

    return SUCCESS;
}

//add an element to the rear of the list
int list_element_add(void *new_key, list_t *list)
{
    if(list == NULL)
        return ERROR;

    if(list->n_elements == 0)
    {
        node_t* temp_p = list_node_create(new_key, 0, 0);

        if(temp_p == NULL)
            return ERROR;

        //create new node
        list->head_p = temp_p;
        //update rear pointer
        list->rear_p = list->head_p;
        //update size
        list->n_elements++;
    }
    else
    {
        node_t* temp_p = list_node_create(new_key, list->rear_p, 0);

        if(temp_p == NULL)
            return ERROR;

        //create new node
        list->rear_p->next_node_p = temp_p;
        //update rear pointer
        list->rear_p = list->rear_p->next_node_p;
        //update size
        list->n_elements++;
    }

    return SUCCESS;
}

node_t *list_element_find(void *key, size_t key_size, node_t *head_p)
{
    //list empty
    if(head_p == NULL)
        return NULL;

    node_t *current_node_p = head_p;

    while(current_node_p != NULL)
    {
        if(!memcmp(current_node_p->key, key, key_size))
            return current_node_p;

        current_node_p = current_node_p->next_node_p;
    }
    //item not found
    return NULL;
}

void *list_element_dequeue(list_t *list)
{
    if(list->head_p == NULL)
        return NULL;

    void *temp_key = NULL;
    temp_key = list->head_p->key;

    node_t *temp_p = list->head_p;

    if(list->head_p->next_node_p != NULL)
    {
        list->head_p = list->head_p->next_node_p;
        list->head_p->previous_node_p = NULL;
    }
    else
        list->head_p = NULL;

    free(temp_p);

    list->n_elements--;

    //after usage free the memory of the variable in main!
    return temp_key;
}

void *list_element_pop(list_t *list)
{
    if(list->rear_p == NULL)
        return NULL;

    void *temp_key = 0;
    temp_key = list->rear_p->key;

    node_t *temp_p = list->rear_p;

    if(list->rear_p->previous_node_p != NULL)
    {
        list->rear_p = list->rear_p->previous_node_p;
        list->rear_p->next_node_p = NULL;
    }
    else
        list->rear_p = NULL; //list is now empty

    free(temp_p);

    list->n_elements--;

    return temp_key;
}
