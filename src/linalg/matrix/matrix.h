//
// Created by recabet on 8/3/25.
//

#ifndef LINALG_MATRIX_H
#define LINALG_MATRIX_H

#include <stdint.h>
#include <stdbool.h>

typedef float float32_t;
typedef double float64_t;

struct matrix {
    uint32_t rows;
    uint32_t cols;
    float32_t* data;
};

typedef struct matrix matrix;

matrix* matrix_init(uint32_t rows, uint32_t cols, bool randomize);

void matrix_print(const matrix* m);

void matrix_free(matrix* m);

void matrix_fill(const matrix* m, float32_t val);

matrix* matrix_eye(uint32_t size);

matrix* matrix_add(const matrix* m1, const matrix* m2);

void matrix_add_(const matrix* m1, const matrix* m2, bool free_m2);

matrix* matrix_sub(const matrix* m1, const matrix* m2);

void matrix_sub_(const matrix* m1, const matrix* m2, bool free_m2);

matrix* matrix_copy(const matrix* m);

matrix* matrix_scalar_mul(const matrix* m, float32_t scalar);

matrix* matrix_transpose(const matrix* m);

void matrix_transpose_(const matrix* m);

// uint32_t matrix_rank(const matrix* m);

float32_t matrix_trace(const matrix* m);



#endif //LINALG_MATRIX_H
