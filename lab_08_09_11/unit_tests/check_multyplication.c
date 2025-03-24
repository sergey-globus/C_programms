#include <check.h>
#include "multyplication.h"

START_TEST(test_multy_dif_papam)
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
    float **mtr_multy = NULL;
    rc = multyplication(mtr_1, n1, m1, mtr_2, n2, m2, &mtr_multy);
    ck_assert_int_eq(rc, MULTY_ERROR);
}
END_TEST

/*!
START_TEST(test_multy_default)
{
    int rc;
    float *mtr_1[1];
    float a0[2] = {2, 2};
    mtr_1[0] = a0;
    int n1 = 1;
    int m1 = 2;
    float *mtr_2[2];
    float b0[1] = {5};
    float b1[1] = {7};
    mtr_2[0] = b0;
    mtr_2[1] = b1;
    int n2 = 2;
    int m2 = 1;
    float **mtr_multy = NULL;
    float *res[1];
    float c0[1] = {24};
    res[0] = c0;
    rc = multyplication(mtr_1, n1, m1, mtr_2, n2, m2, &mtr_multy);
    ck_assert_int_eq(rc, SUCCESS);
    ck_assert_float_eq(res[0][0], mtr_multy[0][0]);
    
}
*/

Suite *multy_suite(void)
{
    Suite *s;
    TCase *tc_neg;
//    TCase *tc_pos;

    s = suite_create("multyplication");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_multy_dif_papam);

    suite_add_tcase(s, tc_neg);
/*!
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multy_default);

    suite_add_tcase(s, tc_pos);
*/
    return s;
}
