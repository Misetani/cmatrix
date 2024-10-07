#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "matrices.h"

START_TEST(test_1) {
  matrix_t A = get_matrix_for_inversion();
  matrix_t C;

  ck_assert_int_eq(s21_inverse_matrix(&A, &C), OK);

  matrix_t result = get_inverted_matrix();

  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(error_test_2) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(error_test_3) {
  matrix_t A = get_matrix_determinant();
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *inverse_matrix_tests(void) {
  Suite *s = suite_create("\033[34m__INVERSE_MATRIX_TESTS__\033[0m");
  TCase *tc = tcase_create("inverse_matrix_tc");

  tcase_add_test(tc, test_1);

  tcase_add_test(tc, error_test_1);
  tcase_add_test(tc, error_test_2);
  tcase_add_test(tc, error_test_3);

  suite_add_tcase(s, tc);

  return s;
}