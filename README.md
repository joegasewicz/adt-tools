# libadttools

### Linked List
Functions:
- (https://github.com/joegasewicz/libadttools#adt_list-adt_list_newdata)[`ADT_List *ADT_list_new(data)`]
- (https://github.com/joegasewicz/libadttools#void-adt_list_insertadt_list-list-void-data)[`void ADT_list_insert(ADT_List *list, void *data)`]

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

