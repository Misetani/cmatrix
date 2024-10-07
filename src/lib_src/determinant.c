#include <stdlib.h>

#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  *result = 0.0;

  if (A->rows <= 0 || A->columns <= 0) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  if (A->rows == 1) {  // base case
    *result = A->matrix[0][0];
    return OK;
  }

  if (A->rows == 2) {  // base case
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return OK;
  }

  // iterate over the first row
  for (int i = 0; i < A->columns; ++i) {
    matrix_t sub_matrix;
    s21_create_matrix(A->rows - 1, A->columns - 1, &sub_matrix);

    for (int j = 1; j < A->rows; ++j) {
      for (int k = 0; k < A->columns; ++k) {
        if (k < i) {
          sub_matrix.matrix[j - 1][k] = A->matrix[j][k];
        } else if (k > i) {
          sub_matrix.matrix[j - 1][k - 1] = A->matrix[j][k];
        }
      }
    }

    int sign = (i % 2 == 0) ? 1 : -1;

    double sub_det;
    s21_determinant(&sub_matrix, &sub_det);
    *result += sign * A->matrix[0][i] * sub_det;

    // printf("sign = %d, value = %f, *result = %f\n", sign, A->matrix[0][i],
    // *result);

    s21_remove_matrix(&sub_matrix);
  }

  return OK;
}