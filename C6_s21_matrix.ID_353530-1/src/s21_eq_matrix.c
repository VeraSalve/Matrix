#include "s21_matrix.h"
int s21_eq_matrix(s21_matrix *A, s21_matrix *B) {
  int result = SUCCESS;
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    result = FAILURE;
  } else {
    if (A->columns == B->columns && A->rows == B->rows) {
      for (int i = 0; i < A->rows && result == SUCCESS; i++) {
        for (int j = 0; j < A->columns && result == SUCCESS; j++) {
          double diff = fabs(A->matrix[i][j] - B->matrix[i][j]);
          if (diff > EPSILON) {
            result = FAILURE;
          }
        }
      }
    } else
      result = FAILURE;
  }
  return result;
}