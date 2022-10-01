#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (size_compare(A, B) == SUCCESS) {
    for (int i = 0; i < A->rows; i++) {
      for (int k = 0; k < A->columns; k++) {
        if (fabsl(A->matrix[i][k] - B->matrix[i][k]) >= 1e-7) {
          return FAILURE;
        }
      }
    }
  } else {
    return FAILURE;
  }
  return SUCCESS;
}
