
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

#include "linked_list.h"


START_TEST (test_ADT_list_new1)
{
    char *expected = "Joe";
    typedef struct data_t {
        char *name;
        int age;
    } Data;

    Data *data;

    data = malloc(sizeof(Data));
    data->name = malloc(sizeof(expected));
    strcat(data->name, expected);
    data->age = 47;

    ADT_List *list = ADT_list_new(data);
    /* unit test code */
    Data *resultData = list->data;
    ck_assert_str_eq(expected, resultData->name);
    ck_assert_int_eq(47, resultData->age);
    /* clean up */
    free(data);
    free(list);
}
END_TEST

START_TEST (test_ADT_list_insert)
{
    // Setup
    typedef struct data_t {
         char *name;
    } Data;

    Data *data = malloc(sizeof(Data));
    Data *data3 = malloc(sizeof(Data)); // for negative test
    data->name = calloc(4, sizeof(char));
    strcpy(data->name, "Joe");
    ADT_List *list = ADT_list_new(data);

    // Setup for ADT_list_insert
    Data *data2 = malloc(sizeof(Data));
    data2->name = calloc(4, sizeof(char));
    strcpy(data2->name, "Ted");
    ADT_list_insert(list, data2);

    // Test
    ck_assert_ptr_eq(list->data, data);
    ck_assert_str_eq(((Data*)list->data)->name, "Joe");
    ck_assert_ptr_eq(list->next->data, data2);
    ck_assert_ptr_ne(list->next->data, data3);
    ck_assert_str_eq(((Data*)list->next->data)->name, "Ted");
}
END_TEST

int main()
{
    TCase *tc_main;
    Suite *s;
    SRunner *sr;
    int number_failed;

    s = suite_create("ADTToolsSuite");
    tc_main = tcase_create("Main");

    /* ================ linked list tests =================*/
    tcase_add_test(tc_main, test_ADT_list_new1);
    tcase_add_test(tc_main, test_ADT_list_insert);

    suite_add_tcase(s, tc_main);
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
