#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int** makeMatrix(int rows, int cols, int vals[rows][cols]) {
    int** mat = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        mat[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = vals[i][j];
        }
    }
    return mat;
}

int main() {
    printf("D = A + (3 * B) x C^T\nCalculating...\n");

    int a_vals[2][2] = { {6, 4}, {8, 3} };
    int b_vals[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int c_vals[2][3] = { {2, 4, 6}, {1, 3, 5} };

    Matrix* A = createMatrix(2, 2, makeMatrix(2, 2, a_vals));
    Matrix* B = createMatrix(2, 3, makeMatrix(2, 3, b_vals));
    Matrix* C = createMatrix(2, 3, makeMatrix(2, 3, c_vals));

    transposeMatrix(C);
    multiplyMatrixByScalar(B, 3);
    multiplyMatrix(B, C);
    addMatrix(A, B);

    printMatrix(A);

    deleteMatrix(A);
    deleteMatrix(B);
    deleteMatrix(C);

    return 0;
}
