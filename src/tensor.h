#ifndef __TENSOR_H__
#define __TENSOR_H__

typedef struct {
    float *data;
    int *shape;
    int *strides;
    int ndim;
} Tensor;

/* Creation */
Tensor *tensor_init(int ndim, const int *shape);
Tensor *tensor_zeros(int ndim, const int *shape);
Tensor *tensor_ones(int ndim, const int *shape);

/* Memory Management*/
void tensor_free(Tensor *t);

/* Operations */
Tensor *tensor_copy(Tensor *t);
void tensor_fill(Tensor *t, float value);

#endif
