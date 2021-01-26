#include "matrix.h"
#include <stdio.h>
#include "strassen.h"

/*
 * this function performs the element-wise
 * subtraction of B from A and put the resulting
 * sub-matrix in C. The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void sub_matrix_blocks(float **C, float const *const *const A,
                       float const *const * const B,
                       const size_t C_f_row, const size_t C_f_col,
                       const size_t A_f_row, const size_t A_f_col,
                       const size_t B_f_row, const size_t B_f_col,
                       const size_t n)
{
    for (size_t y = 0; y < n; ++y) {
      for (size_t x = 0; x < n; ++x) {
          C[y+C_f_row][x+C_f_col] =
               A[y+A_f_row][x+A_f_col] - B[y+B_f_row][x+B_f_col];
      }
    }
}

/*
 * this function performs the element-wise
 * sum of A and B and put the resulting
 * sub-matrix in C. The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void sum_matrix_blocks(float **C, float const *const *const A,
                       float const *const * const B,
                       const size_t C_f_row, const size_t C_f_col,
                       const size_t A_f_row, const size_t A_f_col,
                       const size_t B_f_row, const size_t B_f_col,
                       const size_t n)
{
    for (size_t y = 0; y < n; ++y) {
      for (size_t x = 0; x < n; ++x) {
          C[y+C_f_row][x+C_f_col] =
               A[y+A_f_row][x+A_f_col] + B[y+B_f_row][x+B_f_col];
      }
    }
}

/*
 * this function implements the naive algorithm
 * for matrix multiplication between sub-matrixes.
 * The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void naive_aux(float **C, float const *const *const A,
               float const *const * const B,
               const size_t C_f_row, const size_t C_f_col,
               const size_t A_f_row, const size_t A_f_col,
               const size_t B_f_row, const size_t B_f_col,
               const size_t n)
{
  for (size_t y = 0; y < n; ++y) {
    for (size_t x = 0; x < n; ++x) {
      float value = 0.0;
      for (size_t z = 0; z < n; ++z) {
        value += A[y + A_f_row][z + A_f_col]*B[z + B_f_row][x + B_f_col];
      }
      C[y + C_f_row][x + C_f_col] = value;
    }
  }
}

/*
 * This function implements the Strassen's algorithm
 * for matrix multiplication between sub-matrixes.
 * The result is placed in the sub-matrix C.
 * The parameters *_f_row and *_f_col
 * represents the first row and the first column,
 * respectively, of the sub-matrix we want to deal with.
 */
void strassen_aux(float **C, float const *const *const A,
                  float const *const * const B,
                  const size_t C_f_row, const size_t C_f_col,
                  const size_t A_f_row, const size_t A_f_col,
                  const size_t B_f_row, const size_t B_f_col,
                  const size_t n)
{
    if (n <= (1<<5)) {
        naive_aux(C, A, B,
                  C_f_row, C_f_col,
                  A_f_row, A_f_col,
                  B_f_row, B_f_col,
                  n);
        return;
    }

    size_t n2 = n/2; // This is the size of the blocks

    float ***S = (float ***)malloc(sizeof(float **) * 10);
    for (size_t i = 0; i < 10; ++i) {
        S[i] = allocate_matrix(n2, n2);
    }

    float ***P = (float ***)malloc(sizeof(float **) * 7);
    for (size_t i = 0; i < 7; ++i) {
        P[i] = allocate_matrix(n2, n2);
    }

    // S1 = B12 - B22
    sub_matrix_blocks(S[0], B, B,
                      0, 0,
                      B_f_row, B_f_col + n2,
                      B_f_row + n2, B_f_col + n2,
                      n2);

    // P1 = A11 x S1
    strassen_aux(P[0], A, (const float* const *const) S[0],
                 0, 0,
                 A_f_row, A_f_col,
                 0, 0,
                 n2);

    // S2 = A11 + A12
    sum_matrix_blocks(S[1], A, A,
                      0, 0,
                      A_f_row, A_f_col,
                      A_f_row, A_f_col + n2,
                      n2);


    // P2 = S2 x B22
    strassen_aux(P[1], (const float* const *const) S[1], B,
                 0, 0,
                 0, 0,
                 B_f_row + n2, B_f_col + n2,
                 n2);

    // S3 = A21 + A22
    sum_matrix_blocks(S[2], A, A,
                      0, 0,
                      A_f_row + n2, A_f_col,
                      A_f_row + n2, A_f_col + n2,
                      n2);

    // P3 = S3 x B11
    strassen_aux(P[2], (const float* const *const) S[2], B,
                 0, 0,
                 0, 0,
                 B_f_row, B_f_col,
                 n2);

    // S4 = B21 - B11
    sub_matrix_blocks(S[3], B, B,
                      0, 0,
                      B_f_row + n2, B_f_col,
                      B_f_row, B_f_col,
                      n2);

    // P4 = A22 x S4
    strassen_aux(P[3], A, (const float* const *const) S[3],
                 0, 0,
                 A_f_row + n2, A_f_col + n2,
                 0, 0,
                 n2);

    // S5 = A11 + A22
    sum_matrix_blocks(S[4], A, A,
                      0, 0,
                      A_f_row, A_f_col,
                      A_f_row + n2, A_f_col + n2,
                      n2);

    // S6 = B11 + B22
    sum_matrix_blocks(S[5], B, B,
                      0, 0,
                      B_f_row, B_f_col,
                      B_f_row + n2, B_f_col + n2,
                      n2);

    // P5 = S5 x S6
    strassen_aux(P[4], (const float* const *const) S[4],
                 (const float* const *const) S[5],
                 0, 0,
                 0, 0,
                 0, 0,
                 n2);

    // S7 = A12 - A22
    sub_matrix_blocks(S[6], A, A,
                      0, 0,
                      A_f_row, A_f_col + n2,
                      A_f_row + n2, A_f_col + n2,
                      n2);

    // S8 = B21 + B22
    sum_matrix_blocks(S[7], B, B,
                      0, 0,
                      B_f_row + n2, B_f_col,
                      B_f_row + n2, B_f_col + n2,
                      n2);

    // P6 = S7 x S8
    strassen_aux(P[5], (const float* const *const) S[6],
                 (const float* const *const) S[7],
                 0, 0,
                 0, 0,
                 0, 0,
                 n2);

    // S9 = A11 - A21
    sub_matrix_blocks(S[8], A, A,
                      0, 0,
                      A_f_row, A_f_col,
                      A_f_row + n2, A_f_col,
                      n2);

    // S10 = B11 + B12
    sum_matrix_blocks(S[9], B, B,
                      0, 0,
                      B_f_row, B_f_col,
                      B_f_row, B_f_col + n2,
                      n2);

    // P7 = S9 x S10
    strassen_aux(P[6], (const float* const *const) S[8],
                 (const float* const *const) S[9],
                 0, 0,
                 0, 0,
                 0, 0,
                 n2);

    // C11 = P5 + P4 - P2 + P6
    sum_matrix_blocks(C, (const float* const *const) P[4],
                      (const float* const *const) P[3],
                      C_f_row, C_f_col,
                      0, 0,
                      0, 0,
                      n2);
    sub_matrix_blocks(C, (const float* const *const) C,
                      (const float* const *const) P[1],
                      C_f_row, C_f_col,
                      C_f_row, C_f_col,
                      0, 0,
                      n2);
    sum_matrix_blocks(C, (const float* const *const) C,
                      (const float* const *const) P[5],
                      C_f_row, C_f_col,
                      C_f_row, C_f_col,
                      0, 0,
                      n2);

    // C12 = P1 + P2
    sum_matrix_blocks(C, (const float* const *const) P[0],
                      (const float* const *const) P[1],
                      C_f_row, C_f_col+n2,
                      0, 0,
                      0, 0,
                      n2);

    // C21 = P3 + P4
    sum_matrix_blocks(C, (const float* const *const) P[2],
                      (const float* const *const) P[3],
                      C_f_row+n2, C_f_col,
                      0, 0,
                      0, 0,
                      n2);

    // C22 = P5 + P1 - P3 - P7
    sum_matrix_blocks(C, (const float* const *const) P[4],
                      (const float* const *const) P[0],
                      C_f_row+n2, C_f_col+n2,
                      0, 0,
                      0, 0,
                      n2);
    sub_matrix_blocks(C, (const float* const *const) C,
                      (const float* const *const) P[2],
                      C_f_row+n2, C_f_col+n2,
                      C_f_row+n2, C_f_col+n2,
                      0, 0,
                      n2);
    sub_matrix_blocks(C, (const float* const *const) C,
                      (const float* const *const) P[6],
                      C_f_row+n2, C_f_col+n2,
                      C_f_row+n2, C_f_col+n2,
                      0, 0,
                      n2);
    
    for (size_t i = 0; i < 10; ++i) {
      deallocate_matrix(S[i], n2);
    }
    free(S);
    
    for (size_t i = 0; i < 7; ++i) {
      deallocate_matrix(P[i], n2);
    }
    free(P);   
}

/*
 * This function deals with square matrices
 */
void strassen_square_matrix_multiplication(float **C, float const *const *const A,
                                                      float const *const *const B, size_t n,
                                                      size_t C_f_row, size_t C_f_col)
{
  //Check if the dim is a power of two
  size_t p = 1;
  while(p < n)
    p *= 2;

  if(p != n) {

    float **Aaux = allocate_zero_matrix(p,p);
    float **Baux = allocate_zero_matrix(p,p);
    float **Caux = allocate_matrix(p,p);
    
    size_t i,j;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        Aaux[i][j] = A[i][j];
        Baux[i][j] = B[i][j];
      }
    }

    strassen_aux(Caux, (const float* const *const) Aaux, 
                        (const float* const *const) Baux, 
                        0, 0, 0, 0, 0, 0, p);

    // copy back the results
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
        C[i][j] = Caux[i][j];

    deallocate_matrix(Aaux, p);
    deallocate_matrix(Baux, p);
    deallocate_matrix(Caux, p);

  } else
      strassen_aux(C, A, B, 0, 0, 0, 0, 0, 0, p);
}

/*
 * This function deals with rectangular matrices
 */
void strassen_rectangular(float **C, size_t dimC1, size_t dimC2,
                          float const *const *const A, size_t r1, size_t c1,
                          float const *const *const B, size_t r2, size_t c2)
{
  size_t i, j, k, z, dim, n, rest;
  float **Aaux, **Baux, **Caux;

  Caux = allocate_matrix(r1,c2);
  
  // case horizzontal * vertical 
  if(r1 < c1) {
    dim = r1;
    n = c1 / dim;
    rest =  c1%dim;

    Aaux = allocate_zero_matrix(dim,dim);
    Baux = allocate_zero_matrix(dim,dim);

    for(k = 0; k < n; ++k) {

      for (i = 0; i < dim; ++i)
        for (j = dim*k; j < dim*k+dim; ++j)
          Aaux[i][j-dim*k] = A[i][j];

      for (i = dim*k; i < dim*k+dim; ++i)
        for (j = 0; j < dim; ++j)
          Baux[i-dim*k][j] = B[i][j];

      strassen_square_matrix_multiplication(Caux, (const float* const *const) Aaux, 
                                              (const float* const *const) Baux, dim, 0, 0);

      // copy back the results
      for (i = 0; i < dimC1; ++i)
        for (j = 0; j < dimC2; ++j)
          C[i][j] += Caux[i][j];
    }

    // rest of the matrices
    if(rest != 0) {
      float **Arest =allocate_zero_matrix(dim, rest);
      float **Brest =allocate_zero_matrix(rest, dim);
      float **Crest =allocate_zero_matrix(dim, dim);
      
      for (i = 0; i < dim; ++i)
        for (j = dim*n; j < dim*n+rest; ++j)
          Arest[i][j-dim*n] = A[i][j];

      for (i = dim*n; i < dim*n+rest; ++i)
        for (j = 0; j < dim; ++j)
          Brest[i-dim*n][j] = B[i][j];

      strassen_matrix_multiplication(Crest, (const float* const *const) Arest, dim, rest, 
                                          (const float* const *const) Brest, rest, dim);
      // copy back the results
      for (i = 0; i < dimC1; ++i)
        for (j = 0; j < dimC2; ++j)
          C[i][j] += Crest[i][j];

      deallocate_matrix(Arest, dim);
      deallocate_matrix(Brest, rest);
      deallocate_matrix(Crest, rest);
    }
       
  } else { // case vetical * horizzontal
    dim = c1;
    n = r1 / dim;
    rest =  r1%dim;
    
    Aaux =allocate_zero_matrix(dim,dim);
    Baux =allocate_zero_matrix(dim,dim);
  
    for(z = 0; z < n; ++z) {

      for (i = dim*z; i < dim*z+dim; ++i)
        for (j = 0; j < dim; ++j)
          Aaux[i-dim*z][j] = A[i][j];
      
      for(k = 0; k < n; ++k) {

        for (i = 0; i < dim; ++i)
          for (j = dim*k; j < dim*k+dim; ++j)
            Baux[i][j-dim*k] = B[i][j];
 
        strassen_square_matrix_multiplication(Caux, (const float* const *const) Aaux, 
                                               (const float* const *const) Baux, dim, z, k);
        // copy back the results
        for (i = dim*z; i < dim*z+dim; ++i)
          for (j = dim*k; j < dim*k+dim; ++j)
            C[i][j] = Caux[i-dim*z][j-dim*k];
      }

      // rest of the matrices
      if(rest != 0) {
        float **Brest =allocate_zero_matrix(dim, rest);
        float **Crest =allocate_zero_matrix(dim, rest);

        for (i = 0; i < dim; ++i)
          for (j = dim*n; j < dim*n+rest; ++j)
            Brest[i][j-(dim*n)] = B[i][j];

        strassen_matrix_multiplication(Crest, (const float* const *const) Aaux, dim, dim, 
                                            (const float* const *const) Brest, dim, rest);

        // copy back the results
        for (i = dim*z; i < dim*z+dim; ++i)
          for (j = dim*n; j < dimC2; ++j)
            C[i][j] = Crest[i-dim*z][j-(dim*n)];

        deallocate_matrix(Brest, rest);
        deallocate_matrix(Crest, dim);
      }  
    }
    
    // rest of the matrices
    if(rest != 0) {
      float **Arest =allocate_zero_matrix(rest, dim);
      float **Brest =allocate_zero_matrix(dim, rest);
      float **Crest =allocate_zero_matrix(rest, dim);

      for (i = dim*n; i < dim*n+rest; ++i)
        for (j = 0; j < dim; ++j)
          Arest[i-(dim*n)][j] = A[i][j];

      for(k = 0; k < n; ++k) {

        for (i = 0; i < dim; ++i)
          for (j = dim*k; j < dim*k+dim; ++j)
            Baux[i][j-dim*k] = B[i][j];
  
        strassen_matrix_multiplication(Crest, (const float* const *const) Arest, rest, dim, 
                                            (const float* const *const) Baux, dim, dim);
        
        // copy back the results
        for (i = dim*n; i < dim*n+rest; ++i)
          for (j = dim*k; j < dim*k+dim; ++j)
            C[i][j] = Crest[i-dim*n][j-(dim*k)];   
      }

      for (i = 0; i < dim; ++i)
        for (j = dim*n; j < dim*n+rest; ++j)
          Brest[i][j-(dim*n)] = B[i][j];

      Crest = allocate_zero_matrix(rest, rest);
      strassen_matrix_multiplication(Crest, (const float* const *const) Arest, rest, dim, 
                                            (const float* const *const) Brest, dim, rest);

      // copy back the results
      for (i = dim*n; i < dimC1; ++i)
        for (j = dim*n; j < dimC2; ++j)
          C[i][j] = Crest[i-(dim*n)][j-(dim*n)];

      deallocate_matrix(Arest, rest);
      deallocate_matrix(Brest, rest);
      deallocate_matrix(Crest, rest);   
    } 
  }

  deallocate_matrix(Aaux, dim);
  deallocate_matrix(Baux, dim);
  deallocate_matrix(Caux, r1);
}

/*
 * This function adds dimensions to a matrix adding zeros
 */
void strassen_add_dimension(float **C, float const *const *const A,
                            size_t r1, size_t c1,
                            float const *const *const B,
                            size_t r2, size_t c2)
{
  size_t old_dim;

                // case p,n * n,m     
  if(r1 > c2) { // p > m

    // adding columns to B
    float **B2 =allocate_zero_matrix(r2,r1);
      
    // copy old values of B
    for (size_t i = 0; i < r2; ++i)
      for (size_t j = 0; j < c2; ++j)
        B2[i][j] = B[i][j];

    old_dim = c2;
    c2 = r1;

    float **Caux = allocate_matrix(r1,c2);

    strassen_rectangular(Caux, r1, c2,
                            (const float* const *const) A, r1, c1,
                            (const float* const *const) B2, r2, c2);

    // copy back the results
      for (size_t i = 0; i < r1; ++i)
        for (size_t j = 0; j < old_dim; ++j)
          C[i][j] = Caux[i][j];

    deallocate_matrix(Caux, r1);
  } 
  else {   // p < m    

    // adding rows to A 
    float **A2 =allocate_zero_matrix(c2,c1);
      
    // copy old values of A
    for (size_t i = 0; i < r1; ++i)
      for (size_t j = 0; j < c1; ++j)
        A2[i][j] = A[i][j];

    old_dim = r1;
    r1 = c2;

    float **Caux = allocate_matrix(r1,c2);

    strassen_rectangular(Caux, r1, c2,
                            (const float* const *const) A2, r1, c1,
                            (const float* const *const) B, r2, c2);

    // copy back the results
    for (size_t i = 0; i < old_dim; ++i)
      for (size_t j = 0; j < c2; ++j)
        C[i][j] = Caux[i][j];

    deallocate_matrix(Caux, r1);  
  }
}

void strassen_matrix_multiplication(float **C, float const *const *const A,
                                    size_t r1, size_t c1,
                                    float const *const *const B, 
                                    size_t r2, size_t c2)
{
  if(r1 == c1 && c1 == r2 && r2 == c2) { // case n,n * n,n

    strassen_square_matrix_multiplication(C, A, B, r1, 0, 0);

  } else if (r1 != c2) { // case p,n * n,m

    strassen_add_dimension(C, A, r1, c1, B, r2, c2);
    
  } else { // case p,n * n,p

    strassen_rectangular(C, r1, c2,
                            (const float* const *const) A, r1, c1,
                            (const float* const *const) B, r2, c2);
  }
}