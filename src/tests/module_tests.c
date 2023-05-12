/* created by sheritsh // Oleg Polovinko ※ School 21, Kzn */

#include "module_tests.h"

/* TEST OPTIONS */

START_TEST(input_validation_opt_1) {
  char* sample = "2+2*2";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(input_validation_opt_2) {
  char* sample = "2^2^3";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(input_validation_opt_3) {
  char* sample = "cos(4)*sin(3)";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(input_validation_opt_4) {
  char* sample = "3.1415-21/42+12tan(5)";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(input_validation_opt_5) {
  char* sample = "19e+6-659.129+x(tan(cos(x)))";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(input_validation_opt_6) {
  char* sample = "kakayatonesurazica";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(input_validation_opt_7) {
  char* sample = "3..15";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(input_validation_opt_8) {
  char* sample = "1e--16";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(input_validation_opt_9) {
  char* sample = "29ep+cos(4)";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(input_validation_opt_10) {
  char* sample = "atan(5)+ln(3)+mod(4)+sqrb()";
  int res = is_input_valid(sample);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(tokens_devider_opt_1) {
  char* input_data = "+x-(-21)";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "+ x - ( - 21 ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_2) {
  char* input_data = "3.14+56((x)22)";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "3.14 + 56 ( ( x ) 22 ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_3) {
  char* input_data = "xxxxxxxxx(x)";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "x x x x x x x x x ( x ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_4) {
  char* input_data = "1e-12+cos(4)/sin(2)+ln(5)";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "1e-12 + cos ( 4 ) / sin ( 2 ) + ln ( 5 ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_5) {
  char* input_data = "log(log(log(sin(3))))";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "log ( log ( log ( sin ( 3 ) ) ) ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_6) {
  char* input_data = "+3247862-(-1)";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "+ 3247862 - ( - 1 ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_7) {
  char* input_data = "12/03/1997";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "12 / 03 / 1997 ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_8) {
  char* input_data = "0log(x)";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, "0 log ( x ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_9) {
  char* input_data = ".123123123+12398172387126387123613412";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(token_str, ".123123123 + 12398172387126387123613412 ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(tokens_devider_opt_10) {
  char* input_data = "^3^2^10*(24124-1e16)cos(5)/0log(x)";
  char* token_str = token_devider(input_data);
  int is_allocated = false;
  if (token_str != NULL) {
    is_allocated = true;
    ck_assert_str_eq(
        token_str, "^ 3 ^ 2 ^ 10 * ( 24124 - 1e16 ) cos ( 5 ) / 0 log ( x ) ");
    free(token_str);
    token_str = NULL;
  }
  ck_assert_int_eq(is_allocated, SUCCESS);
}
END_TEST

START_TEST(stack_opt_1) {
  // char *stack
  int is_error = false;
  calc_stack_t* teststack = init_stack();
  if (teststack != NULL) {
    push(teststack, "I");
    push(teststack, "am");
    push(teststack, "egoist");
    ck_assert_int_eq(teststack->length, 3);
    char* top = peek(teststack);
    ck_assert_str_eq(top, "egoist");
    top = pop(teststack);
    ck_assert_str_eq(top, "egoist");
    top = pop(teststack);
    ck_assert_str_eq(top, "am");
    remove_stack(teststack);
    if (teststack->tokens != NULL) {
      is_error = 1;
    }
    free(teststack);
    teststack = NULL;
  } else {
    is_error = 1;
  }
  ck_assert_int_eq(is_error, false);
}
END_TEST

START_TEST(stack_opt_2) {
  // long double* stack
  int is_error = false;
  double_stack_t* teststack = init_double_stack();
  if (teststack != NULL) {
    push(teststack, 5);
    push(teststack, 10);
    push(teststack, 97);
    ck_assert_int_eq(teststack->length, 3);
    long double top = peek_double_stack(teststack);
    ck_assert_ldouble_eq(top, 97);
    top = pop_double_stack(teststack);
    ck_assert_ldouble_eq(top, 97);
    top = pop_double_stack(teststack);
    ck_assert_ldouble_eq(top, 10);
    remove_double_stack(teststack);
    if (teststack->values != NULL) {
      is_error = 1;
    }
    free(teststack);
    teststack = NULL;
  } else {
    is_error = 1;
  }
  ck_assert_int_eq(is_error, false);
}
END_TEST

START_TEST(shunting_yard_opt_1) {
  // test
}
END_TEST

START_TEST(calculate_opt_1) {
  // test
}
END_TEST

/*  TEST SUITES */

Suite* input_validation_suite(void) {
  Suite* suite = suite_create("input_validation_tests");
  TCase* tc_core = tcase_create("core_of_input_validation");
  tcase_add_test(tc_core, input_validation_opt_1);
  tcase_add_test(tc_core, input_validation_opt_2);
  tcase_add_test(tc_core, input_validation_opt_3);
  tcase_add_test(tc_core, input_validation_opt_4);
  tcase_add_test(tc_core, input_validation_opt_5);
  tcase_add_test(tc_core, input_validation_opt_6);
  tcase_add_test(tc_core, input_validation_opt_7);
  tcase_add_test(tc_core, input_validation_opt_8);
  tcase_add_test(tc_core, input_validation_opt_9);
  tcase_add_test(tc_core, input_validation_opt_10);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite* tokens_devider_suite(void) {
  Suite* suite = suite_create("tokens_devider_tests");
  TCase* tc_core = tcase_create("core_of_tokens_devider");
  tcase_add_test(tc_core, tokens_devider_opt_1);
  tcase_add_test(tc_core, tokens_devider_opt_2);
  tcase_add_test(tc_core, tokens_devider_opt_3);
  tcase_add_test(tc_core, tokens_devider_opt_4);
  tcase_add_test(tc_core, tokens_devider_opt_5);
  tcase_add_test(tc_core, tokens_devider_opt_6);
  tcase_add_test(tc_core, tokens_devider_opt_7);
  tcase_add_test(tc_core, tokens_devider_opt_8);
  tcase_add_test(tc_core, tokens_devider_opt_9);
  tcase_add_test(tc_core, tokens_devider_opt_10);
  suite_add_tcase(suite, tc_core);

  return suite;
}

Suite* stack_suite(void) {
  Suite* suite = suite_create("stack_tests");
  TCase* tc_core = tcase_create("core_of_stack");
  tcase_add_test(tc_core, stack_opt_1);
  tcase_add_test(tc_core, stack_opt_2);
  suite_add_tcase(suite, tc_core);

  return suite;
}

/*  SUITES EXECUTION SCRIPT */

void s21_suit_execution(Suite* suite, int* failed_count, char* suite_name) {
  SRunner* suite_runner = srunner_create(suite);
  srunner_set_log(suite_runner, suite_name);
  srunner_run_all(suite_runner, CK_NORMAL);
  *failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
}

/*  TESTS MAIN */

int main(void) {
  int failed_count = 0;

  s21_suit_execution(input_validation_suite(), &failed_count,
                     "tests/input_validation_tests.log");
  s21_suit_execution(tokens_devider_suite(), &failed_count,
                     "tests/tokens_devider_tests.log");
  s21_suit_execution(stack_suite(), &failed_count, "tests/stack_tests.log");

  return failed_count == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
