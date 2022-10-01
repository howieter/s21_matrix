#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A->rows != A->columns) {
    return INCORRECT_MATRIX;
  }
  error = minor_matrix(A, result);
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][k] *= pow(-1, i + k);
      }
    }
  }
  return error;
}
