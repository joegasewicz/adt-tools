/********************************************//**
 * Inserts & deletes are only made at the top of
 * stack. The stack implements LIFO (last in - first out).
 * The stack is referenced via a pointer to the top node.
 * The link member of the last node in the stack is
 * set to NULL.
 ***********************************************/
 /** @file stack.c */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>

 #include "stack.h"



 /********************************************//**
   * @brief Initiates the last node in the stack.
  *
  * @param data void*
  * @return int ~The return values indicates if there
  * are any errors. See // TODO
  *
  ***********************************************/
 int init(void *data)
 {
       ADT_Stack *stack = malloc(sizeof(ADT_Stack));
       if (stack == NULL)
            return ADT_ALLOC_ERROR;
       stack->data = data;
       stack->link = NULL;
       return ADT_NO_ERROR;
 }

/********************************************//**
 * @brief Pushes the next node on the stack.
 * You must initiates the stack by calling the
 * #init(void *data) first.
 *
 * @param data void*
 * @return int
 *
 ***********************************************/
int push(void *data)
 {
      ADT_Stack *tempPtr = malloc(sizeof(ADT_Stack));
      if (tempPtr == NULL)
            return ADT_ALLOC_ERROR;
      tempPtr->data = data;
      tempPtr->link
 }

/********************************************//**
 * @brief
 *
 * @param stack ADT_Stack*
 * @return bool
 *
 ***********************************************/
bool is_empty(ADT_Stack *stack)
 {
     ADT_Stack *temp_stack = stack;
     if (temp_stack == NULL || temp_stack->link == NULL)
         return true;
      return false;
 }



