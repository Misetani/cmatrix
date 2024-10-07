#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "matrices.h"

START_TEST(test_1) {
  matrix_t A = get_matrix_for_complements();
  matrix_t C;

  ck_assert_int_eq(s21_calc_complements(&A, &C), OK);

  matrix_t result = get_matrix_of_compliments();

  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_calc_complements(NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(error_test_2) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *calc_complements_tests(void) {
  Suite *s = suite_create("\033[34m__CALC_COMPLEMENTS_TESTS__\033[0m");
  TCase *tc = tcase_create("calc_complements_tc");

  tcase_add_test(tc, test_1);

  tcase_add_test(tc, error_test_1);
  tcase_add_test(tc, error_test_2);

  suite_add_tcase(s, tc);

  return s;
}