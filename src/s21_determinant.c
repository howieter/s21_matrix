#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (A->rows != A->columns || A->rows == 0) {
    return CALC_ERROR;
  }
  int error = OK;
  *result = 0;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t tmp_matrix2 = {0};
    double tmp = 0;
    for (int row = 0; error == OK && row < A->rows; row++) {
      error = cut_matrix(A, row, 0, &tmp_matrix2);
      if (error == OK) {
        error = s21_determinant(&tmp_matrix2, &tmp);
        if (error == OK) {
          *result += tmp * A->matrix[row][0] * ((row % 2 == 1) ? -1 : 1);
        }
      }
      s21_remove_matrix(&tmp_matrix2);
    }
  }

  return error;
}
