#include "headers/calculate.h"

long double calculate_res(char* str) {
  if (str == NULL) {
    return 0;
  }

  char temp[MAX_LEN] = {'\0'};
  strcpy(temp, str);

  long double result = 0;
  bool is_error = false;

  double_stack_t* calculation_stack = init_double_stack();
  if (calculation_stack != NULL) {
    char* token = strtok(temp, " ");
    while (token != NULL && !is_error) {
      is_error = !calculations(token, calculation_stack, &result);
      token = strtok(NULL, " ");
    }
    result = pop_double_stack(calculation_stack);
    remove_double_stack(calculation_stack);
    free(calculation_stack);
    calculation_stack = NULL;
  } else {
    is_error = true;
  }

  return is_error == 0 ? result : NAN;
}

bool calculations(char* token, double_stack_t* calculation_stack,
                  long double* result) {
  if (token == NULL || calculation_stack == NULL || result == NULL) {
    return false;
  }

  bool is_success = true;
  if (strchr("0123456789.", (int)*token)) {
    push_into_double(calculation_stack, strtold(token, &token));
  } else if (strchr(OPERATORS, (int)*token)) {
    long double res = 0;
    is_success = calculate_from_stack(calculation_stack, &res, (int)*token);
    if (is_success) {
      push_into_double(calculation_stack, res);
    }
  } else if (*token == '~') {
    // handle UNARY
    push_into_double(calculation_stack,
                     0 - pop_double_stack(calculation_stack));
  } else if (*token == 'p') {
    push_into_double(calculation_stack,
                     0 + pop_double_stack(calculation_stack));
  } else {
    // handle FUNCS
    long double res = 0;
    is_success = calculate_func(calculation_stack, &res, token);
    if (is_success) {
      push_into_double(calculation_stack, res);
    }
  }

  return is_success;
}

bool calculate_from_stack(double_stack_t* calculation_stack, long double* res,
                          int sign) {
  if (calculation_stack == NULL || res == NULL) {
    return false;
  }

  long double val1 = pop_double_stack(calculation_stack);
  long double val2 = pop_double_stack(calculation_stack);

  if (sign == '+') {
    *res = val2 + val1;
  } else if (sign == '-') {
    *res = val2 - val1;
  } else if (sign == '*') {
    *res = val2 * val1;
  } else if (sign == '/') {
    *res = val2 / val1;
  } else if (sign == '^') {
    *res = powl(val2, val1);
  }

  return isnan(*res) == 0 ? true : false;
}

bool calculate_func(double_stack_t* calculation_stack, long double* res,
                    char* func) {
  if (calculation_stack == NULL || res == NULL || func == NULL) {
    return false;
  }

  long double value = pop_double_stack(calculation_stack);

  if (strstr(func, "mod")) {
    *res = fabsl(value);
  } else if (strstr(func, "cos")) {
    *res = cosl(value);
  } else if (strstr(func, "sin")) {
    *res = sinl(value);
  } else if (strstr(func, "tan")) {
    *res = tanl(value);
  } else if (strstr(func, "acos")) {
    *res = acosl(value);
  } else if (strstr(func, "asin")) {
    *res = asinl(value);
  } else if (strstr(func, "atan")) {
    *res = atanl(value);
  } else if (strstr(func, "sqrt")) {
    *res = sqrtl(value);
  } else if (strstr(func, "ln")) {
    *res = logl(value);
  } else if (strstr(func, "log")) {
    *res = log10l(value);
  }

  return isnan(*res) == 0 ? true : false;
}