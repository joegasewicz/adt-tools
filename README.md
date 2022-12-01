# ADT Tools
A set of abstract data types.

### Linked List
- [`ADT_List *ADT_list_new(data)`](https://github.com/joegasewicz/libadttools#adt_list-adt_list_newdata)
- [`void ADT_list_insert(ADT_List *list, void *data)`](https://github.com/joegasewicz/libadttools#void-adt_list_insertadt_list-list-void-data)
- [`void *ADT_list_delete(ADT_List *list, void *data)`](https://github.com/joegasewicz/libadttools#void-adt_list_deleteadt_list-list-void-data)
- [`int ADT_list_size(ADT_List *list)`](https://github.com/joegasewicz/adt-tools#int-adt_list_sizeadt_list-list)
- [`void ADT_list_destroy(ADT_List * list);`](https://github.com/joegasewicz/adt-tools#void-adt_list_destroyadt_list--list)
- [`ADT_List *ADT_list_tail(ADT_List *list)`](https://github.com/joegasewicz/adt-tools#adt_list-adt_list_tailadt_list-list)
- [`ADT_IS_EMPTY(head)` (macro)](https://github.com/joegasewicz/adt-tools#adt_is_emptyl-macro)
- [`ADT_LIST_NEXT(head)` (macro)](https://github.com/joegasewicz/adt-tools#adt_list_nextl-macro)
- [`ADT_LIST_DATA(head)` (macro)](https://github.com/joegasewicz/adt-tools#adt_list_datal-macro)

### Stack
- [`ADT_Stack *ADT_stk_init(void *data)`]()
- [`int *ADT_stk_push(ADT_Stack *stack, void *data)`]()
- [`int *ADT_stk_pop(ADT_Stack *stack)`]()
- [`ADT_Stack *ADT_stk_peek(const ADT_Stack *stack)`]()
- [`void ADT_stk_destroy(ADT_Stack *stack)`]()
- [`int ADT_stk_size(ADT_Stack *stack)`]()
- [`ADT_STACK_IS_EMPTY(s)` (macro)]()

##### Queue (TODO)
##### Doubly Linked List (TODO)
##### Binary Tree (TODO)
##### Hash Table (TODO)

<details>
##<summary>Linked List</summary>

#### ADT_List *ADT_list_new(data)
Create a new list
```c
// Create some data
typedef struct data_t {
   char *name;
} Data;

Data *data = malloc(sizeof(Data));
data->name = calloc(4, sizeof(char));
strcpy(data->name, "Joe");

// Pass the data to ADT_list_new to return the new head of the
// linked list
ADT_List *head = ADT_list_new(data);
```

#### void ADT_list_insert(ADT_List *list, void *data)
Insert a new item at the tail of the list

```c
// Create the data and then create a new list
ADT_List *head = ADT_list_new(data);

// Pass the head list head reference to ADT_list_insert function
ADT_list_insert(list, data2);
```

#### void *ADT_list_delete(ADT_List *list, void *data)
Remove a node from the list at nth position (matched via the data reference)
```c
// Create your `void* data` & insert the data ref into the list with `ADT_list_insert`
ADT_list_insert(list, data);

// Pass the dasta reference to the ADT_list_delete function as a 2nd argument
void *result = ADT_list_delete(list, data);
if (result < 0)
      // handle error
```

#### int ADT_list_size(ADT_List *list)
```c
int *d1 = 1;
int *d2 = 1;
ADT_List *l = ADT_list_new(d1);
ADT_list_insert(l, d2);

// Get the sum total of nodes in the list
int result = ADT_list_size(l); // returns 2
```

#### ADT_IS_EMPTY(l) (macro)
Checks if the list is empty. The macro will return true if there are
no nodes in the list or the list has not yet been initiated.
```c
int *d = 1;
ADT_List *l = ADT_list_new(d);
int result = ADT_IS_EMPTY(l); // returns false
```

#### ADT_LIST_NEXT(l) (macro)
Get the next list node
```c
int *d1 = 1;
int *d2 = 2;
int result;
ADT_List *l = ADT_list_new(d1);
ADT_list_insert(l, d2);
ADT_List *l2 = ADT_LIST_NEXT(l);
ADT_List *l3 = ADT_LIST_NEXT(l2);
```

#### ADT_LIST_DATA(l) (macro)
Get the current node's data
```c
int *d1 = 1;
ADT_List *l = ADT_list_new(d1);
int result = ADT_LIST_DATA(l);
```

#### void ADT_list_destroy(ADT_List * list)
Detaches each node from the list.
This function does not destroy allocated memory
assigned to the node's data.
```c
int *d1 = 1;
int *d2 = 2;
int result;
ADT_List *l = ADT_list_new(d1);
ADT_list_insert(l, d2);
ADT_list_destroy(l);
```
#### ADT_List *ADT_list_tail(ADT_List *list)
Returns the last node in the list
```c
int *d1 = 1;
int *d2 = 2;
int result;
ADT_List *l = ADT_list_new(d1);
ADT_list_insert(l, d2);
ADT_List *l2 = ADT_LIST_NEXT(l);
ADT_List *tail = ADT_list_tail(l);
```

</details>

<details>
##<summary>Stack</summary>


### ADT_Stack *ADT_stk_init(void *data)
Initiates the last node in the stack.
It is the responsibility of the caller to manage
the memory of void *data.
```c
int *d1 = 1;
ADT_Stack *s = ADT_stk_init(d1);
```

#### int *ADT_stk_push(ADT_Stack *stack, void *data)
Pushes the next node on the stack.
You must initiates the stack by calling the
`init(void *data)` first. It is the responsibility
of the caller to manage the memory of void *data.
```c
int *d1 = 1;
int *d2 = 2;
ADT_Stack *s = ADT_stk_init(d1);
int result = ADT_stk_push(s, d2);
```

#### int *ADT_stk_pop(ADT_Stack *stack)
Removes the top nod from the stack.
The caller must manage the memory of void *data.
```c
char *d0 = calloc(4, sizeof(char));
ADT_Stack *s = ADT_stk_init(d0);
int res1 = ADT_stk_pop(s);
```

#### ADT_Stack *ADT_stk_peek(const ADT_Stack *stack)
Enables the caller to peek at the top
node without popping it off the stack. It
returns a reference to the top node.
```c

```

#### void ADT_stk_destroy(ADT_Stack *stack)
Detaches each node from the stack.
This function does not destroy allocated memory
assigned to the node's data.
```c

```

#### int ADT_stk_size(ADT_Stack *stack)
Returns the size of the stack based on
total count of nodes.
```c

```

#### ADT_STACK_IS_EMPTY(s) (macro)
Checks if the stack is empty. The macro will
return true if there are no nodes in the stack or the
stack has not yet been initiated.
```c
int *d = 1;
ADT_Stack *s = ADT_stk_init(d);
int result = ADT_STACK_IS_EMPTY(s); // 0
result = ADT_STACK_IS_EMPTY(NULL); // 1
```

</details>

## Authors

* **joegasewicz** - *Initial work* - [@joegasewicz](https://twitter.com/joegasewicz)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

### Testing
cd into the `test` directory then build & run `main.c` - you will need to
statically link the adt_tools & dynamically link [libcheck](https://github.com/libcheck/check)

### Documentation
This library uses [doxygen](https://www.doxygen.nl/) to generate inline docs.

## License
[MIT](https://choosealicense.com/licenses/mit/)

