#include <assert.h>

#include "IntVector.h"

struct IntVector *int_vector_new(size_t initial_capacity)
{
    struct IntVector Vector * = (struct IntVector *)malloc(sizeof(struct IntVector)); // Выделение памяти на структуру IntVector
    if (Vector == NULL)
    {
        printf("No memory for this IntVector!!! :<");
        return NULL;
    }
    Vector->vector = (int *)malloc(initial_capacity * sizeof(int));
    if (Vector->vector == NULL)
    {
        free(Vector);
        return NULL;
    }
    Vector->size = 0;
    Vector->capacity = initial_capacity;
    return v;
}
