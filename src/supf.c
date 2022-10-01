#include "s21_matrix.h"

int size_compare(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }
  return SUCCESS;
}

int plus_minus(matrix_t *A, matrix_t *B, matrix_t *result, int sign) {
  if (size_compare(A, B) == FAILURE) {
    return INCORRECT_MATRIX;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int k = 0; k < A->columns; k++) {
      result->matrix[i][k] = A->matrix[i][k] + sign * B->matrix[i][k];
    }
  }
  return OK;
}

int cut_matrix(matrix_t *A, int rows_del, int columns_del, matrix_t *R) {
  int error = s21_create_matrix(A->rows - 1, A->columns - 1, R);
  if (error == OK) {
    for (int i = 0, j = 0; i < A->rows; i++) {
      if (i == rows_del) {
        continue;
      }
      for (int k = 0, l = 0; k < A->columns; k++) {
        if (k == columns_del) {
          continue;
        }
        R->matrix[j][l] = A->matrix[i][k];
        l++;
      }
      j++;
    }
  }

  return error;
}

int minor_matrix(matrix_t *A, matrix_t *minor) {
  int error = 0;
  error = s21_create_matrix(A->rows, A->columns, minor);
  matrix_t cut = {0};
  if (error == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int k = 0; k < A->columns; k++) {
        error = cut_matrix(A, i, k, &cut);
        if (error != OK) break;
        error = s21_determinant(&cut, &minor->matrix[i][k]);
        if (error != OK) break;
        s21_remove_matrix(&cut);
      }
    }
  }
  return error;
}
