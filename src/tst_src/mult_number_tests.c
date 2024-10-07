#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "matrices.h"

START_TEST(test_1) {
  matrix_t A = get_simple_matrix();
  double number = 3.14;
  matrix_t C;

  ck_assert_int_eq(s21_mult_number(&A, number, &C), OK);

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      ck_assert_double_eq(C.matrix[i][j], number * A.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_2) {
  matrix_t A = get_matrix_1();
  double number = 3.14;
  matrix_t C;

  ck_assert_int_eq(s21_mult_number(&A, number, &C), OK);

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      ck_assert_double_eq_tol(C.matrix[i][j], number * A.matrix[i][j], 1e-7);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_3) {
  matrix_t A = get_matrix_2();
  double number = 9.99;
  matrix_t C;

  ck_assert_int_eq(s21_mult_number(&A, number, &C), OK);

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      ck_assert_double_eq_tol(C.matrix[i][j], number * A.matrix[i][j], 1e-7);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  double number = 0.0;
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(NULL, number, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_number(NULL, number, &result), INCORRECT_MATRIX);
}
END_TEST

Suite *mult_number_tests(void) {
  Suite *s = suite_create("\033[34m__MULT_NUMBER_TESTS__\033[0m");
  TCase *tc = tcase_create("mult_number_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);

  tcase_add_test(tc, error_test_1);

  suite_add_tcase(s, tc);

  return s;
}