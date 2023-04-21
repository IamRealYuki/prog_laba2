#include <stdio.h>

#include "IntVector.h"

int main()
{
    size_t cap = 6;
    struct IntVector vector = int_vector_new(cap);
    vector[0] = 5;
    printf("%d", arr[0]);
}