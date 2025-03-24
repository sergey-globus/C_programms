#include <check.h>

Suite *assoc_array_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    s = assoc_array_suite();
    
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}
