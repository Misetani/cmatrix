#include <stdlib.h>

#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  if (A->rows <= 0 || A->columns <= 0) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  if (s21_create_matrix(A->columns, A->rows, result) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      matrix_t sub_matrix;
      s21_create_matrix(A->rows - 1, A->columns - 1, &sub_matrix);

      for (int k = 0; k < A->rows; ++k) {
        if (k < i) {
          for (int l = 0; l < A->columns; ++l) {
            if (l < j) {
              sub_matrix.matrix[k][l] = A->matrix[k][l];
            } else if (l > j) {
              sub_matrix.matrix[k][l - 1] = A->matrix[k][l];
            }
          }
        } else if (k > i) {
          for (int l = 0; l < A->columns; ++l) {
            if (l < j) {
              sub_matrix.matrix[k - 1][l] = A->matrix[k][l];
            } else if (l > j) {
              sub_matrix.matrix[k - 1][l - 1] = A->matrix[k][l];
            }
          }
        }
      }

      s21_determinant(&sub_matrix, &result->matrix[i][j]);
      result->matrix[i][j] *= (i + j) % 2 == 0 ? 1 : -1;

      s21_remove_matrix(&sub_matrix);
    }
  }

  return OK;
}
