

#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define ADT_NO_ERROR 0
#define ADT_ALLOC_ERROR -1

/********************************************//**
 * @brief To create a new linked list, create an instance of List.
 *
 * For example:
 * @code
 * List *list;
 * @endcode
 * @param data generic data type
 * @param next is the reference to the next node of the list
 ***********************************************/
typedef struct ADT_List_ {
    void *data;
    struct ADT_List_ *next;
} ADT_List;

void hello(void);

ADT_List *ADT_list_new(void *data);

int ADT_list_insert(ADT_List *list, void *data);

void *ADT_list_delete(ADT_List *list, void *data);


#endif // LINKED_LIST_H_INCLUDED
