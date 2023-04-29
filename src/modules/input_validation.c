#include "headers/input_validation.h"

bool is_input_valid(char* str) {
  bool is_valid = true;
  int arg_len = (int)strlen(str);

  printf("input to validate %s\n", str);
  int i = 0;
  for (char* ptr = str; *ptr != '\0' && is_valid; ptr++, i++) {
    char cur_char = *ptr;
    printf("testing char [%c]\n", cur_char);
    if (strchr(PERMITTED_SYMBOLS, (int)cur_char)) {
      printf("premitted\n");
      if (strchr(NUMBERS, (int)cur_char) || cur_char == 'x') {
        printf("numb\n");
      } else {
        int step = handle_symbols(ptr);
        if (step) {
          ptr += step - 1;
        } else {
          printf("falsim\n");
          is_valid = false;
        }
      }
    } else {
      is_valid = false;
    }
  }

  return is_valid;
}

int handle_symbols(char* ptr) {
  printf("We are in handle symbs to test %s\n", ptr);
  int valid_symbols = 0;
  char str_to_analyze[6] = {'\0'};
  strncat(str_to_analyze, ptr, 5);
  if (*ptr == '(' || *ptr == ')') {
    valid_symbols = 1;
  } else if (*ptr == '.') {
    if (strchr(NUMBERS, (int)*(ptr + 1))) {
      valid_symbols = 1;
    }
  } else if (strchr("+-*/^", (int)*ptr)) {
    if (strchr(OPERANDS, (int)*(ptr + 1))) {
      valid_symbols = 1;
    }
  } else if (*ptr == 'a') {
    if (strstr(str_to_analyze, "asin(") || strstr(str_to_analyze, "acos(") ||
        strstr(str_to_analyze, "atan(")) {
      valid_symbols = 5;
    }
  } else if (*ptr == 'c') {
    if (strstr(str_to_analyze, "cos(")) {
      valid_symbols = 4;
    }
  } else if (*ptr == 'l') {
    if (strstr(str_to_analyze, "ln(")) {
      valid_symbols = 3;
    } else if (strstr(str_to_analyze, "log(")) {
      valid_symbols = 4;
    }
  } else if (*ptr == 'm') {
    if (strstr(str_to_analyze, "mod(")) {
      valid_symbols = 4;
    }
  } else if (*ptr == 's') {
    if (strstr(str_to_analyze, "sin(")) {
      valid_symbols = 4;
    } else if (strstr(str_to_analyze, "sqrt(")) {
      valid_symbols = 5;
    }
  } else if (*ptr == 't') {
    if (strstr(str_to_analyze, "tan(")) {
      valid_symbols = 4;
    }
  }

  printf("result of hs %d\n", valid_symbols);
  return valid_symbols;
}