#include "SmartCalc.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    char input_data[MAX_LEN + 1];
    strncpy(input_data, argv[1], MAX_LEN);
    if (is_input_valid(input_data)) {
      char* token_str = token_divider(input_data);
      printf("%s\n", token_str);
      free(token_str);

      // printf("%s\n", input_data);
    } else {
      printf("Invalid input. Error.\n");
    }
  }
  return 0;
}