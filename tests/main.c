#include <stdio.h>
#include <stdlib.h>
#include <check.h>

int hello()
{

    return 1;
}
START_TEST (test_CHECK)
{
  /* unit test code */
  ck_assert_int_eq(2, 2);
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
    tcase_add_test(tc_main, test_CHECK);
    suite_add_tcase(s, tc_main);
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
