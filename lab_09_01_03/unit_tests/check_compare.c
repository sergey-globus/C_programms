#include <check.h>
#include "compare.h"

START_TEST(test_compare_true)
{
    bool rc;
    struct goods good;
    good.sale = 5;
    float number = 4.5;
    rc = compare(good, number);
    ck_assert_int_eq(rc, true);
}
END_TEST

START_TEST(test_compare_false)
{
    bool rc;
    struct goods good;
    good.sale = 5;
    float number = 5.5;
    rc = compare(good, number);
    ck_assert_int_eq(rc, false);
}
END_TEST

Suite *compare_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("compare");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_compare_false);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_compare_true);

    suite_add_tcase(s, tc_pos);

    return s;
}
