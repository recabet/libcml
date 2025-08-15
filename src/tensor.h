#ifndef _TENSOR_H_
#define _TENSOR_H_

typedef struct {
    float *data;
    int *shape;
    int *strides;
    int ndim;
} Tensor;

/*
 * Creation
 */
Tensor 	*tensor_init(const int ndim, const int *shape);
Tensor 	*tensor_zeros(const int ndim, const int *shape);
Tensor 	*tensor_ones(const int ndim, const int *shape);

/*
 * Memory Management
 */
void 	tensor_free(Tensor *t);

/*
 * Operations
 */
Tensor 	*tensor_copy(const Tensor *t);
void 	tensor_fill(Tensor *t, float value);
void 	tensor_add(Tensor *m1, const Tensor *m2);
void 	tensor_scalar_mul(Tensor *m, float scalar);
void 	tensor_sub(Tensor *m1, const Tensor *m2);

/*
 * Helpers
 */
void 	tensor_print(const Tensor *t);

#endif /* _TENSOR_H_ */
