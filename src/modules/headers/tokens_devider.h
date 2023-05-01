#ifndef TOKENS_DEVIDER_H
#define TOKENS_DEVIDER_H

#include "../../SmartCalc.h"

int handle_functions(char* ptr);
char* token_divider(char* str);
int exp_notation_length(char* str);
bool check_exp_notation(char* str);
void missing_mult_signs_handler(char* str);
void unary_operators_handler(char* str);
void add_end_of_line(char* str);

#endif  // TOKENS_DEVIDER_H