#include "adt_base.h"
#include <stdio.h>

adt_base* create_adt(void *data, size_t size){
    adt_base*new = malloc(sizeof(adt_base));
    new->data = malloc(sizeof(data));
    new->data = data;
    new->size = size;
    return new;
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