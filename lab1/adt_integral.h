#ifndef _ADT_INTEGRAL_H
#define _ADT_INTEGRAL_H

#include "adt_string.h"


typedef struct adt_integral{
    adt_string* equation_2B_parsed;
    double initial_limit, final_limit;
    double (*equation_parsed)(adt_string,...);
    int precision;
    double final_result;
}adt_integral;


double equation_parsing_result{

}

double riemann_algo();



#endif