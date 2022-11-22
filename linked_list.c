/** @file linked_list.c */

#include "linked_list.h"


/********************************************//**
 * @brief Creates a new instance of the ADT_List object
 *
 * @param data void* generic data type
 * @return ADT_List*
 *
 ***********************************************/
ADT_List *ADT_list_new(void *data)
{
    ADT_List *l = malloc(sizeof(ADT_List));
    l->data = data;
    l->next = NULL;
    return l;
}


//void insertAtBeginning(ADT_List *head, char val)
//{
//    ADT_List new_node = malloc(sizeof(node_t));
//    new_node->data = val;
//    // if this is the first call then head will be NULL else gets set to the previous head
//    new_node->next = *head;
//    // set the head to this new node
//    *head = new_node;
//}
//
//
//void insertAtEnd(ADT_List *head, char value)
//{
//    ADT_List current = *head;
//
//    if (current == NULL)
//    {
//        // there are no nodes so add the first
//        current = malloc(sizeof(node_t));
//        current->data = value;
//        current->next = NULL;
//        *head = current;
//    }
//    else
//    {
//        while(current->next != NULL)
//        {
//            // set current to the last node
//            current = current->next;
//        }
//        current->next = malloc(sizeof(node_t));
//        current->next->data = value;
//        current->next->next = NULL;
//    }
//}
//
//
//
//void insert(ADT_List *head, char value)
//{
//    ADT_List newPtr;
//    ADT_List previousPtr;
//    ADT_List currentPtr;
//
//    newPtr = malloc(sizeof(node_t));
//
//    // check if space is available
//    if (newPtr != NULL)
//    {
//        newPtr->data = value;
//        newPtr->next = NULL;
//
//        previousPtr = NULL;
//        currentPtr = *head;
//
//        while(currentPtr->next != NULL && value > currentPtr->data)
//        {
//            previousPtr = currentPtr;
//            currentPtr = currentPtr->next;
//        } /* end while */
//        if (previousPtr == NULL)
//        {
//            // no nodes so create first node at beginning of list
//            *head = newPtr;
//        }
//        else
//        {
//            // insert a new node between the previous and current nodes
//            previousPtr->next = newPtr;
//            newPtr->next = currentPtr;
//        }
//    }
//    else
//    {
//        printf("Error %c not inserted. No memory available.\n", value);
//    }
//    // TODO return int error
//}
//
//
//
//char delete(ADT_List *head, char value)
//{
//    ADT_List previousPtr;
//    ADT_List currentPtr;
//    ADT_List tempPtr;
//
//    if (value == (*head)->data)
//    {
//        tempPtr = *head; // store node being deleted
//        *head = (*head)->next;
//        free(tempPtr);
//    }
//    else
//    {
//        previousPtr = *head;
//        currentPtr = (*head)->next;
//
//        while(currentPtr != NULL && currentPtr->data != value)
//        {
//            previousPtr = currentPtr;
//            currentPtr = currentPtr->next;
//        }
//        if (currentPtr != NULL)
//        {
//            tempPtr = currentPtr;
//            previousPtr->next = currentPtr->next;
//            free(tempPtr);
//            return value;
//        }
//    }
//    return '\0';
//}
//
//
//void deleteAtPosition(ADT_List *head, int pos)
//{
//    int length = 0;
//    ADT_List currentPtr;
//    ADT_List previousPtr;
//    currentPtr = *head;
//    if (*head == NULL)
//    {
//        printf("Error: Nothing to delete\n");
//        return '\0';
//    }
//    if (pos == 1)
//    {
//        *head = currentPtr->next;
//    }
//    else
//    {
//        while(currentPtr != NULL)
//        {
//            currentPtr = currentPtr->next;
//            length++;
//        }
//        if (pos > 0 && pos <= length)
//        {
//            for(int i = 1; i < pos; i++)
//            {
//                previousPtr = currentPtr;
//                currentPtr = currentPtr->next;
//            }
//            previousPtr->next = currentPtr->next;
//        }
//        else
//        {
//            printf("Error: out of range\n");
//            return '\0';
//        }
//
//    }
//    free(currentPtr);
//}
//
//
//void printList(ADT_List currentPtr)
//{
//    if (currentPtr == NULL)
//    {
//        printf("List is empty\n\n");
//    }
//    else
//    {
//        printf("The list is:\n");
//        while(currentPtr != NULL)
//        {
//            currentPtr = currentPtr->next;
//        }
//        printf("NULL\n\n");
//    }
//}
//
//
//int isEmpty(ADT_List head)
//{
//    return head == NULL;
//}
//
//
