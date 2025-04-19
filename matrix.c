#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* createMatrix(int rows, int cols, int** inputData) {
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        m->data[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            m->data[i][j] = inputData[i][j];
        }
    }
    return m;
}

void deleteMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; ++i) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void printMatrix(const Matrix* m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(Matrix* m) {
    int** temp = (int**)malloc(m->cols * sizeof(int*));
    for (int i = 0; i < m->cols; ++i) {
        temp[i] = (int*)malloc(m->rows * sizeof(int));
    }

    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            temp[j][i] = m->data[i][j];
        }
    }

    for (int i = 0; i < m->rows; ++i) free(m->data[i]);
    free(m->data);

    int tmp = m->rows;
    m->rows = m->cols;
    m->cols = tmp;
    m->data = temp;
}

void addMatrix(Matrix* m1, const Matrix* m2) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            m1->data[i][j] += m2->data[i][j];
        }
    }
}

void multiplyMatrix(Matrix* m1, const Matrix* m2) {
    if (m1->cols != m2->rows) {
        printf("Incompatible matrices for multiplication.\n");
        exit(1);
    }

    int** result = (int**)malloc(m1->rows * sizeof(int*));
    for (int i = 0; i < m1->rows; ++i) {
        result[i] = (int*)calloc(m2->cols, sizeof(int));
    }

    for (int i = 0; i < m1->rows; ++i) {
        for (int j = 0; j < m2->cols; ++j) {
            for (int k = 0; k < m1->cols; ++k) {
                result[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }

    for (int i = 0; i < m1->rows; ++i) free(m1->data[i]);
    free(m1->data);

    m1->data = result;
    m1->cols = m2->cols;
}

void multiplyMatrixByScalar(Matrix* m, int num) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            m->data[i][j] *= num;
        }
    }
}
