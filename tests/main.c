
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

    suite_add_tcase(s, tc_main);
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
