#ifndef ADT_MATRIX_H
#define ADT_MATRIX_H

#include <time.h>
#include "adt_string.h"
#include "adt_base.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

#define subtraction_matrix(mt1,mtx2) addition_matrix(mtx1,-mtx2)

typedef struct Matrix{
    adt_base* data;
    int rows, cols;
}Matrix;

Matrix* zero_Matrix(int rows,int cols);

Matrix* create_Matrix(adt_string* input,int rows, int cols);

Matrix* random_Matrix(int rows,int cols);

Matrix* addition_matrices(const Matrix* mtx1, const Matrix* mtx2);

Matrix* dot_product(const Matrix* mtx1, const Matrix* mtx2);

Matrix* negate_matrix(const Matrix* mtx);

void scalar_product(Matrix* mtx, double scalar);

void scalar_addition(Matrix* mtx, double scalar);

void transpose_Matrix(Matrix* mtx);

Matrix* inverse_Matrix(const Matrix* mtx);

double determinant_Matrix(const Matrix* mtx);

void delete_Matrix(Matrix* mtx);

void print_matrix(const Matrix* mtx);

Matrix* adt_matrix_empty();

#endif