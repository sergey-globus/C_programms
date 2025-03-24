#include <check.h>
#include "addition.h"

START_TEST(test_add_dif_papam)
{
    int rc;
    float *mtr_1[1];
    float a0[3] = {2.0, 2.0, 2.0};
    mtr_1[0] = a0;
    int n1 = 1;
    int m1 = 3;
    float *mtr_2[2];
    float b0[1] = {5.0};
    float b1[1] = {7.0};
    mtr_2[0] = b0;
    mtr_2[1] = b1;
    int n2 = 2;
    int m2 = 1;
    float **mtr_sum = NULL;
    rc = addition(mtr_1, n1, m1, mtr_2, n2, m2, &mtr_sum);
    ck_assert_int_eq(rc, ADD_ERROR);
}
END_TEST

/*!
START_TEST(test_add_default)
{
    int rc;
    float *mtr_1[2];
    float a0[2] = {2.0, 2.0};
    float a1[2] = {2.0, 2.0};
    mtr_1[0] = a0;
    mtr_1[1] = a1;
    int n1 = 2;
    int m1 = 2;
    float *mtr_2[2];
    float b0[2] = {5.0, 5.0};
    float b1[2] = {7.0, 7.0};
    mtr_2[0] = b0;
    mtr_2[1] = b1;
    int n2 = 2;
    int m2 = 2;
    float **mtr_sum = NULL;
    float *res[2];
    float c0[2] = {7, 7};
    float c1[2] = {9, 9};
    res[0] = c0;
    res[1] = c1;
    rc = addition(mtr_1, n1, m1, mtr_2, n2, m2, &mtr_sum);
    ck_assert_int_eq(rc, SUCCESS);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
	    ck_assert_float_eq(res[i][j], mtr_sum[i][j]);
    
}
*/

Suite *add_suite(void)
{
    Suite *s;
    TCase *tc_neg;
//    TCase *tc_pos;

    s = suite_create("addition");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_add_dif_papam);

    suite_add_tcase(s, tc_neg);
/*!
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_add_default);

    suite_add_tcase(s, tc_pos);
*/
    return s;
}
