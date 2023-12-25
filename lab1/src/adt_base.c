#include "adt_base.h"
#include <stdio.h>

adt_base* create_adt(void *data, size_t size){
    adt_base*new_adt = (adt_base*) malloc(sizeof(adt_base));
    if(new_adt == NULL){
        printf("Problema de memoria\n");
        return NULL;
    }
    new_adt->data = malloc(sizeof(data));
    new_adt->data = data;
    new_adt->size = size;
    return new_adt;
}

void remove_adt(adt_base* node){
    printf("Deletando valores do adt\n");
    if(node){
        printf("dados do geral\n");
        free(node->data);
        free(node);
        node = NULL;
    }
    printf("concluido geral\n");
}