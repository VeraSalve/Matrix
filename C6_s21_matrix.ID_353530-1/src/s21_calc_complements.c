#include "s21_matrix.h"
int s21_calc_complements(s21_matrix *A, s21_matrix *result) {
  int r = CODEOK;
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return CODE1;
  } else if (A->columns != A->rows) {
    r = CODE2;
  } else {
    r = s21_create_matrix(A->rows, A->columns, result);
    if (A->rows == 1) {
      result->matrix[0][0] = 1.0;
    } else {
      for (int i = 0; i < A->rows && r == CODEOK; i++) {
        for (int j = 0; j < A->columns && r == CODEOK; j++) {
          s21_matrix minor = {0};
          double det = 0.0;
          r = s21_crossout(A, &minor, i, j);
          if (r == CODEOK) {
            r = s21_determinant(&minor, &det);
            if (r == CODEOK) {
              result->matrix[i][j] = det * pow(-1, i + j);
            }
          }
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  return r;
}