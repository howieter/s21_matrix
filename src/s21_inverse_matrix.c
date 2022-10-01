#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  double determinant = 0;
  error = s21_determinant(A, &determinant);
  if (determinant == 0 || fabs(determinant) <= 1e-7) {
    return CALC_ERROR;
  }
  if (error == OK) {
    matrix_t tmp = {0};
    error = s21_calc_complements(A, result);
    error = s21_transpose(result, &tmp);
    s21_remove_matrix(result);
    error = s21_mult_number(&tmp, 1 / determinant, result);
    s21_remove_matrix(&tmp);
  }
  return error;
}
