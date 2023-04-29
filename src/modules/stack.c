#include "headers/stack.h"

s21_stack_t* init_stack() {
  s21_stack_t* newstack = (s21_stack_t*)calloc(1, sizeof(s21_stack_t));

  newstack->length = 0;
  newstack->tokens = (char**)calloc(MAX_LEN, sizeof(char**));

  printf("stack initialized\n");
  return newstack;
}

bool is_stack_empty(s21_stack_t* stack) { return stack->length == 0; }

bool is_stack_full(s21_stack_t* stack) { return stack->length == MAX_LEN; }

void push(s21_stack_t* stack, char* token) {
  if (stack != NULL && !is_stack_full(stack)) {
    stack->tokens[stack->length] = token;
    stack->length++;
    printf("Successful push %s in stack\n");
  }
}

char* peek(s21_stack_t* stack) {
  if (stack == NULL || is_stack_empty(stack)) {
    return NULL;
  }

  return stack->tokens[stack->length - 1];
}

char* pop(s21_stack_t* stack) {
  if (stack == NULL || is_stack_empty(stack)) {
    return NULL;
  }

  stack->length--;
  return stack->tokens[stack->length];
}

void remove_stack(s21_stack_t* stack) {
  if (stack != NULL) {
    for (int i = 0; i < stack->length; i++) {
      free(stack->tokens[i]);
    }
    stack->length = 0;
  }
}

// int main() {
//   s21_stack_t* s21_stack = init_stack();
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