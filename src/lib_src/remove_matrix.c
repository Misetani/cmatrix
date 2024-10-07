#include <stdlib.h>

#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A == NULL) {
    return;
  }

  for (int i = 0; i < A->rows; ++i) {
    // if malloc returned NULL, then all consecutive memory is not allocated
    // no need to free it
    if (A->matrix[i] == NULL) {
      break;
    }

    free(A->matrix[i]);
  }

  free(A->matrix);
  A->matrix = NULL;
}