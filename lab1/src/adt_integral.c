#include "adt_integral.h"


double parse_double(const char* str) {
    char* endptr;
    return strtod(str, &endptr);
}

adt_integral* create_adt_integral(const char* equation, double initial_limit, double final_limit, int step, int intervals) {
    adt_integral* integral = (adt_integral*)malloc(sizeof(adt_integral));
    integral->equation_2B_parsed = shunting_yard(equation);
    integral->initial_limit = initial_limit;
    integral->final_limit = final_limit;
    integral->step = step;
    integral->intervals = intervals;
    integral->top_stack = 0;

    return integral;
}

int get_precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


adt_string* shunting_yard(const char* infix) {
    adt_string* output = adt_string_empty();
    adt_string* operators = adt_string_empty();

    for (size_t index = 0; infix[index] != '\0'; index++) {
        if (isdigit(infix[index]) || infix[index] == '.') {
            while (isdigit(infix[index]) || infix[index] == '.') {
                append_char(output, infix[index]);
                index++;
            }
            index--; 
            append_char(output, ' ');
        } else if (infix[index] == '(') {
            append_char(operators, infix[index]);
        } else if (infix[index] == ')') {
            while (adt_string_size(operators) > 0 && $$(operators)[adt_string_size(operators) - 1] != '(') {
                append_char(output, $$(operators)[adt_string_size(operators) - 1]);
                append_char(output, ' ');
                adt_string_size(operators)--;
            }
            adt_string_size(operators)--;
        } else if (infix[index] == '+' || infix[index] == '-' || infix[index] == '*' || infix[index] == '/' || infix[index] == '^') {
            while (adt_string_size(operators) > 0 && get_precedence($$(operators)[adt_string_size(operators) - 1]) >= get_precedence(infix[index])) {
                append_char(output, $$(operators)[adt_string_size(operators) - 1]);
                append_char(output, ' ');
                adt_string_size(operators)--;
            }
            append_char(operators, infix[index]);
        }
    }

    while (adt_string_size(operators) > 0) {
        append_char(output, $$(operators)[adt_string_size(operators) - 1]);
        append_char(output, ' ');
        adt_string_size(operators)--;
    }

    del_adt_string(operators);

    return output;
}


double evaluate_postfix(const char* postfix, double (*function)(double)) {
    double stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i]) || (postfix[i] == '-' && isdigit(postfix[i + 1]))) {
            stack[++top] = strtod(&postfix[i], NULL);
            while (isdigit(postfix[i]) || postfix[i] == '.' || postfix[i] == 'e' || postfix[i] == 'E' || postfix[i] == '-')
                ++i;
        } else if (postfix[i] == ' ') {
            continue;
        } else {
            double operand2 = stack[top--];
            double operand1 = stack[top--];

            switch (postfix[i]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                case '^':
                    stack[++top] = pow(operand1, operand2);
                    break;
                default:
                    break;
            }
        }
    }

    return stack[top];
}

double equation_parsing_result(adt_integral* integral) {
    double result = evaluate_postfix($(integral->postfix), sin);
    integral->final_result = result;
    return result;
}

double riemann_algo(adt_integral* integral, double (*function)(double)) {
    double result = 0.0;
    double dx = (integral->final_limit - integral->initial_limit) / integral->intervals;
    for (double x = integral->initial_limit; x < integral->final_limit; x += dx) {
        result += function(x) * dx;
    }
    return result;
}

void delete_integral(adt_integral* integral) {
    del_adt_string(integral->equation_2B_parsed);
    free(integral);
}