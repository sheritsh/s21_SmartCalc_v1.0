#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "../../SmartCalc.h"
#include "stack.h"

enum operator_precedence {
  OPEN_BRACKET,
  PLUS,
  MINUS = 1,
  MULT,
  DIV = 2,
  POW,
  UNARY_MINUS,
  UNARY_PLUS = 4,
};

bool dijkstra_runner(char* str);
bool dijkstra_logic(char* token, calc_stack_t* calc_stack, char* buffer);
bool handle_EOL(calc_stack_t* calc_stack, char* buffer);
int check_precedence(int operator);
int get_operator_int(char* token);
void decide_on_operators(char* token, calc_stack_t* calc_stack, char* buffer);
void decide_on_closure_brackets(calc_stack_t* calc_stack, char* buffer,
                                bool* is_success);

#endif  // SHUNTING_YARD_H