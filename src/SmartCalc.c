#include "SmartCalc.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    // smart_calc_init(argv[1]);
    long double res = 0;
    api_calculate_str(argv[1], &res);
    // printf("%Lf\n", res);
  }
  return 0;
}

// int smart_calc_init(char* str) {
//   if (str == NULL) {
//     return 1;
//   }

//   char input_data[MAX_LEN + 1] = {'\0'};
//   bool is_error = false;
//   strncpy(input_data, str, MAX_LEN);
//   is_error = !is_input_valid(input_data);
//   if (!is_error) {
//     char* token_str = token_divider(input_data);
//     if (token_str != NULL) {
//       if (*token_str == '\0') {
//         printf("Please input smthng\n");
//       }
//       missing_mult_signs_handler(token_str);
//       unary_operators_handler(token_str);
//       add_end_of_line(token_str);
//       x_replacement_to_value(token_str, 100);
//       printf("%s\n", token_str);
//       is_error = !dijkstra_runner(token_str);
//       if (!is_error) {
//         long double res = calculate_res(token_str);
//         printf("RPN: [%s]\n", token_str);
//         printf("RES: [%Lf]\n", res);

//         free(token_str);
//         token_str = NULL;
//       }
//     }
//   }

//   if (is_error) {
//     printf("Invalid input. Error.\n");
//   }

//   return 0;
// }

int api_calculate_str(const char* str, long double* res) {
  if (str == NULL) {
    return EXIT_FAILURE;
  }

  *res = 0;
  char input_data[MAX_LEN + 1] = {'\0'};
  bool is_error = false;
  strncpy(input_data, str, MAX_LEN);
  is_error = !is_input_valid(input_data);
  if (!is_error) {
    char* token_str = token_divider(input_data);
    if (token_str != NULL) {
      missing_mult_signs_handler(token_str);
      unary_operators_handler(token_str);
      add_end_of_line(token_str);

      is_error = !dijkstra_runner(token_str);
      printf("input [%s]\n", token_str);
      long double rez;
      if (!is_error) {
        // *res = calculate_res(token_str);
        rez = calculate_res(token_str);
      }
      printf("input [%Lf]\n", rez);
      free(token_str);
      token_str = NULL;
    }
  }

  return is_error;
}

int api_infix_to_postfix_notation(const char* str, char* res_str) {
  if (str == NULL) {
    return EXIT_FAILURE;
  }

  char input_data[MAX_LEN + 1] = {'\0'};
  bool is_error = false;
  strncpy(input_data, str, MAX_LEN);
  is_error = !is_input_valid(input_data);
  if (!is_error) {
    char* token_str = token_divider(input_data);
    if (token_str != NULL) {
      missing_mult_signs_handler(token_str);
      unary_operators_handler(token_str);
      add_end_of_line(token_str);
      x_replacement_to_value(token_str, 2);
      is_error = !dijkstra_runner(token_str);
      strncpy(res_str, token_str, MAX_LEN * 2);
      free(token_str);
      token_str = NULL;
    }
  }

  return is_error;
}

int api_calculate_str_with_x(const char* str, long double x, long double* res) {
  if (str == NULL) {
    return EXIT_FAILURE;
  }

  *res = 0;
  char input_data[MAX_LEN + 1] = {'\0'};
  bool is_error = false;
  strncpy(input_data, str, MAX_LEN);
  is_error = !is_input_valid(input_data);
  if (!is_error) {
    char* token_str = token_divider(input_data);
    if (token_str != NULL) {
      missing_mult_signs_handler(token_str);
      unary_operators_handler(token_str);
      add_end_of_line(token_str);
      x_replacement_to_value(token_str, x);
      is_error = !dijkstra_runner(token_str);
      if (!is_error) {
        *res = calculate_res(token_str);
      }
      free(token_str);
      token_str = NULL;
    }
  }

  return is_error;
}
