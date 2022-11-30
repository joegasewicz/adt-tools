#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/********************************************//**
 * @brief An ADT_Stack is technically a self referencing
 * node but for clarity & portability within this
 * library it is named ADT_Stack.
 ***********************************************/
typedef struct ADT_Stack_ {
      void *data;
      struct ADT_Stack_ *link;
} ADT_Stack;

int init(void *data)

int push(ADT_Stack stack, void *data);

void pop(ADT_Stack stack, void *data);

ADT_Stack *top(ADT_Stack stack);

bool is_empty(ADT_Stack stack);

int size(ADT_Stack);



#endif // STACK_H_INCLUDED
