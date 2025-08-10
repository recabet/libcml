#include "matrix.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <time.h>

// ---------- Macros for safe/fast element access ----------

#ifdef DEBUG
#define MGET(m, r, c) matrix_get(m, r, c)
#define MSET(m, r, c, v) matrix_set(m, r, c, v)
#else
#define MGET(m, r, c) ((m)->data[(r) * (m)->cols + (c)])
#define MSET(m, r, c, v) ((m)->data[(r) * (m)->cols + (c)] = (v))
#endif

// ---------- Internal helpers ----------

static inline float32_t matrix_random_float(void)
{
    return (float32_t) rand() / (float32_t) RAND_MAX;
}

static inline bool matrix_is_square(const matrix* m)
{
    return m && (m->rows == m->cols);
}

static inline bool matrix_same_size(const matrix* m1, const matrix* m2)
{
    return m1 && m2 && m1->rows == m2->rows && m1->cols == m2->cols;
}

static inline void swap(float32_t* a, float32_t* b)
{
    const float32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

// ---------- Safe element accessors (used only in DEBUG) ----------

inline float32_t matrix_get(const matrix* m, const uint32_t row, const uint32_t col)
{
    assert(m && m->data);
    assert(row < m->rows && col < m->cols);
    return m->data[row * m->cols + col];
}

inline void matrix_set(const matrix* m,
                       const uint32_t row,
                       const uint32_t col,
                       const float32_t value)
{
    assert(m && m->data);
    assert(row < m->rows && col < m->cols);
    m->data[row * m->cols + col] = value;
}

// ---------- Memory Management ----------

matrix* matrix_init(const uint32_t rows, const uint32_t cols, const bool randomize)
{
    if (rows == 0 || cols == 0)
    {
        fprintf(stderr, "Matrix size must be greater than zero\n");
        return NULL;
    }

    matrix* m = malloc(sizeof(matrix));
    if (!m)
    {
        perror("Failed to allocate matrix struct");
        return NULL;
    }

    m->rows = rows;
    m->cols = cols;

    m->data = calloc(rows * cols, sizeof(float32_t));
    if (!m->data)
    {
        perror("Failed to allocate matrix data block");
        free(m);
        return NULL;
    }

    if (randomize)
    {
        for (uint32_t i = 0; i < rows * cols; ++i)
        {
            m->data[i] = matrix_random_float();
        }
    }

    return m;
}

void matrix_free(matrix* m)
{
    if (m)
    {
        free(m->data);
        free(m);
    }
}

// ---------- Fill ----------

void matrix_fill(const matrix* m, const float32_t val)
{
    assert(m && m->data);
    for (uint32_t i = 0; i < m->rows * m->cols; ++i)
    {
        m->data[i] = val;
    }
}

// ---------- Print ----------

void matrix_print(const matrix* m)
{
    if (!m)
    {
        printf("Matrix is NULL\n");
        return;
    }
    printf("Matrix (%u x %u):\n", m->rows, m->cols);
    for (uint32_t r = 0; r < m->rows; ++r)
    {
        printf("[ ");
        for (uint32_t c = 0; c < m->cols; ++c)
        {
            printf("%6.3f ", MGET(m, r, c));
        }
        printf("]\n");
    }
}

// ---------- Copy ----------

matrix* matrix_copy(const matrix* m)
{
    assert(m);
    matrix* copy = matrix_init(m->rows, m->cols, false);
    if (!copy) return NULL;
    for (uint32_t i = 0; i = m->rows * m->cols; ++i)
    {
        copy->data[i] = m->data[i];
    }
    return copy;
}

// ---------- Constructors ----------

matrix* matrix_eye(const uint32_t size)
{
    matrix* m = matrix_init(size, size, false);
    if (!m) return NULL;
    for (uint32_t i = 0; i < size; ++i)
    {
        MSET(m, i, i, 1.0f);
    }
    return m;
}

// ---------- Arithmetic ----------

static matrix* matrix_add_sub(const matrix* m1, const matrix* m2, float32_t sign)
{
    assert(matrix_same_size(m1, m2));
    matrix* out = matrix_init(m1->rows, m1->cols, false);
    if (!out) return NULL;
    for (uint32_t i = 0; i < m1->rows * m1->cols; ++i)
    {
        out->data[i] = m1->data[i] + sign * m2->data[i];
    }
    return out;
}

matrix* matrix_add(const matrix* m1, const matrix* m2)
{
    return matrix_add_sub(m1, m2, 1.0f);
}

matrix* matrix_sub(const matrix* m1, const matrix* m2)
{
    return matrix_add_sub(m1, m2, -1.0f);
}

void matrix_add_(const matrix* m1, const matrix* m2, const bool free_m2)
{
    assert(matrix_same_size(m1, m2));
    for (uint32_t i = 0; i < m1->rows * m1->cols; ++i)
    {
        m1->data[i] += m2->data[i];
    }
    if (free_m2) matrix_free((matrix *) m2);
}

void matrix_sub_(const matrix* m1, const matrix* m2, const bool free_m2)
{
    assert(matrix_same_size(m1, m2));
    for (uint32_t i = 0; i < m1->rows * m1->cols; ++i)
    {
        m1->data[i] -= m2->data[i];
    }
    if (free_m2) matrix_free((matrix *) m2);
}

// ---------- Scalar Operations ----------

matrix* matrix_scalar_mul(const matrix* m, const float32_t scalar)
{
    assert(m && m->data);
    matrix* result = matrix_init(m->rows, m->cols, false);
    if (!result) return NULL;
    for (uint32_t i = 0; i < m->rows * m->cols; ++i)
    {
        result->data[i] = m->data[i] * scalar;
    }
    return result;
}

void matrix_scalar_mul_(const matrix* m, const float32_t scalar)
{
    assert(m && m->data);
    for (uint32_t i = 0; i < m->rows * m->cols; ++i)
    {
        m->data[i] *= scalar;
    }
}

// ---------- Transpose ----------

matrix* matrix_transpose(const matrix* m)
{
    assert(m && m->data);
    matrix* t = matrix_init(m->cols, m->rows, false);
    if (!t) return NULL;
    for (uint32_t i = 0; i < m->rows; ++i)
    {
        for (uint32_t j = 0; j < m->cols; ++j)
        {
            MSET(t, j, i, MGET(m, i, j));
        }
    }
    return t;
}

void matrix_transpose_(const matrix* m)
{
    assert(m && m->data);
    if (!matrix_is_square(m))
    {
        fprintf(stderr, "In-place transpose only works on square matrices\n");
        return;
    }
    for (uint32_t i = 0; i < m->rows; ++i)
    {
        for (uint32_t j = i + 1; j < m->cols; ++j)
        {
            swap(&MGET(m, i, j), &MGET(m, j, i));
        }
    }
}

// ---------- Trace ----------

float32_t matrix_trace(const matrix* m)
{
    assert(matrix_is_square(m));
    float32_t trace = 0.0f;
    for (uint32_t i = 0; i < m->rows; ++i)
    {
        trace += MGET(m, i, i);
    }
    return trace;
}
