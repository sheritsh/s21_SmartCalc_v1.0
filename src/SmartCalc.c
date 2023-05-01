#include "SmartCalc.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    char input_data[MAX_LEN + 1];
    bool is_error = false;
    strncpy(input_data, argv[1], MAX_LEN);
    is_error = !is_input_valid(input_data);
    if (!is_error) {
      char* token_str = token_divider(input_data);
      if (token_str != NULL) {
        if (*token_str == '\0') {
          printf("Please input smthng\n");
        }
        missing_mult_signs_handler(token_str);
        unary_operators_handler(token_str);
        add_end_of_line(token_str);
        is_error = !dijkstra_runner(token_str);
        if (!is_error) {
          long double res = calculate_res(token_str);
          printf("RPN: [%s]\n", token_str);
          printf("RES: [%Lf]\n", res);

          free(token_str);
          token_str = NULL;
        }
      }
    }

    if (is_error) {
      printf("Invalid input. Error.\n");
    }
  }
  return 0;
}