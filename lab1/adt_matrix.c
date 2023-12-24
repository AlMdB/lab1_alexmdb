#include "adt_matrix.h"

Matrix* create_Matrix(adt_string* input, int rows, int cols) {

    double** data = malloc(sizeof(double*) * rows);

    for (int row_i = 0; row_i < rows; row_i++) {
        data[row_i] = malloc(cols * sizeof(double));
        memset(data[row_i], 0, cols * sizeof(double));
    }

    char* inputStr = (char*)input->base->data; 
    char* token = strtok(inputStr, " ");


    for (int row_i = 0; row_i < rows; row_i++) {
        for (int col_j = 0; col_j < cols; col_j++) {
            if (token == NULL) {
                printf("\nQuantidade insuficiente de dados para criar matriz\n");
                return NULL;
            }
            data[row_i][col_j] = atof(token);
            token = strtok(NULL, " ");
        }
    }

    adt_base* newBase = create_adt(data, sizeof(double**) * rows);
    
    Matrix* newMatrix = malloc(sizeof(Matrix));
    newMatrix->data = newBase;
    newMatrix->rows = rows;
    newMatrix->cols = cols;
    
    return newMatrix;
}


Matrix* random_Matrix(int rows,int cols){
    srand(time(NULL));
    double **data = malloc(sizeof(double*)*rows*cols);
    for (int row_i = 0; row_i < rows; row_i++){
        data[row_i] = malloc(cols* sizeof(double));
        for(int col_i = 0; col_i < cols; col_i++){
            double annex = (rand()%999)+1;
            data[row_i][col_i] = annex;
            printf("%lf %lf \n",annex,data[row_i][col_i]);
        }
    }
    adt_base* newBase = create_adt(data,sizeof(double**)*rows);
    Matrix* new = malloc(sizeof(Matrix));
    new->data = newBase;
    new->rows = rows;
    new->cols = cols;
    return new;
}

Matrix* zero_Matrix(int rows,int cols){
    double **data = malloc(sizeof(double*)*rows*cols);
    for (int row_i = 0; row_i < rows; row_i++){
        data[row_i] = malloc(cols* sizeof(double));
        for(int col_i = 0; col_i < cols; col_i++){
            data[row_i][col_i] = 0;
        }
    }
    adt_base* newBase = create_adt(data,sizeof(double**)*rows);
    Matrix* new = malloc(sizeof(Matrix));
    new->data = newBase;
    new->rows = rows;
    new->cols = cols;
    return new;
}


Matrix* addition_matrices(const Matrix* mtx1, const Matrix* mtx2) {
    if (mtx1->rows != mtx2->rows || mtx1->cols != mtx2->cols) {
        printf("\noperação invalida. matrizes de tamanho diferente\n");
        return NULL;
    }

    Matrix* result = zero_Matrix(mtx1->rows,mtx1->cols);

    for (int i = 0; i < mtx1->rows; i++) {
        for (int j = 0; j < mtx1->cols; j++) {
            ((double**)result->data->data)[i][j] = ((double**)mtx1->data->data)[i][j] + ((double**)mtx2->data->data)[i][j];
        }
    }

    return result;
}

void scalar_product(Matrix* mtx, double scalar) {
    for (int i = 0; i < mtx->rows; i++) {
        for (int j = 0; j < mtx->cols; j++) {
            ((double**)mtx->data->data)[i][j] *= scalar;
        }
    }
}

void scalar_addition(Matrix* mtx, double scalar) {
    for (int i = 0; i < mtx->rows; i++) {
        for (int j = 0; j < mtx->cols; j++) {
            ((double**)mtx->data->data)[i][j] += scalar;
        }
    }
}

void transpose_Matrix(Matrix* mtx) {
    for (int i = 0; i < mtx->rows; i++) {
        for (int j = i + 1; j < mtx->cols; j++) {
            double temp = ((double**)mtx->data->data)[i][j];
            ((double**)mtx->data->data)[i][j] = ((double**)mtx->data->data)[j][i];
            ((double**)mtx->data->data)[j][i] = temp;
        }
    }
}


Matrix* dot_product(const Matrix* mtx1, const Matrix* mtx2) {
    if (mtx1->cols != mtx2->rows) {
        printf("\nInvalid Operation. Matrix dimensions mismatch.\n");
        return NULL;
    }

    Matrix* result = zero_Matrix(mtx1->rows,mtx1->cols);

    for (int i = 0; i < mtx1->rows; i++) {
        for (int j = 0; j < mtx2->cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < mtx1->cols; k++) { // No Dot Prodcut, o elemento[i][j] da nova matriz possui varias interpretações, aqui se seguiu a ideia da somatoria, onde 1,1 equivale a um somatorio dos elementos da primeira linha da matriz 1 com a primeira colubna da matriz 2
                sum += ((double**)mtx1->data->data)[i][k] * ((double**)mtx2->data->data)[k][j];
            }
            ((double**)result->data->data)[i][j] = sum;
        }
    }

    return result;
}

Matrix* negate_matrix(const Matrix* mtx) {
    Matrix* result = zero_Matrix(mtx->rows,mtx->cols);

    for (int i = 0; i < mtx->rows; i++) {
        for (int j = 0; j < mtx->cols; j++) {
            ((double**)result->data->data)[i][j] = -((double**)mtx->data->data)[i][j];
        }
    }

    return result;
}

void print_matrix(const Matrix* mtx) {
    for (int i = 0; i < mtx->rows; i++) {
        for (int j = 0; j < mtx->cols; j++) {
            printf(" %.2lf ", ((double**)mtx->data->data)[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix* inverse_Matrix(const Matrix* mtx) {
    if (mtx->rows != mtx->cols) {
        printf("\nInvalid Operation. Matrix must be square for inversion.\n");
        return NULL;
    }

    Matrix* identity = zero_Matrix(mtx->rows,mtx->cols);
    for (int i = 0; i < mtx->rows; i++) {
        ((double**)identity->data->data)[i][i] = 1.0;
    }
    Matrix* copy = zero_Matrix(mtx->rows,mtx->cols);
    for (int i = 0; i < mtx->rows; i++) {
        for (int j = 0; j < mtx->cols; j++) {
            ((double**)copy->data->data)[i][j] = ((double**)mtx->data->data)[i][j];
        }
    }

    for (int i = 0; i < mtx->rows; i++) {
        double pivot = ((double**)copy->data->data)[i][i];

        if (fabs(pivot) < 1e-10) {
            printf("\nMatrix is not invertible (singular matrix).\n");
            delete_Matrix(copy);
            delete_Matrix(identity);
            return NULL;
        }

        for (int j = 0; j < mtx->cols; j++) {
            ((double**)copy->data->data)[i][j] /= pivot;
            ((double**)identity->data->data)[i][j] /= pivot;
        }

        for (int k = 0; k < mtx->rows; k++) {
            if (k != i) {
                double factor = ((double**)copy->data->data)[k][i];
                for (int j = 0; j < mtx->cols; j++) {
                    ((double**)copy->data->data)[k][j] -= factor * ((double**)copy->data->data)[i][j];
                    ((double**)identity->data->data)[k][j] -= factor * ((double**)identity->data->data)[i][j];
                }
            }
        }
    }

    delete_Matrix(copy);
    return identity;
}

double determinant_Matrix(const Matrix* mtx) {
    if (mtx->rows != mtx->cols) {
        printf("\nTamanhos incorretos para determinante.\n");
        return NAN;
    }
    Matrix* copy = zero_Matrix(mtx->rows,mtx->cols);
    for (int i = 0; i < mtx->rows; i++) {
        for (int j = 0; j < mtx->cols; j++) {
            ((double**)copy->data->data)[i][j] = ((double**)mtx->data->data)[i][j];
        }
    }
    double det = 1.0;
    for (int i = 0; i < mtx->rows; i++) {
        double pivot = ((double**)copy->data->data)[i][i];
        if (fabs(pivot) < 1e-10) {
            det = 0.0;
            break;
        }
        for (int k = i + 1; k < mtx->rows; k++) {
            double factor = ((double**)copy->data->data)[k][i] / pivot;
            for (int j = i; j < mtx->cols; j++) {
                ((double**)copy->data->data)[k][j] -= factor * ((double**)copy->data->data)[i][j];
            }
        }
        det *= pivot;
    }
    delete_Matrix(copy);
    return det;
}

void delete_Matrix(Matrix* mtx) {
    printf("Deletando Matriz\n");
    for (int i = 0; i < mtx->rows; i++) {
        printf("\nDeletando valores correspondentes a linhas %d\n",i);
        free(((double**)mtx->data->data)[i]);
    }
    printf("continua Deleta ponteiro de ponteiros\n");
    free(((double**)mtx->data->data));
    remove_adt(mtx->data);
}

