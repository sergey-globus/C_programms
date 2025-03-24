#include <check.h>
#include "key.h"

START_TEST(test_key_all_eq)
{
    int rc;
    int pb_src[4] = {9, 9, 9, 9};
    int *pe_src = pb_src + 4;
    int *pb_new;
    int *pe_new;
    rc = key(pb_src, pe_src, &pb_new, &pe_new);
    ck_assert_int_eq(rc, EMPTY_FILTR_FILE);
}
END_TEST

Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_neg;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_all_eq);

    suite_add_tcase(s, tc_neg);

    return s;
}
