

#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>


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
typedef struct node {
    void *data;
    struct node *next;
} ADT_List;

void hello(void);

ADT_List *ADT_list_new(void *data);

//void insert(ADT_List *head, char value);
//void insertAtEnd(ADT_List *head, char value);
//void insertAtBeginning(ADT_List *head, char value);
//char delete(ADT_List *head, char value);
//void deleteAtPosition(ADT_List *head, int pos);
//int isEmpty(ADT_List head);
//void printList(ADT_List currentPtr);

#endif // LINKED_LIST_H_INCLUDED
