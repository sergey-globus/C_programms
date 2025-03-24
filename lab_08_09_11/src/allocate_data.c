#include "../inc/allocate_data.h"

float **allocate_data(int n, int m)
{
    float **data = malloc(n * sizeof(float*) + n * m * sizeof(float));
    if (data)
        for (int i = 0; i < n; i++)
            data[i] = (float*) ((char*) data + n * sizeof(float*) + i * m * sizeof(float));
    return data;
}
