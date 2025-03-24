#include <check.h>
#include <stdio.h>

#include "../my_snprintf.h"

// Тест для проверки вывода чисел в строку
START_TEST(test_integer_format)
{
    char buffer[20];
    char my_buffer[20];
    int value = -42;
    long x_value = 1177782237;
    int result_my = my_snprintf(my_buffer, sizeof(my_buffer), "%d %lx", value, x_value);
    int result_sn = snprintf(buffer, sizeof(buffer), "%d %lx", value, x_value);
    ck_assert_int_eq(result_my, result_sn);
    ck_assert_str_eq(buffer, my_buffer);
}
END_TEST

// Тест для проверки вывода строки
START_TEST(test_string_format)
{
    char buffer[20];
    char my_buffer[20];
    const char *str = "Hello, World!";
    int result_my = my_snprintf(my_buffer, sizeof(my_buffer), "This %s", str);
    int result_sn = snprintf(buffer, sizeof(buffer), "This %s", str);
    ck_assert_int_eq(result_my, result_sn);
    ck_assert_str_eq(buffer, my_buffer);
}
END_TEST

// Функция, объединяющая все тесты
Suite *test_suite()
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("My Snprintf Tests");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_integer_format);
    tcase_add_test(tc_core, test_string_format);

    suite_add_tcase(s, tc_core);

    return s;
}
