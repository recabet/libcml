#ifndef LINALG_MATRIX_H
#define LINALG_MATRIX_H

#include "tensor.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    Tensor *tensor2d;
} Matrix;

typedef float float32_t;
typedef double float64_t;

Matrix* matrix_add(const Matrix* m1, const Matrix* m2);
Matrix* matrix_copy(const Matrix* m);
Matrix* matrix_eye(uint32_t size);
Matrix* matrix_init(uint32_t rows, uint32_t cols, bool randomize);
Matrix* matrix_scalar_mul(const Matrix* m, float32_t scalar);
Matrix* matrix_sub(const Matrix* m1, const Matrix* m2);
Matrix* matrix_transpose(const Matrix* m);
float matrix_trace(const Matrix* m);
uint32_t matrix_rank(const Matrix* m);
void matrix_add_(const Matrix* m1, const Matrix* m2, bool free_m2);
void matrix_fill(const Matrix* m, float32_t val);
void matrix_free(Matrix* m);
void matrix_print(const Matrix* m);
void matrix_sub_(const Matrix* m1, const Matrix* m2, bool free_m2);
void matrix_transpose_(const Matrix* m);

#endif
