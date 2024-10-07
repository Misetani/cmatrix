#include <stdlib.h>

#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  if (A->rows <= 0 || A->columns <= 0) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  // if matrix determinant is 0, then matrix is not invertible
  double det;
  s21_determinant(A, &det);
  if (det == 0) {
    return CALCULATION_ERROR;
  }

  if (s21_create_matrix(A->columns, A->rows, result) == INCORRECT_MATRIX) {
    return INCORRECT_MATRIX;
  }

  if (A->rows == 1) {  // base case
    result->matrix[0][0] = 1 / A->matrix[0][0];
    return OK;
  }

  matrix_t complements;
  s21_calc_complements(A, &complements);

  matrix_t transposed_complements;
  s21_transpose(&complements, &transposed_complements);

  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = transposed_complements.matrix[i][j] / det;
    }
  }

  s21_remove_matrix(&complements);
  s21_remove_matrix(&transposed_complements);

  return OK;
}