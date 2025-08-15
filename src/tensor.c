#include "tensor.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Initialize a new tensor with the given number of dimensions (ndim) and shape.
 * Returns a pointer to the tensor, or NULL if allocation fails.
 */
Tensor *
tensor_init(int ndim, const int *shape)
{
    /* TODO: Implement */
}

/*
 * Creates a new tensor of the given shape, with all elements initialized to 0.0f.
 * Returns a pointer to the tensor, or NULL if allocation fails.
 */
Tensor *
tensor_zeros(int ndim, const int *shape)
{
    Tensor *t = tensor_init(ndim, shape);
    if (!t)
        return NULL;
    tensor_fill(t, 0.0f);
    return t;
}

/*
 * Creates a new tensor of the given shape, with all elements initialized to 1.0f.
 * Returns a pointer to the tensor, or NULL if allocation fails.
 */
Tensor *
tensor_ones(int ndim, const int *shape)
{
    Tensor *t = tensor_init(ndim, shape);
    if (!t)
        return NULL;
    tensor_fill(t, 1.0f);
    return t;
}

/*
 * Frees all memory associated with a tensor, including the data, shape, strides,
 * and the Tensor struct itself.
 */
void
tensor_free(Tensor *t)
{
    /* TODO: Implement */
}

/*
 * Returns a new tensor that is a copy of the given tensor.
 */
Tensor *
tensor_copy(const Tensor *t)
{
    /* TODO: Implement */
}

/*
 * Fills all elements of the tensor with the specified value.
 * Modifies the tensor in-place.
 */
void
tensor_fill(Tensor *t, float value)
{
    /* TODO: Implement */
}

/*
 * Adds the elements of m2 to m1 in-place.
 * Both tensors must have the same shape.
 */
void
tensor_add(Tensor *m1, const Tensor *m2)
{
    /* TODO: Implement */
}

/*
 * Multiplies every element of the tensor by the given scalar in-place.
 */
void
tensor_scalar_mul(Tensor *m, float scalar)
{
    /* TODO: Implement */
}

/*
 * Subtracts the elements of m2 from m1 in-place.
 * Both tensors must have the same shape.
 */
void
tensor_sub(Tensor *m1, const Tensor *m2)
{
    /* TODO: Implement */
}

/*
 * Prints the tensor elements to stdout in a readable format.
 */
void
tensor_print(const Tensor *t)
{
    /* TODO: Implement */
}
