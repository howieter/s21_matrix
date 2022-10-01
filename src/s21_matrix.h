#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum { OK, INCORRECT_MATRIX, CALC_ERROR };
enum { FAILURE, SUCCESS };

//  вспомогательные функции
int size_compare(matrix_t *A, matrix_t *B);
int plus_minus(matrix_t *A, matrix_t *B, matrix_t *result, int sign);
int cut_matrix(matrix_t *A, int rows_del, int columns_del, matrix_t *cut);
int minor_matrix(matrix_t *A, matrix_t *minor);

//  основные функции
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  //  SRC_S21_MATRIX_H_
