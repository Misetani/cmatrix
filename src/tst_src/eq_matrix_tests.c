#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t B;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &B), OK);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  A.matrix[1][1] = 1.0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  B.matrix[1][1] = 1.000001;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  B.matrix[1][1] = 1.0000001;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  B.matrix[1][1] = 1.00000001;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  s21_remove_matrix(&B);
  ck_assert_ptr_eq(B.matrix, NULL);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), OK);

  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(NULL, &A), FAILURE);

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(error_test_2) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(1, 2, &A), OK);

  matrix_t B;
  ck_assert_int_eq(s21_create_matrix(2, 1, &B), OK);

  matrix_t C;
  ck_assert_int_eq(s21_create_matrix(1, 1, &C), OK);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(&A, &C), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), FAILURE);

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  s21_remove_matrix(&B);
  ck_assert_ptr_eq(B.matrix, NULL);
  s21_remove_matrix(&C);
  ck_assert_ptr_eq(C.matrix, NULL);
}
END_TEST

Suite *eq_matrix_tests(void) {
  Suite *s = suite_create("\033[34m__EQ_MATRIX_TESTS__\033[0m");
  TCase *tc = tcase_create("eq_matrix_tc");

  tcase_add_test(tc, test_1);

  tcase_add_test(tc, error_test_1);
  tcase_add_test(tc, error_test_2);

  suite_add_tcase(s, tc);

  return s;
}