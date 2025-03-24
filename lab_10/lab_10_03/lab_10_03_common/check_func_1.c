#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "associative_array.h"

// Тест создания и уничтожения ассоциативного массива
START_TEST(test_assoc_array_create_destroy)
{
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_ne(arr, NULL);
    assoc_array_destroy(&arr);
    ck_assert_ptr_eq(arr, NULL);
}
END_TEST

// Тест вставки и поиска значения по ключу
START_TEST(test_assoc_array_insert_find)
{
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_ne(arr, NULL);

    const char *key = "test_key";
    int value = 42;

    assoc_array_error_t result = assoc_array_insert(arr, key, value);
    ck_assert_int_eq(result, ASSOC_ARRAY_OK);

    int *found_value = NULL;
    result = assoc_array_find(arr, key, &found_value);
    ck_assert_int_eq(result, ASSOC_ARRAY_OK);
    ck_assert_ptr_ne(found_value, NULL);
    ck_assert_int_eq(*found_value, value);

    assoc_array_clear(arr);
    assoc_array_destroy(&arr);
}
END_TEST

// Тест удаления значения по ключу
START_TEST(test_assoc_array_remove)
{
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_ne(arr, NULL);

    const char *key = "test_key";
    int value = 42;

    assoc_array_error_t result = assoc_array_insert(arr, key, value);
    ck_assert_int_eq(result, ASSOC_ARRAY_OK);

    result = assoc_array_remove(arr, key);
    ck_assert_int_eq(result, ASSOC_ARRAY_OK);

    int *found_value = NULL;
    result = assoc_array_find(arr, key, &found_value);
    ck_assert_int_eq(result, ASSOC_ARRAY_NOT_FOUND);
    ck_assert_ptr_eq(found_value, NULL);

    assoc_array_clear(arr);
    assoc_array_destroy(&arr);
}
END_TEST

// Тест удаления значения по ключу (пустой массив)
START_TEST(test_assoc_array_remove_empty)
{
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_ne(arr, NULL);

    const char *key = "test_key";
    assoc_array_error_t result = assoc_array_remove(arr, key);
    ck_assert_int_eq(result, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

// Тест вставки значения с пустым ключом
START_TEST(test_assoc_array_insert_empty_key)
{
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_ne(arr, NULL);

    const char *key = "";
    int value = 42;
    assoc_array_error_t result = assoc_array_insert(arr, key, value);
    ck_assert_int_eq(result, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_clear(arr);

    assoc_array_destroy(&arr);
}
END_TEST

// Тест поиска значения с пустым ключом
START_TEST(test_assoc_array_find_empty_key)
{
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_ne(arr, NULL);

    const char *key = "";
    int *found_value = NULL;
    assoc_array_error_t result = assoc_array_find(arr, key, &found_value);
    ck_assert_int_eq(result, ASSOC_ARRAY_INVALID_PARAM);
    ck_assert_ptr_eq(found_value, NULL);
    assoc_array_clear(arr);

    assoc_array_destroy(&arr);
}
END_TEST

// Тест вставки значения с уже существующим ключом
START_TEST(test_assoc_array_insert_existing_key)
{
    assoc_array_t arr = assoc_array_create();
    ck_assert_ptr_ne(arr, NULL);

    const char *key = "test_key";
    int value = 42;

    assoc_array_error_t result = assoc_array_insert(arr, key, value);
    ck_assert_int_eq(result, ASSOC_ARRAY_OK);

    result = assoc_array_insert(arr, key, value);
    ck_assert_int_eq(result, ASSOC_ARRAY_KEY_EXISTS);
    assoc_array_clear(arr);

    assoc_array_destroy(&arr);
}
END_TEST

// Создание набора тестов
Suite *assoc_array_suite(void) {
    Suite *suite = suite_create("AssocArraySuite");

    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_assoc_array_create_destroy);
    tcase_add_test(tc_core, test_assoc_array_insert_find);
    tcase_add_test(tc_core, test_assoc_array_remove);
    tcase_add_test(tc_core, test_assoc_array_remove_empty);
    tcase_add_test(tc_core, test_assoc_array_insert_empty_key);
    tcase_add_test(tc_core, test_assoc_array_find_empty_key);
    tcase_add_test(tc_core, test_assoc_array_insert_existing_key);

    suite_add_tcase(suite, tc_core);

    return suite;
}
