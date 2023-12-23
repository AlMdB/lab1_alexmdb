#include "adt_matrix.h"
#include <stdlib.h>
#include <stdlib.h>

Matrix* create_Matrix(int rows, int cols){
    double **data = malloc(sizeof(double*)*rows*cols);
    for (int row_i = 0; row_i < rows; row_i++){
        data[row_i] = malloc(cols* sizeof(double));
        for(int col_i = 0; col_i < cols; col_i++){
            data[row_i][col_i] = rand();
        }
    }
    adt_base* newBase = create_adt(data,sizeof(double**)*rows);
    Matrix* new = malloc(sizeof(Matrix));
    new->data = newBase;
    new->rows = rows;
    new->cols = cols;
    return new;
}

Matrix* random_Matrix(int rows,int cols);

Matrix* addition_matrices(Matrix* mtx1, Matrix* mtx2){
    if(mtx1->rows != mtx2->rows || mtx1->cols != mtx2->cols){
        printf("\nOperação Inválida. Tamanhos diferentes de matrizes\n");
        return NULL;
    }
    double **newData = malloc(sizeof(double*) * mtx1->rows * mtx1->cols);
    for(int sum_rows = 0; sum_rows <mtx1->rows;sum_rows++){
        newData[sum_rows] = malloc(mtx1->cols * sizeof(double)); 
        for (int sum_cols = 0 ; sum_cols < mtx1->cols;sum_cols++){
            newData[sum_rows][sum_cols] = ((double**)(mtx1->data->data))[sum_rows][sum_cols] + ((double**)mtx2->data->data)[sum_rows][sum_cols];
        }
    }
}

Matrix* dot_product(const Matrix* mtx1, const Matrix* mtx2);

void scalar_product(Matrix* mtx, double scalar){
    for(int row_i = 0;row_i < mtx->rows ; row_i++){
        for (int col_j =0; col_j <mtx->cols ; col_j++){
            ((double**)mtx)[row_i][col_j] *= scalar;
        }
    }
}

void scalar_addition(Matrix* mtx, double scalar){
    for(int row_i = 0;row_i < mtx->rows ; row_i++){
        for (int col_j =0; col_j <mtx->cols ; col_j++){
            ((double**)mtx)[row_i][col_j] += scalar;
        }
    }
}

void transpose_Matrix(Matrix* mtx){
    for(int row_i = 0;row_i < mtx->rows ; row_i++){
        for (int col_j = row_i + 1; col_j <mtx->cols ; col_j++){
            double temp = ((double**)mtx->data->data)[row_i][col_j];
            ((double**)mtx->data->data)[row_i][col_j] = ((double**)mtx->data->data)[col_j][row_i]; 
            ((double**)mtx->data->data)[col_j][row_i] = temp;
        }
    }
};

void print_matrix(const Matrix* mtx){

}

void inverse_Matrix(Matrix* mtx);

double deteminant_Matrix(const Matrix mtx);

void delete_Matrix(Matrix* mtx);

