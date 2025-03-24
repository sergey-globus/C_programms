#include "../inc/compare.h"

bool compare(struct goods good, double number)
{
    bool sign = false;
    if (good.sale >= number)
        sign = true;
    return sign;
}
