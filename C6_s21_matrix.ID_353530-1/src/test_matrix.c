#include <check.h>

#line 1 "test_matrix.check"
#include "s21_matrix.h"

START_TEST(test_create_matrix_success) {
#line 8
  s21_matrix m;
  int code = s21_create_matrix(3, 3, &m);
  ck_assert_int_eq(code, 0);
  ck_assert_ptr_nonnull(m.matrix);
  ck_assert_int_eq(m.rows, 3);
  ck_assert_int_eq(m.columns, 3);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_matrix_invalid) {
#line 17
  s21_matrix m;
  int code = s21_create_matrix(-5, 2, &m);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_create_matrix_invalid_2) {
#line 22
  int code = s21_create_matrix(2, 2, NULL);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_create_matrix_invalid_3) {
#line 26
  s21_matrix m;
  int code = s21_create_matrix(2, -2, &m);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_eq_matrix_equal) {
#line 33
  s21_matrix A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0000001;
  A.matrix[0][1] = 2.0000001;
  A.matrix[1][0] = 3.0000001;
  A.matrix[1][1] = 4.0000001;

  B.matrix[0][0] = 1.0000002;
  B.matrix[0][1] = 2.0000002;
  B.matrix[1][0] = 3.0000002;
  B.matrix[1][1] = 4.0000002;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_not_equal) {
#line 51
  s21_matrix A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 5.0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_diff_size) {
#line 69
  s21_matrix A, B;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_diff_size_2) {
#line 78
  s21_matrix A, B;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix) {
#line 91
  s21_matrix A, B, C, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 2;
  C.matrix[0][1] = 4;
  C.matrix[1][0] = 6;
  C.matrix[1][1] = 8;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum_matrix_error) {
#line 121
  int code = s21_sum_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(code, CODE1);
}
END_TEST

START_TEST(test_sum_matrix_error_2) {
#line 125
  s21_matrix A;
  s21_create_matrix(2, 2, &A);
  int code = s21_sum_matrix(&A, NULL, NULL);
  ck_assert_int_eq(code, CODE1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_sum_matrix_error_3) {
#line 132
  s21_matrix A, B, res;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(code, CODE2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_error_4) {
#line 142
  s21_matrix A, B, res;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(code, CODE2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_error_5) {
#line 151
  s21_matrix A, B;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, CODE1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_error_6) {
#line 161
  s21_matrix A, B, res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 1, &B);

  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(code, CODE2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix) {
#line 175
  s21_matrix A, B, C, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 0;
  C.matrix[1][0] = 0;
  C.matrix[1][1] = 0;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub_matrix_error) {
#line 205
  int code = s21_sub_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(code, CODE1);
}
END_TEST

START_TEST(test_sub_matrix_error_2) {
#line 209
  s21_matrix A;
  s21_create_matrix(2, 2, &A);
  int code = s21_sub_matrix(&A, NULL, NULL);
  ck_assert_int_eq(code, CODE1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_sub_matrix_error_3) {
#line 216
  s21_matrix A, B, res;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(code, CODE2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_error_4) {
#line 226
  s21_matrix A, B, res;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(code, CODE2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_error_5) {
#line 236
  s21_matrix A, B;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, CODE1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_error_6) {
#line 246
  s21_matrix A, B, res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 5, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(code, CODE2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_number) {
#line 260
  s21_matrix A, C, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &C);
  C.matrix[0][0] = 2;
  C.matrix[0][1] = 4;
  C.matrix[1][0] = 6;
  C.matrix[1][1] = 8;

  ck_assert_int_eq(s21_mult_number(&A, 2, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_number_error) {
#line 283
  int code = s21_mult_number(NULL, 2, NULL);
  ck_assert_int_eq(code, CODE1);
}
END_TEST

START_TEST(test_mult_number_error_2) {
#line 287
  s21_matrix A;
  s21_create_matrix(2, 2, &A);
  int code = s21_mult_number(&A, 2, NULL);
  ck_assert_int_eq(code, CODE1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_matrix) {
#line 299
  s21_matrix A, B, C, res;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;

  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 9;
  C.matrix[0][1] = 11;
  C.matrix[0][2] = 17;
  C.matrix[1][0] = 12;
  C.matrix[1][1] = 13;
  C.matrix[1][2] = 22;
  C.matrix[2][0] = 15;
  C.matrix[2][1] = 15;
  C.matrix[2][2] = 27;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_matrix_2) {
#line 338
  s21_matrix A, B, C, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;

  s21_create_matrix(2, 1, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 5;

  s21_create_matrix(2, 1, &C);
  C.matrix[0][0] = 21;
  C.matrix[1][0] = 48;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mult_error) {
#line 364
  s21_matrix A, B, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;

  s21_create_matrix(2, 1, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 5;

  ck_assert_int_eq(s21_mult_matrix(&B, &A, &res), CODE2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_error_2) {
#line 382
  s21_matrix A, B;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;

  s21_create_matrix(2, 1, &B);
  B.matrix[0][0] = 1;
  B.matrix[1][0] = 5;

  ck_assert_int_eq(s21_mult_matrix(&B, &A, NULL), CODE1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_error_3) {
#line 400
  s21_matrix A;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;

  ck_assert_int_eq(s21_mult_matrix(&A, NULL, NULL), CODE1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_error_4) {
#line 413
  s21_matrix A;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 8;

  ck_assert_int_eq(s21_mult_matrix(NULL, &A, NULL), CODE1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_transpose_matrix) {
#line 430
  s21_matrix A, C, res;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  s21_create_matrix(2, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = 2;
  C.matrix[0][2] = 3;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = 5;
  C.matrix[1][2] = 6;

  ck_assert_int_eq(s21_transpose(&A, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &C), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose_matrix_2) {
#line 457
  s21_matrix A, C, res;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  s21_create_matrix(2, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = 2;
  C.matrix[0][2] = 3;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = 5;
  C.matrix[1][2] = 6;

  ck_assert_int_eq(s21_transpose(&C, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &A), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_transpose_error) {
#line 484
  s21_matrix A;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  ck_assert_int_eq(s21_transpose(&A, NULL), CODE1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_transpose_error_2) {
#line 499
  s21_matrix res;

  ck_assert_int_eq(s21_transpose(NULL, &res), CODE1);
}
END_TEST

START_TEST(test_determinant_1) {
#line 508
  s21_matrix A;
  double res = 0, original = -2;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);

  ck_assert_double_eq_tol(res, original, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_2) {
#line 523
  s21_matrix A;
  double res = 0, original = 0;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);

  ck_assert_double_eq_tol(res, original, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_3) {
#line 544
  s21_matrix A;
  double res = 0, original = 3;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);

  ck_assert_double_eq_tol(res, original, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_4) {
#line 565
  s21_matrix A;
  double res = 0, original = 84;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);

  ck_assert_double_eq_tol(res, original, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_5) {
#line 586
  s21_matrix A;
  double res = 0, original = -1;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);

  ck_assert_double_eq_tol(res, original, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_6) {
#line 607
  s21_matrix A;
  double res = 0;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;

  ck_assert_int_eq(s21_determinant(&A, &res), CODE2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_7) {
#line 623
  s21_matrix A;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  ck_assert_int_eq(s21_determinant(&A, NULL), CODE1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_8) {
#line 641
  ck_assert_int_eq(s21_determinant(NULL, NULL), CODE1);
}
END_TEST

START_TEST(test_determinant_zero_row) {
#line 644
  s21_matrix A;
  double res = 1.0;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 0.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_duplicate_rows) {
#line 664
  s21_matrix A;
  double res = 1.0;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 0.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_identity) {
#line 684
  s21_matrix A;
  double res = 0.0;

  s21_create_matrix(4, 4, &A);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A.matrix[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 1.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_upper_triangular) {
#line 700
  s21_matrix A;
  double res = 0.0;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 2 * 4 * 6, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_1x1) {
#line 720
  s21_matrix A;
  double res = 0.0;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 42.0;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 42.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_negative_fractions) {
#line 732
  s21_matrix A;
  double res = 0.0;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = -1.5;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.5;
  A.matrix[1][0] = 4.25;
  A.matrix[1][1] = -5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.75;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = -9.0;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 428.625, 1e-07);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_tiny_values) {
#line 752
  s21_matrix A;
  double res = 0.0;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1e-10;
  A.matrix[0][1] = 2e-10;
  A.matrix[0][2] = 3e-10;
  A.matrix[1][0] = 4e-10;
  A.matrix[1][1] = 5e-10;
  A.matrix[1][2] = 6e-10;
  A.matrix[2][0] = 7e-10;
  A.matrix[2][1] = 8e-10;
  A.matrix[2][2] = 9e-10;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 0.0, 1e-20);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_large_4x4) {
#line 771
  s21_matrix A;
  double res = 0.0;

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[1][3] = 2;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 1;
  A.matrix[3][0] = 9;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 1;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 24.0, 1e-07);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_almost_identity) {
#line 798
  s21_matrix A;
  double res = 0.0;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[0][2] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 0.0;
  A.matrix[2][1] = 0.0;
  A.matrix[2][2] = 0.999999;

  ck_assert_int_eq(s21_determinant(&A, &res), CODEOK);
  ck_assert_double_eq_tol(res, 0.999999, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_1) {
#line 823
  s21_matrix A, res, original;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  s21_create_matrix(3, 3, &original);
  original.matrix[0][0] = 0;
  original.matrix[0][1] = 10;
  original.matrix[0][2] = -20;
  original.matrix[1][0] = 4;
  original.matrix[1][1] = -14;
  original.matrix[1][2] = 8;
  original.matrix[2][0] = -8;
  original.matrix[2][1] = -2;
  original.matrix[2][2] = 4;

  ck_assert_int_eq(s21_calc_complements(&A, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &original), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&original);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_calc_complements_2) {
#line 856
  s21_matrix A;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  ck_assert_int_eq(s21_calc_complements(&A, NULL), CODE1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_3) {
#line 874
  s21_matrix res;

  ck_assert_int_eq(s21_calc_complements(NULL, &res), CODE1);
}
END_TEST

START_TEST(test_calc_complements_4) {
#line 879
  s21_matrix A, res, original;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  s21_create_matrix(2, 2, &original);
  original.matrix[0][0] = 4;
  original.matrix[0][1] = -3;
  original.matrix[1][0] = -2;
  original.matrix[1][1] = 1;

  ck_assert_int_eq(s21_calc_complements(&A, &res), CODEOK);
  ck_assert_int_eq(s21_eq_matrix(&res, &original), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&original);
}
END_TEST

START_TEST(test_calc_complements_5) {
#line 901
  s21_matrix A, res, original;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;

  s21_create_matrix(3, 3, &original);
  original.matrix[0][0] = -8;
  original.matrix[0][1] = 17;
  original.matrix[0][2] = 2;
  original.matrix[1][0] = -4;
  original.matrix[1][1] = -5;
  original.matrix[1][2] = 10;
  original.matrix[2][0] = 8;
  original.matrix[2][1] = 1;
  original.matrix[2][2] = -2;

  ck_assert_int_eq(s21_calc_complements(&A, &res), CODEOK);
  ck_assert_int_eq(s21_eq_matrix(&res, &original), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&original);
}
END_TEST

START_TEST(test_calc_complements_identity) {
#line 933
  s21_matrix A, res, original;

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &original);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      A.matrix[i][j] = (i == j) ? 1 : 0;
    }
  }

  original.matrix[0][0] = 1;
  original.matrix[0][1] = 0;
  original.matrix[0][2] = 0;
  original.matrix[0][3] = 0;
  original.matrix[1][0] = 0;
  original.matrix[1][1] = 1;
  original.matrix[1][2] = 0;
  original.matrix[1][3] = 0;
  original.matrix[2][0] = 0;
  original.matrix[2][1] = 0;
  original.matrix[2][2] = 1;
  original.matrix[2][3] = 0;
  original.matrix[3][0] = 0;
  original.matrix[3][1] = 0;
  original.matrix[3][2] = 0;
  original.matrix[3][3] = 1;

  ck_assert_int_eq(s21_calc_complements(&A, &res), CODEOK);
  ck_assert_int_eq(s21_eq_matrix(&res, &original), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&original);
}
END_TEST

START_TEST(test_calc_complements_6) {
#line 969
  s21_matrix A, res;

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  ck_assert_int_eq(s21_calc_complements(&A, &res), CODE2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_1) {
#line 990
  s21_matrix A, res, original;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  s21_create_matrix(3, 3, &original);
  original.matrix[0][0] = 1;
  original.matrix[0][1] = -1;
  original.matrix[0][2] = 1;
  original.matrix[1][0] = -38;
  original.matrix[1][1] = 41;
  original.matrix[1][2] = -34;
  original.matrix[2][0] = 27;
  original.matrix[2][1] = -29;
  original.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CODEOK);

  ck_assert_int_eq(s21_eq_matrix(&res, &original), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&original);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
#line 1023
  s21_matrix A;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), CODE1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
#line 1041
  s21_matrix A, res;

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CODE2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
#line 1056
  s21_matrix res;

  ck_assert_int_eq(s21_inverse_matrix(NULL, &res), CODE1);
}
END_TEST

START_TEST(test_inverse_matrix_5) {
#line 1061
  s21_matrix A, res, original;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  s21_create_matrix(1, 1, &original);
  original.matrix[0][0] = 0.5;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CODEOK);
  ck_assert_int_eq(s21_eq_matrix(&res, &original), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&original);
}
END_TEST

START_TEST(test_inverse_fractions) {
#line 1077
  s21_matrix A, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 0.5;
  A.matrix[0][1] = -1.5;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 3.0;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CODEOK);

  ck_assert_double_eq_tol(res.matrix[0][0], 0.666667, 1e-06);
  ck_assert_double_eq_tol(res.matrix[0][1], 0.333333, 1e-06);
  ck_assert_double_eq_tol(res.matrix[1][0], -0.444444, 1e-06);
  ck_assert_double_eq_tol(res.matrix[1][1], 0.111111, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_inverse_singular) {
#line 1098
  s21_matrix A, res;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CODE2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_6) {
#line 1111
  s21_matrix A, res;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 0;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CODE2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_7) {
#line 1121
  s21_matrix A, res;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(s21_inverse_matrix(&A, &res), CODE2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_huge_matrix) {
  s21_matrix m;
  int code = s21_create_matrix(1000000000, 1000000000, &m);
  if (code == 0) s21_remove_matrix(&m);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_matrix");
  TCase *tc1_1 = tcase_create("Interface");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_create_matrix_success);
  tcase_add_test(tc1_1, test_create_matrix_invalid);
  tcase_add_test(tc1_1, test_create_matrix_invalid_2);
  tcase_add_test(tc1_1, test_create_matrix_invalid_3);
  tcase_add_test(tc1_1, test_eq_matrix_equal);
  tcase_add_test(tc1_1, test_eq_matrix_not_equal);
  tcase_add_test(tc1_1, test_eq_matrix_diff_size);
  tcase_add_test(tc1_1, test_eq_matrix_diff_size_2);
  tcase_add_test(tc1_1, test_sum_matrix);
  tcase_add_test(tc1_1, test_sum_matrix_error);
  tcase_add_test(tc1_1, test_sum_matrix_error_2);
  tcase_add_test(tc1_1, test_sum_matrix_error_3);
  tcase_add_test(tc1_1, test_sum_matrix_error_4);
  tcase_add_test(tc1_1, test_sum_matrix_error_5);
  tcase_add_test(tc1_1, test_sum_matrix_error_6);
  tcase_add_test(tc1_1, test_sub_matrix);
  tcase_add_test(tc1_1, test_sub_matrix_error);
  tcase_add_test(tc1_1, test_sub_matrix_error_2);
  tcase_add_test(tc1_1, test_sub_matrix_error_3);
  tcase_add_test(tc1_1, test_sub_matrix_error_4);
  tcase_add_test(tc1_1, test_sub_matrix_error_5);
  tcase_add_test(tc1_1, test_sub_matrix_error_6);
  tcase_add_test(tc1_1, test_mult_number);
  tcase_add_test(tc1_1, test_mult_number_error);
  tcase_add_test(tc1_1, test_mult_number_error_2);
  tcase_add_test(tc1_1, test_mult_matrix);
  tcase_add_test(tc1_1, test_mult_matrix_2);
  tcase_add_test(tc1_1, test_mult_error);
  tcase_add_test(tc1_1, test_mult_error_2);
  tcase_add_test(tc1_1, test_mult_error_3);
  tcase_add_test(tc1_1, test_mult_error_4);
  tcase_add_test(tc1_1, test_transpose_matrix);
  tcase_add_test(tc1_1, test_transpose_matrix_2);
  tcase_add_test(tc1_1, test_transpose_error);
  tcase_add_test(tc1_1, test_transpose_error_2);
  tcase_add_test(tc1_1, test_determinant_1);
  tcase_add_test(tc1_1, test_determinant_2);
  tcase_add_test(tc1_1, test_determinant_3);
  tcase_add_test(tc1_1, test_determinant_4);
  tcase_add_test(tc1_1, test_determinant_5);
  tcase_add_test(tc1_1, test_determinant_6);
  tcase_add_test(tc1_1, test_determinant_7);
  tcase_add_test(tc1_1, test_determinant_8);
  tcase_add_test(tc1_1, test_determinant_zero_row);
  tcase_add_test(tc1_1, test_determinant_duplicate_rows);
  tcase_add_test(tc1_1, test_determinant_identity);
  tcase_add_test(tc1_1, test_determinant_upper_triangular);
  tcase_add_test(tc1_1, test_determinant_1x1);
  tcase_add_test(tc1_1, test_determinant_negative_fractions);
  tcase_add_test(tc1_1, test_determinant_tiny_values);
  tcase_add_test(tc1_1, test_determinant_large_4x4);
  tcase_add_test(tc1_1, test_determinant_almost_identity);
  tcase_add_test(tc1_1, test_calc_complements_1);
  tcase_add_test(tc1_1, test_calc_complements_2);
  tcase_add_test(tc1_1, test_calc_complements_3);
  tcase_add_test(tc1_1, test_calc_complements_4);
  tcase_add_test(tc1_1, test_calc_complements_5);
  tcase_add_test(tc1_1, test_calc_complements_identity);
  tcase_add_test(tc1_1, test_calc_complements_6);
  tcase_add_test(tc1_1, test_inverse_matrix_1);
  tcase_add_test(tc1_1, test_inverse_matrix_2);
  tcase_add_test(tc1_1, test_inverse_matrix_3);
  tcase_add_test(tc1_1, test_inverse_matrix_4);
  tcase_add_test(tc1_1, test_inverse_matrix_5);
  tcase_add_test(tc1_1, test_inverse_fractions);
  tcase_add_test(tc1_1, test_inverse_singular);
  tcase_add_test(tc1_1, test_inverse_matrix_6);
  tcase_add_test(tc1_1, test_inverse_matrix_7);
  tcase_add_test(tc1_1, create_huge_matrix);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
