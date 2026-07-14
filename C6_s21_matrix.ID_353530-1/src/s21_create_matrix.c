#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, s21_matrix *result) {
  int r = CODEOK;
  if (result == NULL || rows <= 0 || columns <= 0) {
    r = CODE1;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      r = CODE1;
    } else {
      result->rows = rows;
      result->columns = columns;
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          r = CODE1;
          break;
        }
      }
      if (r == CODE1) {
        s21_remove_matrix(result);
      }
    }
  }
  return r;
}
