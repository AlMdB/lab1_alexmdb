#ifndef ADT_MATRIX_H
#define ADT_MATRIX_H

#include "adt_base.h"

#define subtraction_matrix(mt1,mtx2) addition_matrix(mtx1,-mtx2)

typedef struct Matrix{
    adt_base* data;
    int rows, cols;
}Matrix;

Matrix* create_Matrix(int rows, int cols);

Matrix* random_Matrix(int rows,int cols);

Matrix* addition_matrices(const Matrix* mtx1, const Matrix* mtx2);

Matrix* dot_product(const Matrix* mtx1, const Matrix* mtx2);

void scalar_product(Matrix* mtx, double scalar);

void scalar_addition(Matrix* mtx, double scalar);

void transpose_Matrix(Matrix* mtx);

void inverse_Matrix(Matrix* mtx);

double deteminant_Matrix(const Matrix mtx);



#endif