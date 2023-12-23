#include "adt_string.h";
#include <stdio.h>

size_t size_str(char* sequence){
    size_t size = 0;
    while(sequence !='\0'){
        size++;
    }
    return size;
}

adt_string *newADTS_str(char *str){
    size_t len = size_str(str);
    adt_string* new = malloc(len*sizeof(char));
    if(new){
        new->size = len*sizeof(char);
        sprintf(new->data,"%s",str);
    }
    return new;
}

adt_string *newADTS_char(char c){
    adt_string* new = malloc(1*sizeof(char));
    if(new){
        new->size = 1*sizeof(char);
        sprintf(new->size,"%c",c);
    }
    return new;
}


adt_string *newADTS_int(int i);    
adt_string *newADTS_long(long l);
adt_string *newADTS_float(float f);
adt_string *newADTS_double(double d);

void del_adt_string(adt_string **ptr_str);

adt_string* concat_adt_string(adt_string* s1, ...);