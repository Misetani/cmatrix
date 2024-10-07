#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "matrices.h"

START_TEST(test_1) {
  matrix_t A = get_simple_matrix();
  matrix_t B = get_simple_matrix();
  matrix_t C;

  int ret = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(ret, OK);

  matrix_t result = get_simple_matrix_dif();
  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_2) {
  matrix_t A = get_matrix_1();
  matrix_t B = get_matrix_2();
  matrix_t C;

  int ret = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(ret, OK);

  matrix_t result = get_matrix_12_dif();

  ck_assert_int_eq(s21_eq_matrix(&C, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(error_test_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *sub_matrix_tests(void) {
  Suite *s = suite_create("\033[34m__SUB_MATRIX_TESTS__\033[0m");
  TCase *tc = tcase_create("sub_matrix_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);

  tcase_add_test(tc, error_test_1);
  tcase_add_test(tc, error_test_2);

  suite_add_tcase(s, tc);

  return s;
}