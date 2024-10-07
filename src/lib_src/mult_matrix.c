#include <stdlib.h>

#include "../s21_matrix.h"

// Implementing Naive method for matrix multiplication

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
    return INCORRECT_MATRIX;
  }

  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  if (s21_create_matrix(A->rows, B->columns, result) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  for (int row = 0; row < A->rows; ++row) {
    for (int column = 0; column < B->columns; ++column) {
      for (int i = 0; i < A->columns; ++i) {
        result->matrix[row][column] += A->matrix[row][i] * B->matrix[i][column];
      }
    }
  }

  return OK;
}
