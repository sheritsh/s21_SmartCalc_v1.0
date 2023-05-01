/* created by sheritsh // Oleg Polovinko ※ School 21, Kzn */

#ifndef SMART_CALC_H
#define SMART_CALC_H

#include <iso646.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

#include "modules/headers/calculate.h"
#include "modules/headers/input_validation.h"
#include "modules/headers/shunting_yard.h"
#include "modules/headers/stack.h"
#include "modules/headers/tokens_devider.h"

/**
 * @brief The function to launch the calculator.
 * @param str string in infix notation
 * @return bool :
 * 0 - successfull
 * 1 - failure. ERROR!
 */
int smart_calc_init(char* str);

#endif  // SMART_CALC_H