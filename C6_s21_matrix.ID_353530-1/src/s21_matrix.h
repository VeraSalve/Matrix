#define SUCCESS 1
#define FAILURE 0
#define CODEOK 0
#define CODE1 1
#define CODE2 2
#define EPSILON 1e-7
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} s21_matrix;

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int s21_create_matrix(int rows, int columns, s21_matrix *result);
void s21_remove_matrix(s21_matrix *A);
int s21_eq_matrix(s21_matrix *A, s21_matrix *B);
int s21_sum_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result);
int s21_sub_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result);
int s21_mult_number(s21_matrix *A, double number, s21_matrix *result);
int s21_mult_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result);
int s21_transpose(s21_matrix *A, s21_matrix *result);
int s21_calc_complements(s21_matrix *A, s21_matrix *result);
int s21_determinant(s21_matrix *A, double *result);
int s21_inverse_matrix(s21_matrix *A, s21_matrix *result);

int s21_crossout(s21_matrix *A, s21_matrix *result, int i_toskip, int j_skip);