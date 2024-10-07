#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

START_TEST(test_1) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), OK);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      ck_assert_double_eq(A.matrix[i][j], 0.0);
    }
  }

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(test_2) {
  matrix_t A;
  int rows = 10;
  int columns = 10;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), OK);

  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      ck_assert_double_eq(A.matrix[i][j], 0.0);
    }
  }

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  int rows = 100;
  int columns = 100;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), OK);

  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      ck_assert_double_eq(A.matrix[i][j], 0.0);
    }
  }

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), OK);

  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      ck_assert_double_eq(A.matrix[i][j], 0.0);
    }
  }

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i * j + i + j + 1;
    }
  }

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      ck_assert_double_eq(A.matrix[i][j], i * j + i + j + 1);
    }
  }

  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(error_test_1) {
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(0, 0, &A), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(-1, 0, &A), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(0, -1, &A), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(1, 0, &A), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(0, 1, &A), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), OK);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(error_test_2) {
  ck_assert_int_eq(s21_create_matrix(10, 10, NULL), INCORRECT_MATRIX);
}
END_TEST

Suite *create_remove_matrix_tests(void) {
  Suite *s = suite_create("\033[34m__CREATE_REMOVE_MATRIX_TESTS__\033[0m");
  TCase *tc = tcase_create("create_remove_matrix_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);

  tcase_add_test(tc, error_test_1);
  tcase_add_test(tc, error_test_2);

  suite_add_tcase(s, tc);

  return s;
}