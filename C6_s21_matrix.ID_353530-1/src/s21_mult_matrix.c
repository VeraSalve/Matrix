#include "s21_matrix.h"
int s21_mult_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result) {
  int r = CODEOK;
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL || A->rows <= 0 || A->columns <= 0 || B->rows <= 0 ||
      B->columns <= 0) {
    return CODE1;
  } else if (A->columns != B->rows) {
    r = CODE2;
  } else {
    r = s21_create_matrix(A->rows, B->columns, result);
    if (r == CODEOK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return r;
}