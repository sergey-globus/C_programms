#include <check.h>
#include "sort.h"

START_TEST(test_sort_default)
{
    int pb[6] = {1, 4, 5, 2, 6, 3};
    int n = 6;
    int res[6] = {1, 2, 3, 4, 5, 6};
    mysort(pb, 6, sizeof(int), compar_int);
    for (int i = 0; i < n; i++)
        ck_assert_int_eq(pb[i], res[i]);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;

    TCase *tc_pos;

    s = suite_create("sort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_default);

    suite_add_tcase(s, tc_pos);

    return s;
}
