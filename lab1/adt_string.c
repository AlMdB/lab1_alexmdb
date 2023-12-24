#include "adt_string.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


adt_string *adt_string_empty(){
    return newADTS_str(NULL);
}

adt_string *newADTS_str(char *str) {
    size_t len = strlen(str);
    adt_string *new_str = malloc(sizeof(adt_string));
    if (new_str) {
        new_str->base->size = len * sizeof(char);
        new_str->base->data = malloc(len * sizeof(char) + 1); 
            sprintf((char *)new_str->base->data, "%s", str);
    } else {
        free(new_str);
        new_str = NULL;
        }
    return new_str;
}


adt_string *newADTS_char(char c) {
    adt_string *new = malloc(sizeof(adt_string));
    if (new) {
        new->base->size = sizeof(char);
        new->base->data = malloc(sizeof(char) + 1);
        if (new->base->data) {
            sprintf((char *)new->base->data, "%c", c);
        } else {
            free(new);
            new = NULL;
        }
    }
    return new;
}


adt_string *newADTS_int(int i) {
    adt_string *new = malloc(sizeof(adt_string));
    if (new) {
        new->base->size = 7*sizeof(int); 
        new->base->data = malloc(7*sizeof(int)); 
        if (new->base->data) {
            sprintf((char *)new->base->data, "%d", i);
        } else {
            free(new);
            new = NULL;
        }
    }
    return new;
}


adt_string *newADTS_long(long l) {
    adt_string *new = malloc(sizeof(adt_string));
    if (new) {
        new->base->size = 7*sizeof(long); 
        new->base->data = malloc(7*sizeof(long)); 
        if (new->base->data) {
            sprintf((char *)new->base->data, "%ld", l);
        } else {
            free(new);
            new = NULL;
        }
    }
    return new;
}

adt_string *newADTS_float(float f) {
    adt_string *new = malloc(sizeof(adt_string));
    if (new) {
        new->base->size = 7*sizeof(long); 
        new->base->data = malloc(7*sizeof(float)); 
        if (new->base->data) {
            sprintf((char *)new->base->data, "%f", f);
        } else {
            free(new);
            new = NULL;
        }
    }
    return new;
}

adt_string *newADTS_double(double d) {
    adt_string *new = malloc(sizeof(adt_string));
    if (new) {
        new->base->size = 7*sizeof(double); 
        new->base->data = malloc(7*sizeof(double));
        if (new->base->data) {
            sprintf((char *)new->base->data, "%lf", d);
        } else {
            free(new);
            new = NULL;
        }
    }
    return new;
}

void del_adt_string(adt_string *ptr_str) {
    if (ptr_str) {
        remove_adt(ptr_str->base);
        free(ptr_str);
    }
}


adt_string* concat_adt_string(adt_string* s1, ...) {
    va_list args;
    va_start(args, s1);

    size_t total_size = s1->base->size;

    adt_string* current_str = s1;
    while (current_str != NULL) {
        total_size += current_str->base->size;
        current_str = va_arg(args, adt_string*);
    }

    va_end(args);

    adt_string* new_str = malloc(sizeof(adt_string));
    if (new_str) {
        new_str->base->data = malloc(total_size + 1);
        if (new_str->base->data) {
            current_str = s1;
            char* destination = (char*)new_str->base->data;
            while (current_str != NULL) {
                sprintf(destination, "%s", (char*)current_str->base->data);
                destination += current_str->base->size;
                current_str = va_arg(args, adt_string*);
            }
            new_str->base->size = total_size;
        } else {
            free(new_str);
            new_str = NULL;
        }
    }

    return new_str;
}

