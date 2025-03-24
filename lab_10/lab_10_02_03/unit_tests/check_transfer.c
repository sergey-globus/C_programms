#include <check.h>
#include "transfer.h"
#include "create_node.h"
#include "add_end.h"
#include "free_data.h"

// Тест на разложение числа 1
START_TEST(test_transfer_factorization_of_1)
{
    int number = 1;
    node_t *result = transfer(number);
    ck_assert_ptr_ne(result, NULL);
    ck_assert_int_eq(result->power, 0);
    ck_assert_ptr_eq(result->next, NULL);
    free_data(result);
}
END_TEST

// Тест на разложение числа на простые множители
START_TEST(test_transfer_factorization)
{
    int number = 36;
    node_t *result = transfer(number);
    // Ожидаемый результат: 2^2 * 3^2
    ck_assert_ptr_ne(result, NULL);
    ck_assert_int_eq(result->power, 2);
    ck_assert_ptr_ne(result->next, NULL);
    ck_assert_int_eq(result->next->power, 2);
    ck_assert_ptr_eq(result->next->next, NULL);
    free_data(result);
}
END_TEST

// Функция, объединяющая все тесты
Suite *test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Transfer Function Tests");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_transfer_factorization_of_1);
    tcase_add_test(tc_core, test_transfer_factorization);

    suite_add_tcase(s, tc_core);

    return s;
}

