#include "headers/shunting_yard.h"

char* token_divider(char* str) {
  char* output_str = (char*)calloc(MAX_LEN * 2 + 1, sizeof(char));
  memset(output_str, '\0', MAX_LEN * 2 + 1);

  for (char* ptr = str; *ptr != '\0'; ptr++) {
    char cur_char = *ptr;
    char cur_token[MAX_LEN] = {'\0'};
    int step = 0;

    if (cur_char == '.' || strchr(NUMBERS, (int)cur_char)) {
      step = strspn(ptr, REAL_NUMBS) - 1;
      strncpy(cur_token, ptr, step + 1);
    } else if (strchr(OPERATORS, (int)cur_char) ||
               strchr(BRACKETS, (int)cur_char) || cur_char == 'x') {
      // кидаем в токен и все
      strncpy(cur_token, ptr, 1);
    } else if (strchr(FUNCS, (int)cur_char)) {
      step = handle_functions(ptr) - 1;
      strncpy(cur_token, ptr, step + 1);
    }
    ptr += step;
    strcat(output_str, cur_token);
    strcat(output_str, " ");
  }

  return output_str;
}

int handle_functions(char* ptr) {
  printf("We are in handle func to test %s\n", ptr);
  int func_size = 0;
  char str_to_analyze[6] = {'\0'};
  strncat(str_to_analyze, ptr, 5);

  if (*ptr == 'a') {
    if (strstr(str_to_analyze, "asin") || strstr(str_to_analyze, "acos") ||
        strstr(str_to_analyze, "atan")) {
      func_size = 4;
    }
  } else if (*ptr == 'c') {
    if (strstr(str_to_analyze, "cos")) {
      func_size = 3;
    }
  } else if (*ptr == 'l') {
    if (strstr(str_to_analyze, "ln")) {
      func_size = 2;
    } else if (strstr(str_to_analyze, "log")) {
      func_size = 3;
    }
  } else if (*ptr == 'm') {
    if (strstr(str_to_analyze, "mod")) {
      func_size = 3;
    }
  } else if (*ptr == 's') {
    if (strstr(str_to_analyze, "sin")) {
      func_size = 3;
    } else if (strstr(str_to_analyze, "sqrt")) {
      func_size = 4;
    }
  } else if (*ptr == 't') {
    if (strstr(str_to_analyze, "tan")) {
      func_size = 3;
    }
  }

  return func_size;
}