//
// Created by Александр Петрушин on 27.04.2021.
//

#ifndef LARGE_MATRIX_PERMUTATIONS_H
#define LARGE_MATRIX_PERMUTATIONS_H

void ijk(double **&A, double **&B, int a_rows, int b_cols, int vec_len, double **&C);
void ikj(double **&A, double **&B, int a_rows, int b_cols, int vec_len, double **&C);
void jik(double **&A, double **&B, int a_rows, int b_cols, int vec_len, double **&C);
void jki(double **&A, double **&B, int a_rows, int b_cols, int vec_len, double **&C);
void kij(double **&A, double **&B, int a_rows, int b_cols, int vec_len, double **&C);
void kji(double **&A, double **&B, int a_rows, int b_cols, int vec_len, double **&C);
void ijk2(double *&A, double *&B, int a_rows, int b_cols, int vec_len, double *&C);
void ikj2(double *&A, double *&B, int a_rows, int b_cols, int vec_len, double *&C);
void jik2(double *&A, double *&B, int a_rows, int b_cols, int vec_len, double *&C);
void jki2(double *&A, double *&B, int a_rows, int b_cols, int vec_len, double *&C);
void kij2(double *&A, double *&B, int a_rows, int b_cols, int vec_len, double *&C);
void kji2(double *&A, double *&B, int a_rows, int b_cols, int vec_len, double *&C);

#endif //LARGE_MATRIX_PERMUTATIONS_H
