#include "src/matrix/matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned int) time(NULL));

    printf("=== Testing matrix_init (random) ===\n");
    matrix* A = matrix_init(3, 3, true);
    matrix_print(A);

    printf("\n=== Testing matrix_init (zero) and matrix_fill ===\n");
    matrix* B = matrix_init(3, 3, false);
    matrix_fill(B, 2.0f);
    matrix_print(B);

    printf("\n=== Testing matrix_add ===\n");
    matrix* C = matrix_add(A, B);
    matrix_print(C);

    printf("\n=== Testing matrix_add_ (in-place) ===\n");
    matrix_add_(A, B, false);
    matrix_print(A);

    printf("\n=== Testing matrix_sub ===\n");
    matrix* D = matrix_sub(C, B);
    matrix_print(D);

    printf("\n=== Testing matrix_sub_ (in-place) ===\n");
    matrix_sub_(A, B, false);
    matrix_print(A);

    printf("\n=== Testing matrix_copy ===\n");
    matrix* E = matrix_copy(B);
    matrix_print(E);

    printf("\n=== Testing matrix_scalar_mul ===\n");
    matrix* F = matrix_scalar_mul(B, 0.5f);
    matrix_print(F);

    printf("\n=== Testing matrix_scalar_mul_ (in-place) ===\n");
    matrix_scalar_mul(B, 3.0f);
    matrix_print(B);

    printf("\n=== Testing matrix_transpose ===\n");
    matrix* T = matrix_transpose(C);
    matrix_print(T);

    printf("\n=== Testing matrix_transpose_ (in-place, square only) ===\n");
    matrix_transpose_(C);
    matrix_print(C);

    printf("\n=== Testing matrix_eye ===\n");
    matrix* I = matrix_eye(4);
    matrix_print(I);

    printf("\n=== Testing matrix_trace ===\n");
    float tr = matrix_trace(I);
    printf("Trace of I: %.3f\n", tr);

    // Free all
    matrix_free(A);
    matrix_free(B);
    matrix_free(C);
    matrix_free(D);
    matrix_free(E);
    matrix_free(F);
    matrix_free(T);
    matrix_free(I);

    return 0;
}
