#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "matrices.h"

START_TEST(test_1) {
  matrix_t A = get_simple_matrix();
  matrix_t C;

  ck_assert_int_eq(s21_transpose(&A, &C), OK);

  matrix_t result = get_simple_matrix_transp();

  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  matrix_t result;
  ck_assert_int_eq(s21_transpose(NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_transpose(&A, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_transpose(NULL, &result), INCORRECT_MATRIX);
}
END_TEST

Suite *transpose_matrix_tests(void) {
  Suite *s = suite_create("\033[34m__TRANSPOSE_MATRIX_TESTS__\033[0m");
  TCase *tc = tcase_create("transpose_matrix_tc");

  tcase_add_test(tc, test_1);

  tcase_add_test(tc, error_test_1);

  suite_add_tcase(s, tc);

  return s;
}