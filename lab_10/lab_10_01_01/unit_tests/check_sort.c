#include <check.h>
#include "../inc/sort.h"
#include "../inc/sorted_insert.h"
#include "../inc/comparator_scores.h"


// Тест на сортировку пустого списка
START_TEST(test_sort_empty_list)
{
    node_t *head = NULL;
    node_t *sorted = sort(head, comparator_scores);
    ck_assert_ptr_eq(head, sorted); // Список должен остаться пустым
}
END_TEST

// Функция, объединяющая все тесты
Suite *test_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Sort Function Tests");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_sort_empty_list);

    suite_add_tcase(s, tc_core);

    return s;
}

