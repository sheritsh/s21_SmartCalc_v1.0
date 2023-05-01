#include "headers/stack.h"

calc_stack_t* init_stack() {
  calc_stack_t* newstack = (calc_stack_t*)calloc(1, sizeof(calc_stack_t));

  newstack->length = 0;
  newstack->tokens = (char**)calloc(MAX_LEN, sizeof(char**));

  printf("stack initialized\n");
  return newstack;
}

bool is_stack_empty(calc_stack_t* stack) { return stack->length == 0; }

bool is_stack_full(calc_stack_t* stack) { return stack->length == MAX_LEN; }

void push(calc_stack_t* stack, char* token) {
  if (stack != NULL && !is_stack_full(stack)) {
    stack->tokens[stack->length] = token;
    stack->length++;
    printf("Successful push %s in stack\n");
  }
}

char* peek(calc_stack_t* stack) {
  if (stack == NULL || is_stack_empty(stack)) {
    return NULL;
  }

  return stack->tokens[stack->length - 1];
}

char* pop(calc_stack_t* stack) {
  if (stack == NULL || is_stack_empty(stack)) {
    return NULL;
  }

  stack->length--;
  return stack->tokens[stack->length];
}

void remove_stack(calc_stack_t* stack) {
  if (stack != NULL && stack->tokens != NULL) {
    free(stack->tokens);
    stack->tokens = NULL;
    stack->length = 0;
  }
}

// int main() {
//   calc_stack_t* s21_stack = init_stack();
//   printf("Opagangnam style\n");
//   push(s21_stack, "Zalupa");
//   push(s21_stack, "Pupa");
//   push(s21_stack, "Zangetsu");

//   for (int i = 0; i < s21_stack->length; i++) {
//     printf("%s\n", s21_stack->tokens[i]);
//   }

//   free(s21_stack);

//   return 0;
// }
///////////////////// STACK FOR CALC

double_stack_t* init_double_stack() {
  double_stack_t* newstack = (double_stack_t*)calloc(1, sizeof(double_stack_t));

  newstack->length = 0;
  newstack->values = (long double*)calloc(MAX_LEN, sizeof(long double*));

  printf("double stack initialized\n");
  return newstack;
}

bool is_double_stack_empty(double_stack_t* stack) { return stack->length == 0; }

bool is_double_stack_full(double_stack_t* stack) {
  return stack->length == MAX_LEN;
}

void push_into_double(double_stack_t* stack, long double value) {
  if (stack != NULL && !is_double_stack_full(stack)) {
    stack->values[stack->length] = value;
    stack->length++;
    printf("Successful push %f in stack\n", value);
  }
}

long double peek_double_stack(double_stack_t* stack) {
  if (stack == NULL || is_double_stack_empty(stack)) {
    return 0;
  }

  return stack->values[stack->length - 1];
}

long double pop_double_stack(double_stack_t* stack) {
  if (stack == NULL || is_double_stack_empty(stack)) {
    return 0;
  }

  stack->length--;
  return stack->values[stack->length];
}

void remove_double_stack(double_stack_t* stack) {
  if (stack != NULL && stack->values != NULL) {
    free(stack->values);
    stack->values = NULL;
    stack->length = 0;
  }
}