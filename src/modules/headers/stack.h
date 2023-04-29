#ifndef STACK_H
#define STACK_H

#include "../../SmartCalc.h"

typedef struct stack_struct {
  int length;
  char **tokens;
} s21_stack_t;

#endif  // STACK_H