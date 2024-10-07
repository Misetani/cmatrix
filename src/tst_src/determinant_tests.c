#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "matrices.h"

START_TEST(test_1) {
  matrix_t A = get_matrix_determinant();
  double result;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);

  ck_assert_double_eq_tol(result, 0.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_2) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.0;
  double result;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);

  ck_assert_double_eq_tol(result, 1.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  double result;

  ck_assert_int_eq(s21_determinant(&A, &result), OK);

  ck_assert_double_eq_tol(result, -2.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  s21_create_matrix(3, 4, &A);

  double result;

  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_test_2) {
  matrix_t A;
  double result;

  ck_assert_int_eq(s21_determinant(NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_determinant(&A, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_determinant(NULL, &result), INCORRECT_MATRIX);
}
END_TEST

Suite *determinant_tests(void) {
  Suite *s = suite_create("\033[34m__DETERMINANT_TESTS__\033[0m");
  TCase *tc = tcase_create("determinant_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);

  tcase_add_test(tc, error_test_1);
  tcase_add_test(tc, error_test_2);

  suite_add_tcase(s, tc);

  return s;
}