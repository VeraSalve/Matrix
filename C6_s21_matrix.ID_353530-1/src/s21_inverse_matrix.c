#include "s21_matrix.h"
int s21_inverse_matrix(s21_matrix *A, s21_matrix *result) {
  int r = CODEOK;
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return CODE1;
  } else if (A->columns != A->rows) {
    r = CODE2;
  } else {
    double det = 0.0;
    r = s21_determinant(A, &det);
    if (r == CODEOK && fabs(det) < EPSILON) {
      r = CODE2;
    } else if (r == CODEOK) {
      s21_matrix complements = {0};
      r = s21_calc_complements(A, &complements);
      if (r == CODEOK) {
        s21_matrix transposed = {0};
        r = s21_transpose(&complements, &transposed);
        if (r == CODEOK) {
          r = s21_mult_number(&transposed, 1.0 / det, result);
        }
        s21_remove_matrix(&complements);
        s21_remove_matrix(&transposed);
      }
    }
  }
  return r;
}