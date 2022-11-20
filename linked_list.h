#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>


typedef struct node {
    char data;
    struct node *nextPtr;
} node_t;

/** \brief ListNodePtr is an abstract data type represents a link list node
 *  \example
 *   ListNodePtr head = NULL;
 */
typedef node_t *ListNodePtr;


void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

#endif // LINKED_LIST_H_INCLUDED
