#include "s21_matrix.h"
int s21_mult_number(s21_matrix *A, double number, s21_matrix *result) {
  int r = CODEOK;
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return CODE1;
  } else {
    r = s21_create_matrix(A->rows, A->columns, result);
    if (r == CODEOK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return r;
}