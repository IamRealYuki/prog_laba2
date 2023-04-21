#ifndef IntVector_h_included
#define IntVector_h_included
#include <stdio.h>
#include <malloc.h>
#define size_t unsigned long int

struct IntVector
{
    int *vector;     /*указатель на начало массива*/
    size_t size;     /*размер массива*/
    size_t capacity; /*ёмкость массива*/
};

struct IntVector *int_vector_new(size_t initial_capasity);

struct IntVector *int_vector_copy(const struct IntVector *v);

void int_vector_free(struct IntVector *v);

int int_vector_get_item(const struct IntVector *v, size_t index);

void int_vector_set_item(struct IntVector *v, size_t index, int item);

size_t int_vector_get_size(const struct IntVector *v);

size_t int_vector_get_capacity(const struct IntVector *v);

int int_vector_push_back(struct IntVector *v, int item);

void int_vector_pop_back(struct IntVector *v);

int int_vector_shrink_to_fit(struct IntVector *v);

int int_vector_resize(struct IntVector *v, size_t new_size);

int int_vector_reserve(struct IntVector *v, size_t new_capacity);

#endif