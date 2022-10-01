#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->columns; i++) {
    for (int k = 0; k < A->rows; k++) {
      result->matrix[i][k] = A->matrix[k][i];
    }
  }
  return error;
}
