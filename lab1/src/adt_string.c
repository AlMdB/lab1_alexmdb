#include "adt_string.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


adt_string *adt_string_empty(){
    return newADTS_str(NULL);
}

void append_char(adt_string* str, char c) {
    char char_str[2] = {c, '\0'};
    adt_string* char_adt_str = newADTS_str(char_str);
    adt_string* concat_result = concat_adt_string(str, char_adt_str, NULL);
    del_adt_string(str);
    del_adt_string(char_adt_str);
    *str = *concat_result;
    free(concat_result);
}


adt_string *newADTS_str(char *str) {
    size_t len = (str != NULL) ? strlen(str) : 0; 
    adt_string *new_str = malloc(sizeof(adt_string));
    if (new_str) {
        new_str->base = malloc(sizeof(adt_base));  
        if (new_str->base) {
            new_str->base->size = len * sizeof(char);
            new_str->base->data = malloc(len + 1);  
            if (new_str->base->data) {
                if (str != NULL) {
                    sprintf((char *)new_str->base->data, "%s", str);
                } else {
                    $(new_str)[0] = '\0';  
                }
                return new_str; 
            } else {
                free(new_str->base);
                free(new_str);
                new_str = NULL;
            }
        } else {
            free(new_str);
            new_str = NULL;
        }
    }
    return new_str;
}




adt_string *newADTS_char(char c) {
    adt_string *new_str = malloc(sizeof(adt_string));

    if (new_str) {
        new_str->base = malloc(sizeof(adt_base)); 
        if (new_str->base) {
            new_str->base->size = 2*sizeof(char);  
            new_str->base->data = malloc(new_str->base->size);  
            if (new_str->base->data) {
                ((char *)new_str->base->data)[0] = c;
                ((char *)new_str->base->data)[1] = '\0';
            } else {
                free(new_str->base);
                free(new_str);
                new_str = NULL;
            }
        } else {
            free(new_str);
            new_str = NULL;
        }
    }

    return new_str;
}

adt_string *newADTS_int(int i) {
    adt_string *new_str = malloc(sizeof(adt_string));

    if (new_str) {
        new_str->base = malloc(sizeof(adt_base));
        if (new_str->base) {
            new_str->base->size = 4*sizeof(int);  
            new_str->base->data = malloc(new_str->base->size);
            if (new_str->base->data) {
                sprintf((char *)new_str->base->data, "%d", i);
            } else {
                free(new_str->base);
                free(new_str);
                new_str = NULL;
            }
        } else {
            free(new_str);
            new_str = NULL;
        }
    }

    return new_str;
}

adt_string *newADTS_long(long l) {
    adt_string *new_str = malloc(sizeof(adt_string));

    if (new_str) {
        new_str->base = malloc(sizeof(adt_base));  
        if (new_str->base) {
            new_str->base->size = 4*sizeof(long);  
            new_str->base->data = malloc(new_str->base->size);  
            if (new_str->base->data) {
                sprintf((char *)new_str->base->data, "%ld", l);
            } else {
                free(new_str->base);
                free(new_str);
                new_str = NULL;
            }
        } else {
            free(new_str);
            new_str = NULL;
        }
    }

    return new_str;
}

adt_string *newADTS_float(float f) {
    adt_string *new_str = malloc(sizeof(adt_string));

    if (new_str) {
        new_str->base = malloc(sizeof(adt_base)); 
        if (new_str->base) {
            new_str->base->size = 4*sizeof(float);  
            new_str->base->data = malloc(new_str->base->size);
            if (new_str->base->data) {
                sprintf((char *)new_str->base->data, "%f", f);
            } else {
                free(new_str->base);
                free(new_str);
                new_str = NULL;
            }
        } else {
            free(new_str);
            new_str = NULL;
        }
    }

    return new_str;
}

adt_string *newADTS_double(double d) {
    adt_string *new_str = malloc(sizeof(adt_string));

    if (new_str) {
        new_str->base = malloc(sizeof(adt_base));
        if (new_str->base) {
            new_str->base->size = 4*sizeof(double); 
            new_str->base->data = malloc(new_str->base->size);
            if (new_str->base->data) {
                sprintf((char *)new_str->base->data, "%lf", d);
            } else {
                free(new_str->base);
                free(new_str);
                new_str = NULL;
            }
        } else {
            free(new_str);
            new_str = NULL;
        }
    }

    return new_str;
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
            char* destination = (char*)new_str->base->data;
            current_str = s1;
            while (current_str != NULL) {
                sprintf(destination, "%s", (char*)current_str->base->data);
                destination += strlen((char*)current_str->base->data);
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
