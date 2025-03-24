#include <check.h>

Suite *sort_suite(void);
Suite *key_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    Suite *p;
    SRunner *runner;
    s = sort_suite();
    p = key_suite();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(p);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}
