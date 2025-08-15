#include "tensor.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Initialize a new vector of given size.
 * Returns a pointer to the vector, or NULL if allocation fails.
 */
Vector 	*
vector_init(int size)
{
	int shape[1] = { size };
	Tensor *t = tensor_init(1, shape);
	if (!t)
		return NULL;

	Vector *v = malloc(sizeof(Vector));
	if (!v) {
		tensor_free(t);
		return NULL;
	}

	v->tensor1d = t;
	return v;
}

/*
 * Create a new vector of given size filled with zeros.
 * Returns a pointer to the vector, or NULL if allocation fails.
 */
Vector 	*
vector_zeros(int size)
{
	Vector *v = vector_init(size);
	if (!v)
		return NULL;
	vector_fill(v, 0.0f);

	return v;
}

/*
 * Create a new vector of given size filled with ones.
 * Returns a pointer to the vector, or NULL if allocation fails.
 */
Vector 	*
vector_ones(int size)
{
	Vector *v = vector_init(size);
	if (!v)
		return NULL;
	vector_fill(v, 1.0f);

	return v;
}

/*
 * Free the memory of a vector and its underlying tensor.
 */
void
vector_free(Vector *v)
{
	tensor_free(v->tensor1d);
	free(v);
}

/*
 * Create a copy of a vector.
 * Returns a pointer to the new vector, or NULL if allocation fails.
 */
Vector *
vector_copy(const Vector *v)
{
	Tensor *t = tensor_copy(v->tensor1d);
	if (!t)
		return NULL;

	Vector *v_copy = malloc(sizeof(Vector));
	if (!v_copy) {
		tensor_free(t);
		return NULL;
	}

	v_copy->tensor1d = t;
	return v_copy;
}

/*
 * Fill all elements of a vector with the given value.
 */
void
vector_fill(Vector *v, float val)
{
	tensor_fill(v->tensor1d, val);
}

/*
 * Add another vector to this vector in-place.
 */
void
vector_add(Vector *v1, const Vector *v2)
{
	tensor_add(v1->tensor1d, v2->tensor1d);
}

/*
 * Subtract another vector from this vector in-place.
 */
void
vector_sub(Vector *v1, const Vector *v2)
{
	tensor_sub(v1->tensor1d, v2->tensor1d);
}

/*
 * Multiply all elements of a vector by a scalar in-place.
 */
void
vector_scalar_mul(Vector *v, float scalar)
{
	tensor_scalar_mul(v->tensor1d, scalar);
}

/*
 * Returns the dot product of two vectors.
 */
float
vector_dot(const Vector *v1, const Vector *v2)
{
	/* TODO: Implement */
}
