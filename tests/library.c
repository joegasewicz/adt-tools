
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

#include "adt_tools.h"

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
    int result1 = ADT_list_insert(list, data2);

    // Test
    ck_assert_int_eq(result1, ADT_NO_ERROR);
    ck_assert_ptr_eq(list->data, data);
    ck_assert_str_eq(((Data*)list->data)->name, "Joe");
    ck_assert_ptr_eq(list->next->data, data2);
    ck_assert_ptr_ne(list->next->data, data3);
    ck_assert_str_eq(((Data*)list->next->data)->name, "Ted");
}
END_TEST

START_TEST(test_ADT_list_delete)
{
    // Setup
    typedef struct data_t {
        char *name;
    } Data;

    Data *data = malloc(sizeof(Data));
    data->name = calloc(4, sizeof(char));
    strcat(data->name, "Joe");
    ADT_List *list = ADT_list_new(data);

    // Insert another item
    Data *data2 = malloc(sizeof(Data));
    data2->name = calloc(4, sizeof(char));
    strcpy(data2->name, "Ted");
    ADT_list_insert(list, data2);

    // Insert another item
    Data *data3 = malloc(sizeof(Data));
    data3->name = calloc(4, sizeof(char));
    strcpy(data3->name, "Pat");
    ADT_list_insert(list, data3);

    // Delete the #2nd item
    void *result = ADT_list_delete(list, data2);

    // Test
    ck_assert_pstr_eq(result, data2);
    ck_assert_pstr_eq(list->data, data);
    ck_assert_pstr_eq(list->next->data, data3);
    ck_assert_pstr_eq(list->next->next, NULL);
}
END_TEST

START_TEST(test_ADT_LIST_IS_EMPTY)
{
    int *d = 1;
    ADT_List *l = ADT_list_new(d);
    int result = ADT_LIST_IS_EMPTY(l);
    ck_assert_int_eq(result, 0);
    result = ADT_LIST_IS_EMPTY(NULL);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_ADT_list_size)
{
    int *d1 = 1;
    int *d2 = 1;
    int *d3 = 1;
    int *d4 = 1;
    int result;
    ADT_List *l = ADT_list_new(d1);
    ADT_list_insert(l, d2);
    ADT_list_insert(l, d3);
    ADT_list_insert(l, d4);
    result = ADT_list_size(l);
    ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(test_ADT_LIST_NEXT)
{
    int *d1 = 1;
    int *d2 = 2;
    int *d3 = 3;
    int *d4 = 4;
    int result;
    ADT_List *l = ADT_list_new(d1);
    ADT_list_insert(l, d2);
    ADT_list_insert(l, d3);
    ADT_list_insert(l, d4);
    ck_assert_int_eq(l->data, 1);
    ADT_List *l2 = ADT_LIST_NEXT(l);
    ck_assert_int_eq(l2->data, 2);
    ADT_List *l3 = ADT_LIST_NEXT(l2);
    ck_assert_int_eq(l3->data, 3);
    ADT_List *l4 = ADT_LIST_NEXT(l3);
    ck_assert_int_eq(l4->data, 4);
}
END_TEST

START_TEST (test_ADT_LIST_DATA)
{
    int *d1 = 1;
    ADT_List *l = ADT_list_new(d1);
    int result = ADT_LIST_DATA(l);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST (test_ADT_list_destroy)
{
    int *d1 = 1;
    int *d2 = 2;
    int *d3 = 3;
    int *d4 = 4;
    int result;
    ADT_List *l = ADT_list_new(d1);
    ADT_list_insert(l, d2);
    ADT_list_insert(l, d3);
    ADT_list_insert(l, d4);
    ADT_list_destroy(l);
    ck_assert_int_eq(ADT_LIST_IS_EMPTY(l), 0);
}
END_TEST

START_TEST(test_ADT_list_tail)
{
    int *d1 = 1;
    int *d2 = 2;
    int *d3 = 3;
    int *d4 = 4;
    int result;
    ADT_List *l = ADT_list_new(d1);
    ADT_list_insert(l, d2);
    ADT_list_insert(l, d3);
    ADT_list_insert(l, d4);
    ADT_List *l2 = ADT_LIST_NEXT(l);
    ADT_List *l3 = ADT_LIST_NEXT(l2);
    ADT_List *l4 = ADT_LIST_NEXT(l3);
    ADT_List *tail = ADT_list_tail(l);
    ck_assert_ptr_eq(tail, l4);
}
END_TEST

START_TEST(test_ADT_stk_init)
{
    int *d1 = 1;
    ADT_Stack *s = ADT_stk_init(d1);
    ck_assert_int_eq(s->data, 1);
}
END_TEST

START_TEST(test_ADT_stk_push)
{
    int *d1 = 1;
    int *d2 = 2;
    int *d3 = 3;
    int *d4 = 4;
    ADT_Stack *s = ADT_stk_init(d1);
    int result2 = ADT_stk_push(s, d2);
    int result3 = ADT_stk_push(s, d3);
    int result4 = ADT_stk_push(s, d4);
    int count = 1;
    while (count < 5)
    {
        ck_assert_int_eq(s->data, count);
        s = s->next;
        count++;
    }
}
END_TEST

START_TEST(test_ADT_STACK_IS_EMPTY)
{
    int *d = 1;
    ADT_Stack *s = ADT_stk_init(d);
    int result = ADT_STACK_IS_EMPTY(s);
    ck_assert_int_eq(result, 0);
    result = ADT_STACK_IS_EMPTY(NULL);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_ADT_stk_pop)
{
    char *d0 = calloc(4, sizeof(char));
    ADT_Stack *s = ADT_stk_init(d0);
    int res1 = ADT_stk_pop(s);
    ck_assert_int_eq(res1, 0);

    char *d1 = calloc(4, sizeof(char));
    char *d2 = calloc(4, sizeof(char));
    char *d3 = calloc(4, sizeof(char));
    char *d4 = calloc(4, sizeof(char));
    ADT_Stack *s2 = ADT_stk_init(d1);
    int res2 = ADT_stk_push(s2, d2);
    int res3 = ADT_stk_push(s2, d3);
    int res4 = ADT_stk_push(s2, d4);

    int pop2 = ADT_stk_pop(s2);
    ck_assert_int_eq(pop2, 0);

    int pop3 = ADT_stk_pop(s2);
    ck_assert_int_eq(pop3, 0);

    int pop4 = ADT_stk_pop(s2);
    ck_assert_int_eq(pop4, 0);

    int pop5 = ADT_stk_pop(s2);
    ck_assert_int_eq(pop5, 0); // TODO this should return -3

}
END_TEST

START_TEST(test_ADT_stk_peek)
{
    int *d1 = 1;
    int *d2 = 2;
    int *d3 = 3;
    int *d4 = 4;
    ADT_Stack *s = ADT_stk_init(d1);
    int result2 = ADT_stk_push(s, d2);
    int result3 = ADT_stk_push(s, d3);
    int result4 = ADT_stk_push(s, d4);
    ADT_Stack *peekStk = ADT_stk_peek(s);
    ck_assert_int_eq(peekStk->data, 4);
}
END_TEST

START_TEST (test_ADT_stk_destroy)
{
    int *d1 = 1;
    int *d2 = 2;
    int *d3 = 3;
    int *d4 = 4;
    int result;
    ADT_Stack *s = ADT_stk_init(d1);
    ADT_stk_push(s, d2);
    ADT_stk_push(s, d3);
    ADT_stk_push(s, d4);
    ADT_stk_destroy(s);
    ck_assert_int_eq(ADT_STACK_IS_EMPTY(s), 0);
}
END_TEST

START_TEST(test_ADT_stk_size)
{
    int *d1 = 1;
    int *d2 = 1;
    int *d3 = 1;
    int *d4 = 1;
    int result;
    ADT_Stack *s = ADT_stk_init(d1);
    ADT_list_insert(s, d2);
    ADT_list_insert(s, d3);
    ADT_list_insert(s, d4);
    result = ADT_stk_size(s);
    ck_assert_int_eq(result, 3);
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
    tcase_add_test(tc_main, test_ADT_list_delete);
    tcase_add_test(tc_main, test_ADT_LIST_IS_EMPTY);
    tcase_add_test(tc_main, test_ADT_list_size);
    tcase_add_test(tc_main, test_ADT_LIST_NEXT);
    tcase_add_test(tc_main, test_ADT_LIST_DATA);
    tcase_add_test(tc_main, test_ADT_list_destroy);
    tcase_add_test(tc_main, test_ADT_list_tail);
    tcase_add_test(tc_main, test_ADT_stk_init);
    tcase_add_test(tc_main, test_ADT_stk_push);
    tcase_add_test(tc_main, test_ADT_STACK_IS_EMPTY);
    tcase_add_test(tc_main, test_ADT_stk_pop);
    tcase_add_test(tc_main, test_ADT_stk_peek);
    tcase_add_test(tc_main, test_ADT_stk_destroy);
    tcase_add_test(tc_main, test_ADT_stk_size);

    suite_add_tcase(s, tc_main);
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}