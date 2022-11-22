#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <math.h>




START_TEST(joe_test)
{

    ck_assert_str_eq("hello", "goodbye");
}
END_TEST
// /home/joe/Codeblocks/check/src/check.c

int main()
{

    printf("Hello world!\n");
    return 0;
}
