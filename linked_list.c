#include "linked_list.h"


/** \brief
 *
 * \example
 *
 * \param head ListNodePtr*
 * \param val char
 * \return void
 *
 */
void insertAtBeginning(ListNodePtr *head, char val)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = val;
    // if this is the first call then head will be NULL else gets set to the previous head
    new_node->nextPtr = *head;
    // set the head to this new node
    *head = new_node;
}


/** \brief
 *
 * \param head ListNodePtr*
 * \param value char
 * \return void
 *
 */
void insertAtEnd(ListNodePtr *head, char value)
{
    ListNodePtr current = *head;

    if (current == NULL)
    {
        // there are no nodes so add the first
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
    else
    {
        while(current->nextPtr != NULL)
        {
            // set current to the last node
            current = current->nextPtr;
        }
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
}


/** \brief
 *
 * \param head ListNodePtr*
 * \param value char
 * \return void
 *
 */
void insert(ListNodePtr *head, char value)
{
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(node_t));

    // check if space is available
    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *head;

        while(currentPtr->nextPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        } /* end while */
        if (previousPtr == NULL)
        {
            // no nodes so create first node at beginning of list
            *head = newPtr;
        }
        else
        {
            // insert a new node between the previous and current nodes
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("Error %c not inserted. No memory available.\n", value);
    }
    // TODO return int error
}


/** \brief
 *
 * \param head ListNodePtr*
 * \param value char
 * \return char
 *
 */
char delete(ListNodePtr *head, char value)
{
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if (value == (*head)->data)
    {
        tempPtr = *head; // store node being deleted
        *head = (*head)->nextPtr;
        free(tempPtr);
    }
    else
    {
        previousPtr = *head;
        currentPtr = (*head)->nextPtr

        while(currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}


/** \brief
 *
 * \param currentPtr ListNodePtr
 * \return void
 *
 */
void printList(ListNodePtr currentPtr)
{
    if (currentPtr == NULL)
    {
        printf("List is empty\n\n");
    }
    else
    {
        printf("The list is:\n");
        while(currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

/** \brief
 *
 * \param head ListNodePtr
 * \return int
 *
 */
int isEmpty(ListNodePtr head)
{
    return head == NULL;
}


