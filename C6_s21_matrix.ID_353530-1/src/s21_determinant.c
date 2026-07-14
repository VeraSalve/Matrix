#include "s21_matrix.h"
int s21_determinant(s21_matrix *A, double *result) {
  int r = CODEOK;
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return CODE1;
  } else if (A->rows != A->columns) {
    r = CODE2;
  } else {
    if (A->columns == 1) {
      *result = A->matrix[0][0];
    } else if (A->columns == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      double det = 0.0, tmp = 0.0;
      s21_matrix minor = {0};
      for (int j = 0; j < A->columns; j++) {
        r = s21_crossout(A, &minor, 0, j);
        if (r == CODEOK) {
          r = s21_determinant(&minor, &tmp);
          if (r == CODEOK) {
            det = det + pow((-1), 0 + j) * A->matrix[0][j] * tmp;
          }
          s21_remove_matrix(&minor);
        }
      }
      *result = det;
    }
  }
  return r;
}

int s21_crossout(s21_matrix *A, s21_matrix *result, int i_toskip, int j_skip) {
  int r = CODEOK;
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return CODE1;
  } else {
    r = s21_create_matrix(A->rows - 1, A->columns - 1, result);
    if (r == CODEOK) {
      int current_i = 0;
      for (int i = 0; i < A->rows; i++) {
        if (i == i_toskip) {
          continue;
        }
        int current_j = 0;
        for (int j = 0; j < A->columns; j++) {
          if (j == j_skip) {
            continue;
          } else {
            result->matrix[current_i][current_j] = A->matrix[i][j];
            current_j++;
          }
        }
        current_i++;
      }
    }
  }
  return r;
}