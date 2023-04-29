#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include "../../SmartCalc.h"

#define PERMITTED_SYMBOLS "1234567890()+-*/^mcstalx."
#define NUMBERS "1234567890"
#define OPERANDS "1234567890mcstalx.("

bool is_input_valid(char* str);
int handle_symbols(char* ptr);

#endif  // INPUT_VALIDATION_H