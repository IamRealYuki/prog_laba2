#include <assert.h>

#include "IntVector.h"

struct IntVector *int_vector_new(size_t initial_capacity)
{
    if (initial_capacity < 0)
    {
        printf("Ёмкость не может быть отрицательной");
        return NULL;
    }
    struct IntVector *Vector = (struct IntVector *)malloc(sizeof(struct IntVector));
    if (Vector == NULL)
    {
        printf("Возникла непредвиденная ошибка. Попробуйте ещё раз.");
        return NULL;
    }
    Vector->vector = (int *)malloc(initial_capacity * sizeof(int));
    if (Vector->vector == NULL)
    {
        printf("Возникла непредвиденная ошибка. Попробуйте ещё раз.");
        free(Vector);
        return NULL;
    }
    Vector->size = 0;
    Vector->capacity = initial_capacity;
    return Vector;
}

struct IntVector *int_vector_copy(const struct IntVector *Vector)
{
    if (Vector == NULL)
    {
        printf("Массива не существует");
        return NULL;
    }
    struct IntVector *copy = int_vector_new(Vector->capacity);
    if (copy == NULL)
    {
        printf("Возникла непредвиденная ошибка. Попробуйте ещё раз.");
        return NULL;
    }
    copy->size = Vector->size;
    for (int i = 0; i < Vector->size; i++)
    {
        copy->vector[i] = Vector->vector[i];
    }
    return copy;
}

void int_vector_free(struct IntVector *Vector)
{
    free(Vector->vector);
    free(Vector);
}

int int_vector_get_item(const struct IntVector *Vector, size_t index)
{
    if (Vector != NULL)
        return Vector->vector[index];
    return -1;
}

void int_vector_set_item(struct IntVector *Vector, size_t index, int item)
{
    if (Vector != NULL)
        Vector->vector[index] = item;
}

size_t int_vector_get_size(const struct IntVector *Vector)
{
    if (Vector != NULL)
        return Vector->size;
    printf("Массива не существует");
    return -1;
}

size_t int_vector_get_capacity(const struct IntVector *Vector)
{
    if (Vector != NULL)
        return Vector->capacity;
    printf("Массива не существует");
    return -1;
}

int int_vector_push_back(struct IntVector *Vector, int item)
{
    if (Vector == NULL)
    {
        printf("Массива не существует");
        return -1;
    }
    if (Vector->capacity > Vector->size)
    {
        Vector->vector[Vector->size] = item;
        Vector->size++;
        return 0;
    }
    else
    {
        if (Vector->capacity == 0)
            Vector->capacity = 1;
        Vector->vector = (int *)realloc(Vector->vector, sizeof(int) * Vector->capacity * 2);
        Vector->vector[Vector->size] = item;
        Vector->size++;
        Vector->capacity = Vector->capacity * 2;
        return 0;
    }
    return -1;
}

void int_vector_pop_back(struct IntVector *Vector)
{
    if (Vector == NULL)
    {
        printf("Массива нет");
        return;
    }
    if (Vector->size == 0)
        return;
    Vector->vector[Vector->size - 1] = 0;
    Vector->size--;
}

int int_vector_shrink_to_fit(struct IntVector *Vector)
{
    if (Vector == NULL)
    {
        printf("Массива нет");
        return -1;
    }
    Vector->vector = (int *)realloc(Vector->vector, sizeof(int) * Vector->size);
    if (Vector->vector == NULL)
    {
        printf("Возникла непредвиденная ошибка. Попробуйте ещё раз.");
        return -1;
    }
    Vector->capacity = Vector->size;
    return 0;
}

int int_vector_resize(struct IntVector *Vector, size_t new_size)
{
    if (Vector == NULL)
    {
        printf("Массива нет");
        return -1;
    }
    if (Vector->size > new_size)
    {
        return int_vector_shrink_to_fit(Vector);
    }
    else
    {
        for (int i = Vector->size; i < new_size; i++)
        {
            int_vector_push_back(Vector, 0);
        }
        return 0;
    }
}

int int_vector_reserve(struct IntVector *Vector, size_t new_capacity)
{
    if (Vector == NULL)
    {
        printf("Массива нет");
        return -1;
    }
    if (new_capacity <= Vector->capacity)
        return 0;
    struct IntVector *tmp_vector = int_vector_copy(Vector);
    Vector->vector = (int *)realloc(Vector->vector, sizeof(int) * new_capacity);
    if (Vector == NULL)
    {
        Vector->vector = tmp_vector->vector;
        int_vector_free(tmp_vector);
        return -1;
    }
    else
    {
        Vector->capacity = new_capacity;
        int_vector_free(tmp_vector);
        return 0;
    }
}