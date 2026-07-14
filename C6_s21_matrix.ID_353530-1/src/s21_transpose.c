#include "s21_matrix.h"
int s21_transpose(s21_matrix *A, s21_matrix *result) {
  int r = CODEOK;
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return CODE1;
  } else {
    r = s21_create_matrix(A->columns, A->rows, result);
    if (r == CODEOK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  }
  return r;
}