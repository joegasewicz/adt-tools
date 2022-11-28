# ADT Tools
A set of abstract data types.

### Linked List
- [`ADT_List *ADT_list_new(data)`](https://github.com/joegasewicz/libadttools#adt_list-adt_list_newdata)
- [`void ADT_list_insert(ADT_List *list, void *data)`](https://github.com/joegasewicz/libadttools#void-adt_list_insertadt_list-list-void-data)
- [`void *ADT_list_delete(ADT_List *list, void *data)`](https://github.com/joegasewicz/libadttools#void-adt_list_deleteadt_list-list-void-data)
- [`int ADT_list_size(ADT_List *list)`](https://github.com/joegasewicz/adt-tools#int-adt_list_sizeadt_list-list)
- [`ADT_IS_EMPTY(head)` (macro)](https://github.com/joegasewicz/adt-tools#adt_is_emptyl-macro)
- [`ADT_LIST_NEXT(head)` (macro)](https://github.com/joegasewicz/adt-tools#adt_list_nextl-macro)
- [`ADT_LIST_DATA(head)` (macro)](https://github.com/joegasewicz/adt-tools#adt_list_datal-macro)


### Stack (TODO)

### Queue (TODO)

### Doubly Linked List (TODO)

### Binary Tree (TODO)

### Hash Table (TODO)

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

