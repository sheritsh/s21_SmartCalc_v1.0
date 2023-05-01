#include "headers/input_validation.h"

bool is_input_valid(char* str) {
  if (str == NULL) {
    return false;
  } else if (*str == 'e' || *str == ')') {
    return false;
  }

  bool is_valid = true;
  int arg_len = (int)strlen(str);

  for (char* ptr = str; *ptr != '\0' && is_valid; ptr++) {
    char cur_char = *ptr;
    if (strchr(PERMITTED_SYMBOLS, (int)cur_char) != NULL) {
      if (strchr(NUMBERS, (int)cur_char) || cur_char == 'x') {
        // number - OKAY
      } else {
        int step = handle_symbols(ptr);
        if (step) {
          ptr += step - 1;
        } else {
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
  if (ptr == NULL) {
    return 0;
  }

  int valid_symbols = 0;
  char str_to_analyze[6] = {'\0'};
  strncat(str_to_analyze, ptr, 5);
  if (*ptr == '(') {
    valid_symbols = 1;
  } else if (*ptr == ')') {
    if (*(ptr - 1) != '(') {
      valid_symbols = 1;
    }
  } else if (*ptr == '.') {
    valid_symbols = (int)check_is_dot_valid(ptr);
  } else if (*ptr == 'e') {
    valid_symbols = handle_exponent(ptr);
  } else if (strchr("+-*/^", (int)*ptr)) {
    if (strchr(OPERANDS, (int)*(ptr + 1)) && *(ptr + 1) != '\0') {
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

  return valid_symbols;
}

bool check_is_dot_valid(char* str) {
  if (str == NULL) {
    return false;
  }

  bool has_significant = strchr(NUMBERS, (int)*(str - 2)) ? true : false;
  bool is_dot_single = true;
  bool is_only_numbers = true;
  // now go to the next character and test after '.'
  str++;
  if (!has_significant && (!strchr(NUMBERS, (int)*(str)) || *(str) == '\0')) {
    is_dot_single = false;
  }
  for (char* ptr = str; *ptr != '\0' && is_dot_single && is_only_numbers;
       ptr++) {
    char cur_char = *ptr;
    if (!strchr(NUMBERS, (int)cur_char)) {
      is_only_numbers = false;
      if (cur_char == '.') {
        is_dot_single = false;
      }
    }
  }

  return is_dot_single;
}

int handle_exponent(char* str) {
  if (str == NULL) {
    return 0;
  } else if (*(str + 1) == '\0') {
    return 0;
  }

  int valid_symbols = 0;
  bool error = false;
  if (strchr(NUMBERS, (int)*(str - 1))) {
    if (strchr("+-", (int)*(str + 1))) {
      if (strchr(NUMBERS, (int)*(str + 2))) {
        valid_symbols += 2;
        str += 2;
      } else {
        error = true;
      }
    } else if (!strchr(NUMBERS, (int)*(str + 1))) {
      error = true;
    } else {
      valid_symbols++;
      str++;
    }

    if (!error) {
      bool is_numb_end = false;
      for (char* ptr = str; *ptr != '\0' && !is_numb_end && !error; ptr++) {
        if (strchr(NUMBERS, (int)*ptr)) {
          valid_symbols++;
        } else if (*ptr == 'e' || *ptr == '.') {
          error = true;
        } else {
          is_numb_end = true;
        }
      }
    }
  }

  return error == 0 ? valid_symbols : 0;
}