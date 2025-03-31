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
