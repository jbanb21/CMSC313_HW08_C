#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix* createMatrix(int rows, int cols, int** inputData);
void deleteMatrix(Matrix* m);
void printMatrix(const Matrix* m);
void transposeMatrix(Matrix* m);
void addMatrix(Matrix* m1, const Matrix* m2);
void multiplyMatrix(Matrix* m1, const Matrix* m2);
void multiplyMatrixByScalar(Matrix* m, int num);

#endif
#pragma once
