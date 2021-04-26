//
// Created by Alexander Petrushin on 26.04.2021.
//

#include "blocks.h"
#include <vector>

using namespace std;

double* FlattenMatrix(vector<vector<double>> matrix)
{
    int matrixSize = matrix.size();

    double* flattenMatrix = new double[matrixSize * matrixSize];
    int index = 0;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            flattenMatrix[index] = matrix[i][j];
            index++;
        }
    }

    return flattenMatrix;
}

vector<vector<double>> parseToMatrix(double* matrix, int size)
{
    vector<vector<double>> resultMatrix(size, vector<double>(size));

    int rowIndex = 0, colIndex = 0;

    for (int i = 0; i < size * size; i++) {
        resultMatrix[rowIndex][colIndex] = matrix[i];
        colIndex++;

        if ((i + 1) % size == 0) {
            colIndex = 0;
            rowIndex++;
        }
    }

    return resultMatrix;
}

void Blocks(double *C, const double *A, const double *B, int n, int rowsize)
{
    if (n == 2) {
        const int d11 = 0;
        const int d12 = 1;
        const int d21 = rowsize;
        const int d22 = rowsize + 1;

        C[d11] += A[d11] * B[d11] + A[d12] * B[d21];
        C[d12] += A[d11] * B[d12] + A[d12] * B[d22];
        C[d21] += A[d21] * B[d11] + A[d22] * B[d21];
        C[d22] += A[d21] * B[d12] + A[d22] * B[d22];
    } else {
        const int d11 = 0;
        const int d12 = n / 2;
        const int d21 = (n / 2) * rowsize;
        const int d22 = (n / 2) * (rowsize + 1);

        Blocks(C + d11, A + d11, B + d11, n / 2, rowsize);
        Blocks(C + d11, A + d12, B + d21, n / 2, rowsize);
        Blocks(C + d12, A + d11, B + d12, n / 2, rowsize);
        Blocks(C + d12, A + d12, B + d22, n / 2, rowsize);
        Blocks(C + d21, A + d21, B + d11, n / 2, rowsize);
        Blocks(C + d21, A + d22, B + d21, n / 2, rowsize);
        Blocks(C + d22, A + d21, B + d12, n / 2, rowsize);
        Blocks(C + d22, A + d22, B + d22, n / 2, rowsize);
    }
}

vector<vector<double>> VectorBlocks(vector<vector<double>> firstMatrix, vector<vector<double>> secondMatrix)
{
    int solutionMatrixSize = firstMatrix.size();

    double solutionMatrix[solutionMatrixSize * solutionMatrixSize];
    memset(solutionMatrix, 0, sizeof(solutionMatrix));

    double* flattenFirstMatrix = FlattenMatrix(firstMatrix);
    double* flattenSecondMatrix = FlattenMatrix(secondMatrix);

    Blocks(solutionMatrix, flattenFirstMatrix, flattenSecondMatrix, solutionMatrixSize, solutionMatrixSize);

    return parseToMatrix(solutionMatrix, solutionMatrixSize);
}
