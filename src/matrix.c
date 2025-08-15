#include "tensor.h"
#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

/*
 *   Creates a new matrix with the given number of rows and columns.
 *   Returns a pointer to the Matrix or NULL if allocation fails.
 */
Matrix *
matrix_init(const int rows, const int cols)
{
	int shape[2] = { rows, cols };
	Tensor *t = tensor_init(2, shape);
	if (!t)
		return NULL;

	Matrix *m = malloc(sizeof(Matrix));
	if (!m) {
		tensor_free(t);
		return NULL;
	}

	m->tensor2d = t;
	return m;
}

/*
 *   Creates a new matrix with all elements initialized to 0.0f.
 *   Returns a pointer to the Matrix, or NULL if allocation fails.
 */
Matrix 	*
matrix_zeros(const int rows, const int cols)
{
	Matrix *m = matrix_init(rows, cols);
	if (!m)
		return NULL;
	matrix_fill(m, 0.0f);

	return m;
}

/*
 *   Creates a new matrix with all elements initialized to 1.0f.
 *   Returns a pointer to the Matrix, or NULL if allocation fails.
 */
Matrix 	*
matrix_ones(const int rows, const int cols)
{
	Matrix *m = matrix_init(rows, cols);
	if (!m)
		return NULL;
	matrix_fill(m, 1.0f);

	return m;
}

/*
 *   Creates an identity matrix of the given size.
 *   Returns a pointer to the Matrix, or NULL if allocation fails.
 */
Matrix 	*
matrix_eye(const int size)
{
	/* TODO: implement */
}

/*
 *   Frees the memory allocated for the matrix and its underlying tensor.
 */
void
matrix_free(Matrix *m)
{
	tensor_free(m->tensor2d);
	free(m);
}

/*
 *   Returns a copy of the given matrix.
 *   Returns NULL if allocation fails.
 */
Matrix *
matrix_copy(const Matrix *m)
{
	Tensor *t = tensor_copy(m->tensor2d);
	if (!t)
		return NULL;

	Matrix *m_copy = malloc(sizeof(Matrix));
	if (!m_copy) {
		tensor_free(t);
		return NULL;
	}

	m_copy->tensor2d = t;
	return m_copy;
}

/*
 * Adds m2 to m1 in-place.
 * Both matrices must have the same dimensions.
 */
void
matrix_add(Matrix *m1, const Matrix *m2)
{
	tensor_add(m1->tensor2d, m2->tensor2d);
}

/*
 * Multiplies all elements of the matrix by the given scalar in-place.
 */
void
matrix_scalar_mul(Matrix *m, float scalar)
{
	tensor_scalar_mul(m->tensor2d, scalar);
}

/*
 * Subtracts m2 from m1 in-place.
 * Both matrices must have the same dimensions.
 */
void
matrix_sub(Matrix *m1, const Matrix *m2)
{
	tensor_sub(m1->tensor2d, m2->tensor2d);
}

/*
 * Transposes the matrix in-place.
 */
void
matrix_transpose(Matrix *m)
{
	/* TODO: Implement */
}

/*
 * Fills all elements of the matrix with the given value in-place.
 */
void
matrix_fill(Matrix *m, float val)
{
	tensor_fill(m->tensor2d, val);
}

/*
 * Returns the sum of the diagonal elements of the matrix.
 */
float
matrix_trace(const Matrix *m)
{
	/* TODO: Implement */
}

/*
 * Returns the rank of the matrix.
 */
int
matrix_rank(const Matrix *m)
{
	/* TODO: Implement */
}

/*
 * Returns the number of columns in the matrix.
 */
int
matrix_cols(const Matrix *m)
{
	return m->tensor2d->shape[1];
}

/*
 * Returns the number of rows in the matrix.
 */
int
matrix_rows(const Matrix *m)
{
	return m->tensor2d->shape[0];
}

/*
 * Prints the matrix to stdout in a readable format.
 */
void
matrix_print(const Matrix *m)
{
	tensor_print(m->tensor2d);
}
