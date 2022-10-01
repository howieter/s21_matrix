#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int k = 0; k < A->columns; k++) {
      result->matrix[i][k] = A->matrix[i][k] * number;
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->columns != B->rows) {
    return CALC_ERROR;
  }
  if (A->columns <= 0 || B->columns <= 0 || A->rows <= 0 || B->rows <= 0) {
    return INCORRECT_MATRIX;
  }
  s21_create_matrix(A->rows, B->columns, result);
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < B->columns; n++) {
      for (int k = 0; k < B->rows; k++) {
        result->matrix[m][n] += A->matrix[m][k] * B->matrix[k][n];
      }
    }
  }
  return OK;
}
