#include "src/linalg/matrix/matrix.h"

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
    matrix_scalar_mul_(B, 3.0f);
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

    // === Testing elementary row operations ===
    printf("\n=== Testing row swap ===\n");
    printf("Before swap rows 0 and 1:\n");
    matrix_print(A);
    matrix_row_swap_(A, 0, 1);
    printf("After swap rows 0 and 1:\n");
    matrix_print(A);

    printf("\n=== Testing row scale (multiply row 1 by 2) ===\n");
    matrix_row_scale_(A, 1, 2.0f);
    matrix_print(A);

    printf("\n=== Testing row add multiple (add 0.5 * row 1 to row 2) ===\n");
    matrix_row_add_multiple_(A, 1, 2, 0.5f);
    matrix_print(A);

    // === Testing elementary column operations ===
    printf("\n=== Testing column swap ===\n");
    printf("Before swap cols 0 and 2:\n");
    matrix_print(A);
    matrix_col_swap_(A, 0, 2);
    printf("After swap cols 0 and 2:\n");
    matrix_print(A);

    printf("\n=== Testing column scale (multiply col 1 by 0.5) ===\n");
    matrix_col_scale_(A, 1, 0.5f);
    matrix_print(A);

    printf("\n=== Testing column add multiple (add -1 * col 2 to col 0) ===\n");
    matrix_col_add_multiple_(A, 2, 0, -1.0f);
    matrix_print(A);

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
