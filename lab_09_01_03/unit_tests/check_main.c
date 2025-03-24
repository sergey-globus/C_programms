#include <check.h>

Suite *compare_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    s = compare_suite();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}
