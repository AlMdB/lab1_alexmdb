#ifndef ADT_BASE_H
#define ADT_BASE_H

#define adt_base_data(adt) ((adt)->data) 
#define adt_base_size(adt)  ((adt)->size)


typedef struct adt_base{
    void*data;
    size_t size;
}adt_base;

adt_base* create_adt(void *data, size_t size);
void remove_adt(adt_base* node);


#endif