#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "tensor.h"

typedef struct {
    Tensor *tensor2d;
} Matrix;

/*
 * Creation
 */
Matrix 	*matrix_init(const int rows, const int cols);
Matrix 	*matrix_zeros(const int rows, const int cols);
Matrix 	*matrix_ones(const int rows, const int cols);
Matrix 	*matrix_eye(const int size);

/*
 * Memory Management
 */
void 	matrix_free(Matrix *m);

/*
 * Operations
 */
Matrix 	*matrix_copy(const Matrix *m);
void 	matrix_add(Matrix *m1, const Matrix *m2);
void 	matrix_scalar_mul(Matrix *m, float scalar);
void 	matrix_sub(Matrix *m1, const Matrix *m2);
void 	matrix_transpose(Matrix *m);
void 	matrix_fill(Matrix *m, float val);
float 	matrix_trace(const Matrix *m);
int 	matrix_rank(const Matrix *m);

/*
 * Helpers
 */
int 	matrix_cols(const Matrix *m);
int 	matrix_rows(const Matrix *m);
void 	matrix_print(const Matrix *m);

#endif /* _MATRIX_H_ */
