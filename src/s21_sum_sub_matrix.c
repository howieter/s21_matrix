#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return plus_minus(A, B, result, 1);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return plus_minus(A, B, result, -1);
}
