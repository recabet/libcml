#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "tensor.h"

typedef struct {
    Tensor *tensor1d;
} Vector;

/*
 * Creation
 */
Vector 	*vector_init(int size);
Vector 	*vector_zeros(int size);
Vector 	*vector_ones(int size);

/*
 * Memory Management
 */
void	vector_free(Vector *v);

/*
 * Operations
 */
Vector 	*vector_copy(const Vector *v);
void    vector_fill(Vector *v, float val);
void    vector_add(Vector *v1, const Vector *v2);
void    vector_sub(Vector *v1, const Vector *v2);
void    vector_scalar_mul(Vector *v, float scalar);
float   vector_dot(const Vector *v1, const Vector *v2);

/*
 * Helpers
 */
int 	vector_size(const Vector *v);
void    vector_print(const Vector *v);

#endif /* _VECTOR_H_ */
