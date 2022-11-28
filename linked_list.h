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

/********************************************//**
 * @brief Checks if the list is empty. The macro will
 * return true if there are no nodes in the list or the
 * list has not yet been initiated.
 *
 * @param x
 * @return #define
 *
 ***********************************************/
#define ADT_LIST_IS_EMPTY(l) (l == NULL)

/********************************************//**
 * @brief Returns a pointer to the node in the list
 *
 * @param l
 * @return #define
 *
 ***********************************************/
#define ADT_LIST_NEXT(l) (l->next)

/********************************************//**
 * @brief Returns the current node's data
 *
 * @param l
 * @return #define
 *
 ***********************************************/
#define ADT_LIST_DATA(l) (l->data)

// Prototypes
ADT_List *ADT_list_new(void *data);

int ADT_list_insert(ADT_List *list, void *data);

void *ADT_list_delete(ADT_List *list, void *data);

int ADT_list_size(ADT_List *list);

void ADT_list_destroy(ADT_List * list); // TODO

void ADT_list_tail(ADT_List *list); // TODO


#endif // LINKED_LIST_H_INCLUDED
