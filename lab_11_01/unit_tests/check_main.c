#include <check.h>

Suite *test_suite();

// Основная функция запуска тестов
int main(void)
{
    int number_failed;
    SRunner *sr;

    sr = srunner_create(test_suite());
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
