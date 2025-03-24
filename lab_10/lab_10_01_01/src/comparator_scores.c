#include "../inc/comparator_scores.h"

int comparator_scores(const void *a, const void *b)
{
    return ((struct base *) a)->scores - ((struct base *) b)->scores;
}
