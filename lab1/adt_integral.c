#include "adt_integral.h"
#include <stdio.h>

double parse_equation(adt_string* equation) {
    return 42.0;
}

double riemann_algo(double (*equation)(adt_string), adt_string* equation_str, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double xi = a + i * h;
        sum += equation(*equation_str) * h; 

    return sum;
}

void calculate_integral(adt_integral* integral) {
    double result = riemann_algo(integral->equation_parsed, integral->equation_2B_parsed, integral->initial_limit, integral->final_limit, integral->precision);
    integral->final_result = result;
    printf("Integral result using Riemann algorithm: %lf\n", integral->final_result);
}

int main() {
    adt_integral my_integral;

    my_integral.equation_2B_parsed = newADTS_str("x^2"); 
    my_integral.initial_limit = 0.0;
    my_integral.final_limit = 1.0;
    my_integral.equation_parsed = parse_equation;
    my_integral.precision = 100;
    my_integral.final_result = 0.0; 

    calculate_integral(&my_integral);

    del_adt_string(my_integral.equation_2B_parsed);

    return 0;
}