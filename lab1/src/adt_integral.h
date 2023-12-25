#ifndef _ADT_INTEGRAL_H
#define _ADT_INTEGRAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "adt_string.h"
#include <ctype.h>


typedef struct adt_integral{
    adt_string* equation_2B_parsed,*postfix,*stack;
    double initial_limit, final_limit, final_result;
    int step,intervals,top_stack;
} adt_integral;

adt_string* shunting_yard(const char* infix);

adt_integral* create_adt_integral(const char* equation, double initial_limit, double final_limit, int step, int intervals);

double equation_parsing_result(adt_integral* integral);

double riemann_algo(adt_integral* integral, double (*function)(double));

void delete_integral(adt_integral* integral);


#endif
