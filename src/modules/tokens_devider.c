#include "headers/tokens_devider.h"

char* token_divider(char* str) {
  char* output_str = (char*)calloc(MAX_LEN * 2 + 1, sizeof(char));
  if (output_str != NULL) {
    memset(output_str, '\0', MAX_LEN * 2 + 1);

    for (char* ptr = str; *ptr != '\0'; ptr++) {
      char cur_char = *ptr;
      char cur_token[MAX_LEN] = {'\0'};
      int step = 0;

      if (cur_char == '.' || strchr(NUMBERS, (int)cur_char)) {
        bool is_exp_notation = check_exp_notation(ptr);
        if (is_exp_notation) {
          // for exp_notated
          step = exp_notation_length(ptr) - 1;
          strncpy(cur_token, ptr, step + 1);
        } else {
          step = strspn(ptr, REAL_NUMBS) - 1;
          strncpy(cur_token, ptr, step + 1);
        }
      } else if (cur_char == 'e') {
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

bool check_exp_notation(char* str) {
  bool is_exp_notation = false;
  bool is_number_end = false;

  for (char* ptr = str; *ptr != '\0' && !is_number_end; ptr++) {
    printf("checking\n");
    if (*ptr == 'e') {
      is_exp_notation = true;
    } else if (!strchr("1234567890.", (int)*ptr)) {
      is_number_end = true;
    }
  }

  return is_exp_notation;
}

int exp_notation_length(char* str) {
  if (str == NULL) {
    return 0;
  }

  int length = 0;
  bool is_number_end = false;
  bool has_sign = false;
  int real_part = (int)strspn(str, "1234567890.");
  str += real_part + 1;
  if (*str == '+' || *str == '-') {
    has_sign = true;
    str++;
  }
  int exp_part = (int)strspn(str, "1234567890");

  return real_part + has_sign + exp_part + 1;
}

void missing_mult_signs_handler(char* str) {
  char prev_lexema[MAX_LEN + 1] = {'\0'};
  int current_word = 0;

  printf("handled str [%s]\n", str);

  for (char* ptr = str; *ptr != '\0'; ptr++) {
    int cur_lexema_length = 0;
    printf("\titerated str [%s]\n", ptr);
    // arrange lexema
    if (current_word) {
      for (char* insptr = ptr; *insptr != ' '; insptr++) {
        cur_lexema_length++;
      }

      // handling multiplier for numbers
      printf("make decision for %c in case [%s]\n", *ptr, prev_lexema);
      printf("current real ptr [%s]\n", ptr);
      if (*ptr == 'x' || *ptr == '(' || strchr(FUNCS, (int)*ptr)) {
        if (strpbrk(prev_lexema, ")x.0123456789")) {
          printf("memovаю вот столько %d\n", strlen(ptr));
          memmove(ptr + 2, ptr, strlen(ptr));
          printf("[MEMMOVED]: %s\n", ptr);
          *ptr = '*';
          *(ptr + 1) = ' ';
        }
      } else if (strchr(REAL_NUMBS, (int)*ptr)) {
        if (strpbrk(prev_lexema, ")x")) {
          memmove(ptr + 2, ptr, strlen(ptr));
          *ptr = '*';
          *(ptr + 1) = ' ';
        }
      }
    }

    for (char* insptr = ptr; *insptr != ' '; insptr++) {
      strncpy(prev_lexema, insptr, 1);
    }

    while (*ptr != ' ') {
      ptr++;
    }

    printf("now i am on -> %s\n", ptr);

    current_word++;
  }
}

void unary_operators_handler(char* str) {
  if (str != NULL) {
    if (*str == '+') {
      *str = 'p';
    } else if (*str == '-') {
      *str = '~';
    }

    char prev_lexema[MAX_LEN + 1] = {'\0'};
    int current_word = 0;

    for (char* ptr = str; *ptr != '\0'; ptr++) {
      int cur_lexema_length = 0;
      if (current_word) {
        if (*ptr == '+' || *ptr == '-') {
          if (strchr(prev_lexema, '(')) {
            if (*ptr == '+') {
              *ptr = 'p';
            } else {
              *ptr = '~';
            }
          }
        }
      }
      for (char* insptr = ptr; *insptr != ' '; insptr++) {
        strncpy(prev_lexema, insptr, 1);
      }
      while (*ptr != ' ') {
        ptr++;
      }
      current_word++;
    }
  }
}

void add_end_of_line(char* str) {
  if (str != NULL) {
    *(str + strlen(str)) = '<';
    *(str + strlen(str) + 1) = '\0';
  }
}