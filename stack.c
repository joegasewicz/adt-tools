/********************************************//**
 * Inserts & deletes are only made at the top of
 * stack. The stack implements LIFO (last in - first out).
 * The stack is referenced via a pointer to the top node.
 * The link member of the last node in the stack is
 * set to NULL.
 ***********************************************/
 /** @file stack.c */

 #include "adt_tools.h"

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
 * @param data void*
 * @return int
 *
 ***********************************************/
int *ADT_stk_push(ADT_Stack *stack, void *data)
 {
      return ADT_list_insert(stack, data);
 }

/********************************************//**
 * @brief
 *
 * @param stack ADT_Stack*
 * @return bool
 *
 ***********************************************/
//bool is_empty(ADT_Stack *stack)
// {
//     ADT_Stack *temp_stack = stack;
//     if (temp_stack == NULL || temp_stack->link == NULL)
//         return true;
//      return false;
// }



