#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 && columns <= 0) {
    return INCORRECT_MATRIX;
  }
  result->columns = columns;
  result->rows = rows;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (!result->matrix[i]) {
      result->rows = i;
      s21_remove_matrix(result);
      return INCORRECT_MATRIX;
    }
  }

  return OK;
}
