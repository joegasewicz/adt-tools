/** @file stack.c */

 #include "adt_tools.h"
/********************************************//**
 * Inserts & deletes are only made at the top of
 * stack. The stack implements LIFO (last in - first out).
 * The stack is referenced via a pointer to the top node.
 * The link member of the last node in the stack is
 * set to NULL.
 ***********************************************/

 /********************************************//**
   * @brief Initiates the last node in the stack.
  * It is the responsibility of the caller to manage
  * the memory of void *data.
  * @param data void*
  * @return ADT_Stack*
  *
  ***********************************************/
ADT_Stack *ADT_stk_init(void *data)
{
    ADT_Stack *stack = malloc(sizeof(ADT_Stack));
    if (stack == NULL)
        return ADT_ALLOC_ERROR;
    stack->data = data;
    stack->next = NULL;
    return stack;
}

/********************************************//**
 * @brief Pushes the next node on the stack.
 * You must initiates the stack by calling the
 * #init(void *data) first. It is the responsibility
 * of the caller to manage the memory of void *data.
 *
 * @param data void*s
 * @return int
 *
 ***********************************************/
int ADT_stk_push(ADT_Stack *stack, void *data)
{
    return ADT_list_insert(stack, data);
}

/********************************************//**
 * @brief Removes the top nod from the stack.
 * The caller must manage the memory of void *data.
 *
 * @param stack ADT_Stack*
 * @return int*
 *
 ***********************************************/
int ADT_stk_pop(ADT_Stack *stack)
{

    if (stack == NULL || stack->data == NULL) return ADT_NO_REFERENCE;
    if (stack->next == NULL)
    {
        stack->data = NULL;
        free(stack);
        return ADT_SUCCESS;
    }
    ADT_Stack *head = stack;
    ADT_Stack *prev;

    while (head->next != NULL)
    {
        prev = head;
        head = head->next;
    }
    if (head != NULL)
    {
        prev->next = NULL;
        head->data = NULL; // the caller must manage the memory
        free(head);
        head = NULL;
        return ADT_SUCCESS;
    }
    return ADT_NO_REFERENCE;
}

/********************************************//**
 * @brief Enables the caller to peek at the top
 *  node without popping it off the stack. It
 * returns a reference to the top node.
 *
 * @param stack const ADT_Stack*
 * @return ADT_Stack*
 *
 ***********************************************/
ADT_Stack *ADT_stk_peek(const ADT_Stack *stack)
{
   ADT_Stack *head = stack;
   if (stack == NULL || stack->next == NULL)
        return stack;
   while (head->next != NULL)
   {
       head = head->next;
   }
   return head;
}


/********************************************//**
 * @brief Detaches each node from the stack.
 * This function does not destroy allocated memory
 * assigned to the node's data.
 *
 * @param stack ADT_Stack*
 * @return void
 *
 ***********************************************/
void ADT_stk_destroy(ADT_Stack *stack)
{
    ADT_list_destroy(stack);
}

/********************************************//**
 * @brief Returns the size of the stack based on
 * total count of nodes.
 *
 * @param ADT_Stack
 * @return int
 *
 ***********************************************/
int ADT_stk_size(ADT_Stack *stack)
{
    return ADT_list_size(stack);
}
