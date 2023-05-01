#ifndef STACK_H
#define STACK_H

typedef struct stack_struct {
  int length;
  char **tokens;
} calc_stack_t;

typedef struct double_stack_struct {
  int length;
  long double *values;
} double_stack_t;

#include "../../SmartCalc.h"

calc_stack_t *init_stack();

bool is_stack_empty(calc_stack_t *stack);

bool is_stack_full(calc_stack_t *stack);

void push(calc_stack_t *stack, char *token);

char *peek(calc_stack_t *stack);

char *pop(calc_stack_t *stack);

void remove_stack(calc_stack_t *stack);

double_stack_t *init_double_stack();

bool is_double_stack_empty(double_stack_t *stack);

bool is_double_stack_full(double_stack_t *stack);

void push_into_double(double_stack_t *stack, long double value);

long double peek_double_stack(double_stack_t *stack);

long double pop_double_stack(double_stack_t *stack);

void remove_double_stack(double_stack_t *stack);

#endif  // STACK_H
