//
// Created by recabet on 8/3/25.
//

#ifndef CML_LINALG_MATRIX_H
#define CML_LINALG_MATRIX_H


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

float32_t matrix_get(const matrix* m, uint32_t row, uint32_t col);

void matrix_set(const matrix* m, uint32_t row, uint32_t col, float32_t value);

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

void matrix_scalar_mul_(const matrix* m, float32_t scalar);

matrix* matrix_transpose(const matrix* m);

void matrix_transpose_(const matrix* m);

// uint32_t matrix_rank(const matrix* m);

float32_t matrix_trace(const matrix* m);

void matrix_row_swap_(const matrix* m, uint32_t r1, uint32_t r2);

void matrix_row_scale_(const matrix* m, uint32_t r, float32_t scalar);

void matrix_row_add_multiple_(const matrix* m, uint32_t src, uint32_t dst, float32_t scalar);

void matrix_col_swap_(const matrix* m, uint32_t c1, uint32_t c2);

void matrix_col_scale_(const matrix* m, uint32_t c, float32_t scalar);

void matrix_col_add_multiple_(const matrix* m, uint32_t src, uint32_t dst, float32_t scalar);

#endif //CML_LINALG_MATRIX_H
