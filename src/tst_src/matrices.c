#include <stdio.h>

#include "../s21_matrix.h"

matrix_t get_simple_matrix() {
  static matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  return A;
}

matrix_t get_matrix_1() {
  static matrix_t A;
  s21_create_matrix(5, 5, &A);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      A.matrix[i][j] = 5 * i + j;
    }
  }

  return A;
}

matrix_t get_matrix_2() {
  static matrix_t A;
  s21_create_matrix(5, 5, &A);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      A.matrix[i][j] = 24 - (5 * i + j);
    }
  }

  return A;
}

matrix_t get_matrix_3() {
  static matrix_t A;
  s21_create_matrix(3, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 6.0;

  return A;
}

matrix_t get_matrix_4() {
  static matrix_t A;
  s21_create_matrix(2, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  return A;
}

matrix_t get_matrix_12_sum() {
  static matrix_t A;
  s21_create_matrix(5, 5, &A);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      A.matrix[i][j] = 24;
    }
  }

  return A;
}

matrix_t get_matrix_12_dif() {
  static matrix_t A;
  s21_create_matrix(5, 5, &A);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      A.matrix[i][j] = 2 * (5 * i + j) - 24;
    }
  }

  return A;
}

matrix_t get_matrix_34_mult() {
  static matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 9.0;
  A.matrix[0][1] = 12.0;
  A.matrix[0][2] = 15.0;
  A.matrix[1][0] = 19.0;
  A.matrix[1][1] = 26.0;
  A.matrix[1][2] = 33.0;
  A.matrix[2][0] = 29.0;
  A.matrix[2][1] = 40.0;
  A.matrix[2][2] = 51.0;

  return A;
}

matrix_t get_simple_matrix_sum() {
  static matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 8.0;

  return A;
}

matrix_t get_simple_matrix_dif() {
  static matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.0;

  return A;
}

matrix_t get_simple_matrix_mult() {
  static matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 7.0;
  A.matrix[0][1] = 10.0;
  A.matrix[1][0] = 15.0;
  A.matrix[1][1] = 22.0;

  return A;
}

matrix_t get_simple_matrix_transp() {
  static matrix_t A;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 3.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 4.0;

  return A;
}

matrix_t get_matrix_determinant() {
  static matrix_t A;
  s21_create_matrix(3, 3, &A);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      A.matrix[i][j] = i * 3 + j + 1;
    }
  }

  return A;
}

matrix_t get_matrix_for_complements() {
  static matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;

  return A;
}

matrix_t get_matrix_of_compliments() {
  static matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 10.0;
  A.matrix[0][2] = -20.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = -14.0;
  A.matrix[1][2] = 8.0;
  A.matrix[2][0] = -8.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = 4.0;

  return A;
}

matrix_t get_matrix_for_inversion() {
  static matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  return A;
}

matrix_t get_inverted_matrix() {
  static matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = -1.0;
  A.matrix[0][2] = 1.0;
  A.matrix[1][0] = -38.0;
  A.matrix[1][1] = 41.0;
  A.matrix[1][2] = -34.0;
  A.matrix[2][0] = 27.0;
  A.matrix[2][1] = -29.0;
  A.matrix[2][2] = 24.0;

  return A;
}

void print_matrix(matrix_t A) {
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      printf("%-5.3f ", A.matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}