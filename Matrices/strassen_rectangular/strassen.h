#ifndef __STRASSEN__

void strassen_matrix_multiplication(float **C, float const *const *const A,
                                    size_t r1, size_t c1,
                                    float const *const *const B, 
                                    size_t r2, size_t c2);
#endif //__STRASSEN__
