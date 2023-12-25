#include <stdio.h>
#include <stdlib.h>
#include "adt_matrix.h"
#include "adt_integral.h"
#include "adt_string.h"

void clrscr() {
    system("@cls||clear");
}

void print_menu() {
    printf("Escolha o algoritmo para teste:\n");
    printf("1. ADT das matrizes\n");
    printf("2. ADT das integrais\n");
    printf("3. ADT das Strings\n");
    printf("0. Fechar o programa\n");
}

void auto_matrix_test(){

    Matrix* matrix1 = random_Matrix(3, 3);
    Matrix* matrix2 = random_Matrix(3, 3);

    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("\nMatri 2:\n");
    print_matrix(matrix2);

    Matrix* sum = addition_matrices(matrix1, matrix2);
    printf("\nSOMA:\n");
    print_matrix(sum);

    Matrix* product = dot_product(matrix1, matrix2);
    printf("\nPRODUTO:\n");
    print_matrix(product);

    scalar_product(matrix1, 2.0);
    printf("\nPRODUTO ESCALAR NA MATRIX 1:\n");
    print_matrix(matrix1);

    scalar_addition(matrix2, 3.0);
    printf("\nPRODUTO ESCALAR NA MATRIX 2\n");
    print_matrix(matrix2);

    transpose_Matrix(matrix1);
    printf("\nTRANSPOSTA 1:\n");
    print_matrix(matrix1);

    
    Matrix* identity = inverse_Matrix(matrix1);
    printf("\nINVERSA 1:\n");
    print_matrix(identity);

    double determinant = determinant_Matrix(matrix1);
    printf("\nDETERMINANTE DA PRIMEIRA: %lf\n", determinant);

    delete_Matrix(matrix1);
    delete_Matrix(matrix2);
    delete_Matrix(sum);
    delete_Matrix(product);
    delete_Matrix(identity);
}

void auto_string_test(){
    adt_string *adt_s1 = newADTS_str("Somando com um float");
    printf("%s\n",$(adt_s1));
    adt_string *adt_s2 = newADTS_float(2.1674);
    printf("%s\n",$(adt_s2));
    adt_string *concat_st = concat_adt_string(adt_s1,adt_s2);
    printf("%s\n",$(concat_st));
    printf("A concatenação da string : %s com o float %s é igual a : %s",$(adt_s1),$(adt_s2),$(concat_st));
    del_adt_string(adt_s1);
    del_adt_string(adt_s2);
    del_adt_string(concat_st);
}

int testing_matrix_function() {
    int rows, cols;
    printf("Input as linhas e colunas da matriz: ");
    scanf("%d %d", &rows, &cols);

    int choice = 0;

    printf("\n1. Para criar a própria matriz\n");
    printf("2. Para criar a matriz randômica\n");
    printf("3. Test Automático\n");

    printf("Escolha: ");
    scanf("%d", &choice);

    Matrix *matrix;
    switch (choice) {
        case 1:
            char entrada[1000];
            scanf("%s",entrada); 
            adt_string *entrada_matrix = newADTS_str(entrada);
            matrix = create_Matrix(entrada_matrix, rows, cols);
            printf("Matriz criada:\n");
            print_matrix(matrix);
            break;
        case 2:
            matrix = random_Matrix(rows, cols);
            printf("Matriz randômica criada:\n");
            print_matrix(matrix);
            break;
        case 3:
            auto_matrix_test();
            break;
        default:
            printf("Escolha inválida\n");
            break;
    }
    if (matrix != NULL) {
        delete_Matrix(matrix);
    }
    return 0; 
}
int testing_string_function() {
    printf("Função de teste para Strings\n");
    int loop1 = 1;
    while (loop1) {
        printf("Qual tipo de string deseja testar?\n");
        printf("1. String\n");
        printf("2. Char\n");
        printf("3. Float\n");
        printf("4. Double\n");
        printf("5. Long\n");
        printf("6. Int\n");
        printf("7. Teste automatico das strings\n");
        printf("0. Sair\n");

        int choice;
        printf("Escolha: ");
        scanf("%d", &choice);

        adt_string* adt_s1;
        switch (choice) {
            case 1:
                printf("\nEscreva uma String\n");
                char test_string[1000];
                scanf("%s",test_string);
                adt_s1 = newADTS_str(test_string);
                printf("String: %s\n", $(adt_s1));
                 del_adt_string(adt_s1);
                break;
            case 2:
                printf("\nEscreva um char\n");
                char test_char;
                scanf(" %c",&test_char);
                adt_s1 = newADTS_char(test_char);
                printf("Char: %s\n", $(adt_s1));
                del_adt_string(adt_s1);
                break;
            case 3:
                printf("\nEscreva um numero float\n");
                float test_fl;
                scanf("%f",&test_fl);
                adt_s1 = newADTS_float(test_fl);
                printf("Float: %s\n", $(adt_s1));
                del_adt_string(adt_s1);
                break;
            case 4:
                printf("\nEscreva um numero double\n");
                double test_double;
                scanf("%lf",&test_double);
                adt_s1 = newADTS_double(test_double);
                printf("Double: %s\n", $(adt_s1));
                del_adt_string(adt_s1);
                break;
            case 5:
                printf("\nEscreva um numero long\n");
                long test_long;
                scanf("%ld",&test_long);
                adt_s1 = newADTS_long(test_long);
                printf("Long: %s\n", $(adt_s1));
                del_adt_string(adt_s1);
                break;
            case 6:
                printf("\nEscreva um numero int\n");
                int test_int;
                scanf("%d",&test_int);
                adt_s1 = newADTS_int(test_int);
                printf("Int: %s\n", $(adt_s1));
                del_adt_string(adt_s1);
                break;
            case 7:
                auto_string_test();
                break;
            case 0:
                loop1 = 0;
                break;
            default:
                printf("Escolha inválida\n");
                break;
        }
    }

    return 0;
}

int testing_integral_function() {
    printf("Função de teste para Integrais\n");
    return 0; 
}

int main() {
    int choice = 7;
    int inside_loop_function = 1;

    while (choice != 0) {
        print_menu();
        printf("Digite sua escolha: ");
        scanf("%d", &choice);
        clrscr();

        switch (choice) {
            case 1:
                inside_loop_function = 1;
                while (inside_loop_function) {
                    inside_loop_function = testing_matrix_function();
                }
                break;
            case 2:
                inside_loop_function = 1;
                while (inside_loop_function) {
                    inside_loop_function = testing_integral_function();
                }
                break;
            case 3:
                inside_loop_function = 1;
                while (inside_loop_function) {
                    inside_loop_function = testing_string_function();
                }
                break;
            case 0:
                printf("SAIR DO PROGRAMA\n");
                break;
            default:
                printf("ESCOLHA INVÁLIDA\n");
                break;
        }
    }

    return 0;
}
