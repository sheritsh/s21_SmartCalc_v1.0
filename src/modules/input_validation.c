#include "headers/input_validation.h"

bool is_input_valid(char* str) {
  if (str == NULL || *str == 'e' || *str == ')') {
    return false;
  }

  bool is_valid = true;
  int arg_len = (int)strlen(str);

  printf("input to validate %s\n", str);
  int i = 0;
  for (char* ptr = str; *ptr != '\0' && is_valid; ptr++, i++) {
    char cur_char = *ptr;
    printf("testing char [%c]\n", cur_char);
    if (strchr(PERMITTED_SYMBOLS, (int)cur_char) != NULL) {
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

  printf("result of hs %d\n", valid_symbols);
  return valid_symbols;
}

bool check_is_dot_valid(char* str) {
  if (str == NULL) {
    return false;
  }

  // !strchr(NUMBERS, (int)*(str + 1)) || *(str + 1) == '\0'

  str++;
  bool has_significant = strchr(NUMBERS, (int)*(str - 2)) ? true : false;
  bool is_dot_single = true;
  bool is_only_numbers = true;

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
  if (str == NULL || *(str + 1) == '\0') {
    return 0;
  }

  printf("exponent test %s\n", str);
  int valid_symbols = 0;
  char* test;
  bool error = false;
  if (strchr(NUMBERS, (int)*(str - 1))) {
    if (test = strchr("+-", (int)*(str + 1))) {
      printf("KAK BLYAT TI SYUDA ZAHODISH??? [%s]\n", test);
      printf("numb %c\n", (int)*(str + 1));
      if (strchr(NUMBERS, (int)*(str + 2))) {
        valid_symbols += 2;
        str += 2;
      } else {
        error = true;
      }
    } else if (!strchr(NUMBERS, (int)*(str + 1))) {
      printf("Vperedi zalupa posle e\n");
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

  printf("exp test res -> %d\n", error == 0 ? valid_symbols : 0);
  return error == 0 ? valid_symbols : 0;
}