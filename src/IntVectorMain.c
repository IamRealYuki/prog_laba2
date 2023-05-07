#include <stdio.h>

#include "IntVector.h"

int main()
{
    size_t cap = 6;
    struct IntVector *intvector = int_vector_new(cap);
    int i = 0;
    while (i < 10)
    {
        int_vector_push_back(intvector, i);
        printf("%d: %d\n", i, intvector->vector[i]);
        i++;
    }
    printf("\nPrint copied vector\n");
    struct IntVector *copy = int_vector_copy(intvector);
    for (i = 0; i < copy->size; i++)
    {
        printf("%d: %d\n", i, copy->vector[i]);
    }
    printf("\n");
    printf("intvector\ncapacity: %lu\nsize: %lu\n", int_vector_get_capacity(intvector), int_vector_get_size(intvector));
    printf("Item 5: %d", int_vector_get_item(intvector, 5));
    printf("\n");
    int_vector_set_item(intvector, 5, 10);
    printf("Changed item 5: %d\n", int_vector_get_item(intvector, 5));
    int_vector_pop_back(intvector);
    printf("\nvector after deleting last element\n");
    for (i = 0; i < intvector->size; i++)
    {
        printf("%d: %d\n", i, intvector->vector[i]);
    }
    printf("\n");

    printf("Capacity: %lu\n", int_vector_get_capacity(intvector));
    int res = int_vector_shrink_to_fit(intvector);
    printf("new capacity: %lu\n", int_vector_get_capacity(intvector));

    printf("size: %lu\n", int_vector_get_size(intvector));
    res = int_vector_resize(intvector, 20);
    printf("new size: %lu\n", int_vector_get_size(intvector));
    for (i = 0; i < intvector->size; i++)
    {
        printf("%d: %d\n", i, intvector->vector[i]);
    }
    printf("%d %lu %lu\n", res, intvector->capacity, intvector->size);
    res = int_vector_reserve(intvector, 40);
    printf("%d %lu %lu\n", res, intvector->capacity, intvector->size);
    int_vector_free(intvector);
    int_vector_free(copy);
    return 0;
}