# Dynamic Linked List Library

## Overview
This library provides a **generic, dynamic doubly linked list** implementation in C using `void*` pointers for flexible data storage. It supports **memory management, element operations, queue, and stack functionalities**.

## Features
- **Generic Storage**: Stores any data type using `void*`.
- **Doubly Linked List**: Each node has pointers to both the next and previous node.
- **Memory Management**: Functions to allocate and free nodes dynamically.
- **Element Operations**: Add, find, and remove elements.
- **Queue & Stack Support**: Enqueue, dequeue, push, and pop operations.

## Data Structures
- `node_t`: Represents a node in the list.
- `list_t`: Manages the linked list with head, rear, size, and element count.

## Function Overview
### Memory Management
- `void list_initialize(list_t *list, size_t key_size);`  
  _Initializes a list with the given key size._
- `node_t *list_node_create(void *new_key, node_t *previous_node_p, node_t *next_node_p);`  
  _Creates and initializes a new node._
- `int list_node_destroy(node_t *node, list_t *list);`  
  _Destroys a node and updates the list._

### Element Management
- `int list_element_add(void *new_key, list_t *list);`  
  _Adds an element to the rear of the list._
- `node_t *list_element_find(void *key, size_t key_size, node_t *head_p);`  
  _Finds and returns a pointer to a node containing the key._

### Queue Operations
- `void *list_element_dequeue(list_t *list);`  
  _Removes and returns the first element in the list._

### Stack Operations
- `void *list_element_pop(list_t *list);`  
  _Removes and returns the last element in the list._

## Usage Example
```c
#include <stdio.h>
#include <stdlib.h>
#include "dyn_linked_list.h"

typedef struct
{
    char name[20];
    int age;
}person_t;

void person_print(person_t *person);

void list_element_all_print(list_t *list);

int main()
{
    list_t list_persons;

    list_initialize(&list_persons, sizeof(person_t));

    person_t person1 = {"Tim", 20};
    person_t person2 = {"Susanna", 30};
    person_t person3 = {"Felix", 40};

    list_element_add(&person1, &list_persons);
    list_element_add(&person2, &list_persons);
    list_element_add(&person3, &list_persons);

    /*
    for(int i = 0; i < list_persons.n_elements; i++)
    {
        person_t *temp_p = (person_t *)list_element_dequeue(&list_persons);
        if(temp_p != NULL)
            person_print(temp_p);
    }*/

    /*
    //find a node and print
    node_t *temp_p = list_element_find(&person1, sizeof(person1), list_persons.head_p);
    if(temp_p != NULL)
            person_print((person_t *)temp_p->key);
    */

    list_element_all_print(&list_persons);




    return 0;
}

void list_element_all_print(list_t *list)
{
    if(list->head_p == NULL)
        return;

    node_t *temp_p = list->head_p;

    for(int i = 0; i < list->n_elements; i++)
    {
        person_t *temp_person_p = (person_t *)temp_p->key;

        printf("Person [%d]\n", i + 1);
        person_print(temp_person_p);

        temp_p = temp_p->next_node_p;
    }
}

void person_print(person_t *person)
{
    printf("name: %s\n", person->name);
    printf("name: %d\n", person->age);
}

```

## Notes
- The user is responsible for **allocating and freeing memory**.
- Strings should be compared using `strcmp()` instead of `memcmp()`.
- Always ensure proper memory management to prevent leaks.

## License
This library is open-source and can be modified as needed. Happy coding!

