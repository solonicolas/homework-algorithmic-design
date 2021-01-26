#ifndef __MATRIX__
#include <stdlib.h>

void naive_matrix_multiplication(float **C, 
                                float const *const *const A, const size_t r1, const size_t c1,
                                float const *const *const B, const size_t r2, const size_t c2
                                );

int same_matrix(float const *const *const A, float const *const *const B,
                const size_t rows, const size_t cols);

float **allocate_matrix(const size_t rows, const size_t cols);
void deallocate_matrix(float **A, const size_t rows);


float **allocate_random_matrix(const size_t rows, const size_t cols);
float **allocate_zero_matrix(const size_t rows, const size_t cols);
#endif //__MATRIX__
