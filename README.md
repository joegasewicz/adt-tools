# libadttools
A set of abstract data types.

### Linked List
Functions:
- [`ADT_List *ADT_list_new(data)`](https://github.com/joegasewicz/libadttools#adt_list-adt_list_newdata)
- [`void ADT_list_insert(ADT_List *list, void *data)`](https://github.com/joegasewicz/libadttools#void-adt_list_insertadt_list-list-void-data)

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

