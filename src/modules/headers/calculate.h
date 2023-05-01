#ifndef CALCULATE_H
#define CALCULATE_H

#include "../../SmartCalc.h"
#include "stack.h"

long double calculate_res(char* str);

bool calculations(char* token, double_stack_t* calculation_stack,
                  long double* result);

bool calculate_from_stack(double_stack_t* calculation_stack, long double* res,
                          int sign);

bool calculate_func(double_stack_t* calculation_stack, long double* res,
                    char* func);

#endif  // CALCULATE_H