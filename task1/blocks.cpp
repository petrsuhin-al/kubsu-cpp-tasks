//
// Created by Александр Петрушин on 26.04.2021.
//

#include "blocks.h"
#include <vector>
#include <iostream>

using namespace std;

double* FlattenMatrix(vector<vector<double>> matrix)
{
    int matrixSize = matrix.size();

    double* flattenMatrix = new double[matrixSize * matrixSize];
    int index = 0;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); j++) {
            flattenMatrix[index] = matrix[i][j];
            index++;
        }
    }

    return flattenMatrix;
}

vector<vector<double>> parseToMatrix(double* matrix, int size)
{
    vector<vector<double>> resultMatrix(size);
    int colIndex = 0;

    for (int i = 0; i < size * size; ++i) {
        resultMatrix[colIndex][i] = matrix[i];

        if (i % size == 0) {
            colIndex++;
        }
    }

    return resultMatrix;
}

void MultBlocks(double *C, const double *A, const double *B, int n, int rowsize)
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

        MultBlocks(C + d11, A + d11, B + d11, n / 2, rowsize);
        MultBlocks(C + d11, A + d12, B + d21, n / 2, rowsize);
        MultBlocks(C + d12, A + d11, B + d12, n / 2, rowsize);
        MultBlocks(C + d12, A + d12, B + d22, n / 2, rowsize);
        MultBlocks(C + d21, A + d21, B + d11, n / 2, rowsize);
        MultBlocks(C + d21, A + d22, B + d21, n / 2, rowsize);
        MultBlocks(C + d22, A + d21, B + d12, n / 2, rowsize);
        MultBlocks(C + d22, A + d22, B + d22, n / 2, rowsize);
    }
}

vector<vector<double>> Blocks(vector<vector<double>> firstMatrix, vector<vector<double>> secondMatrix)
{
    int solutionMatrixSize = firstMatrix.size();

    double solutionMatrix[solutionMatrixSize * solutionMatrixSize];
    memset(solutionMatrix, 0, sizeof(solutionMatrix));

    double* flattenFirstMatrix = FlattenMatrix(firstMatrix);
    double* flattenSecondMatrix = FlattenMatrix(secondMatrix);


    for (int i = 0; i < 8*8; ++i) {
        cout << "row" << flattenFirstMatrix[i] << ' ';
    }

    MultBlocks(solutionMatrix, flattenFirstMatrix, flattenSecondMatrix, solutionMatrixSize, solutionMatrixSize);

    return parseToMatrix(solutionMatrix, solutionMatrixSize);
}
