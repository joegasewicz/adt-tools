//
// Created by Joe Goose on 27/04/2023.
//

#ifndef ADT_TOOLS_ADT_TOOLS_H
#define ADT_TOOLS_ADT_TOOLS_H

/* @file adt_tools.h */

#define ADT_SUCCESS 0
#define ADT_NO_ERROR 0
#define ADT_ALLOC_ERROR -1
#define ADT_STACK_NODE_HAS_NEXT -2
#define ADT_NO_REFERENCE -3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
 * @param l
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

void ADT_list_destroy(ADT_List * list);

ADT_List *ADT_list_tail(ADT_List *list);

/********************************************//**
 * @brief Implements the stack using a linked list
 * An ADT_Stack is technically a self referencing
 * node but for clarity & portability within this
 * library it is named ADT_Stack.
 ***********************************************/
typedef ADT_List ADT_Stack;

/********************************************//**
 * @brief Checks if the stack is empty. The macro will
 * return true if there are no nodes in the stack or the
 * stack has not yet been initiated.
 *
 * @param l
 * @return #define
 *
 ***********************************************/
#define ADT_STACK_IS_EMPTY(s) (s == NULL)

ADT_Stack *ADT_stk_init(void *data);

int ADT_stk_push(ADT_Stack *stack, void *data);

int ADT_stk_pop(ADT_Stack *stack);

ADT_Stack *ADT_stk_peek(const ADT_Stack *stack);

void ADT_stk_destroy(ADT_Stack *stack);

int ADT_stk_size(ADT_Stack *stack);
#endif //ADT_TOOLS_ADT_TOOLS_H
