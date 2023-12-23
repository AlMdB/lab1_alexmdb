#ifndef _DSTRING_H
#define _DSTRING_H

typedef struct adt_string{
    void* data;
    size_t size;
}adt_string;

#define adt_string_size(aString) (aString->size)
#define $(aString) (aString->data)

#define new_adt_string _Generic((I), \
    char*  : new_adt_string_str, \
    char   : new_adt_string_char, \
    int    : new_adt_string_int,   \
    long   : new_adt_string_long,  \
    float  : new_adt_string_float,  \
    double : new_adt_string_double  \
    )
adt_string *newADTS_str(char *str);
adt_string *newADTS_char(char c);
adt_string *newADTS_int(int i);    
adt_string *newADTS_long(long l);
adt_string *newADTS_float(float f);
adt_string *newADTS_double(double d);

void del_adt_string(adt_string **pt);

adt_string* concat_adt_string(adt_string* s1, ...);


#endif