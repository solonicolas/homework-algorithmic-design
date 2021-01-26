#include <stdio.h>

#include "test.h"
#include "matrix.h"
#include "strassen.h"

int main(int argc, char *argv[]) {

/**
 * all different cases that can happen
 * 
 * nxn * nxn - n power of 2
 * nxn * nxn - general value of n
 * pxn * nxp - n > p - divisible in equal blocks
 * pxn * nxp - n < p - divisible in equal blocks
 * pxn * nxp - n > p - NOT divisible in equal blocks
 * pxn * nxp - n < p - NOT divisible in equal blocks
 * pxn * nxm - p > m
 * pxn * nxm - p < m
*/
  size_t R1[8] = {1024,1000,1100,2000,1000,2200,2000,1700};
  size_t C1[8] = {1024,1000,2200,1000,2200,1000,1000,1000};
  size_t R2[8] = {1024,1000,2200,1000,2200,1000,1000,1000};
  size_t C2[8] = {1024,1000,1100,1000,1000,2200,1900,2000};

  printf("n\t\t\tStrassen's Alg.\tNaive Alg.\tSame result\n");

  size_t r1, c1, r2, c2;
  for (unsigned int j = 0; j < 7; ++j) {
    r1 = R1[j];
    c1 = C1[j];
    r2 = R2[j];
    c2 = C2[j];

    float **A = allocate_random_matrix(r1, c1);
    float **B = allocate_random_matrix(r2, c2);
    float **C0 = allocate_matrix(r1, c2);
    float **C1 = allocate_matrix(r1, c2);

    printf("%zu,%zu*%zu,%zu\t", r1, c1, r2, c2);
    fflush(stdout);

    printf("%lf\t", test(strassen_matrix_multiplication, C1, A, r1, c1, B, r2, c2));
    
    fflush(stdout);
    printf("%lf\t", test(naive_matrix_multiplication, C0, A, r1, c1, B, r2, c2));
    
    fflush(stdout);
  
    printf("%d\n", same_matrix((float const *const *const)C0,
                               (float const *const *const)C1, r1, c2));

    deallocate_matrix(A, r1);
    deallocate_matrix(B, r2);
    deallocate_matrix(C0, r1);
    deallocate_matrix(C1, r1);
  }
  return 0;
}
