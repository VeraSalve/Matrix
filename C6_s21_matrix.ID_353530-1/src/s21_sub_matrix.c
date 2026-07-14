#include "s21_matrix.h"
int s21_sub_matrix(s21_matrix *A, s21_matrix *B, s21_matrix *result) {
  int r = CODEOK;
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL || A->rows <= 0 || A->columns <= 0 || B->rows <= 0 ||
      B->columns <= 0) {
    return CODE1;
  } else {
    if (A->columns == B->columns && A->rows == B->rows) {
      r = s21_create_matrix(A->rows, A->columns, result);
      if (r == CODEOK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else {
      r = CODE2;
    }
  }
  return r;
}