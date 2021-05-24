//
// Created by Александр Петрушин on 27.04.2021.
//

#include "main.h"
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include "permutations.h"

using namespace std;

double RandomValue()
{
    return rand() % 100;
}

void InitData(int aRows, int bCols, int vecLen, double **&A, double **&B, double **&C)
{
    A = new double *[aRows];
    B = new double *[vecLen];
    C = new double *[aRows];

    for (int i = 0; i < aRows; i++) {
        A[i] = new double[vecLen];
        C[i] = new double[bCols];
    }
    for (int i = 0; i < vecLen; i++) {
        B[i] = new double[b_cols];
    }

    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            for (int k = 0; k < vecLen; k++) {
                A[i][k] = RandomValue();
                B[k][j] = RandomValue();
                C[i][j] = 0;
            }
        }
    }
}

void Delete(int aRows, int size, double **&A, double **&B, double **&C)
{
    for (int i = 0; i < aRows; i++) {
        delete[] A[i];
        delete[] C[i];
    }
    for (int i = 0; i < size; i++) {
        delete[] B[i];
    }

    delete A;
    delete B;
    delete C;
}

void Evaluate(int type, int aRows, int bCols, int vecLen, double **&A, double **&B, double **&C)
{

    switch (type)
    {
        case 0:
            ijk(A, B, aRows, bCols, vecLen, C);
            break;
        case 1:
            ikj(A, B, aRows, bCols, vecLen, C);
            break;
        case 2:
            jik(A, B, aRows, bCols, vecLen, C);
            break;
        case 3:
            jki(A, B, aRows, bCols, vecLen, C);
            break;
        case 4:
            kij(A, B, aRows, bCols, vecLen, C);
            break;
        case 5:
            kji(A, B, aRows, bCols, vecLen, C);
            break;
        default:
            break;
    }
}

int main()
{
    vector<string> types = {"ijk", "ikj", "jik", "jki", "kij", "kji"};
    vector<int> sizes = {500, 1000, 2000};

    for (int s = 0; s < types.size(); s++) {
        cout << "Type: " << types[s] << endl;

        for (int v = 0; v < sizes.size(); v++) {
            int aRows = sizes[v];
            int bCols = sizes[v];
            int vecLen = sizes[v];

            double **A, **B, **C;
            InitData(aRows, bCols, vecLen, A, B, C);

            chrono::steady_clock::time_point startTime = chrono::steady_clock::now();
            Evaluate(s, aRows, bCols, vecLen, A, B, C);
            chrono::steady_clock::time_point endTime = chrono::steady_clock::now();

            Delete(aRows, vecLen, A, B, C);

            std::cout << "size = " << sizes[v] << "  time = " << chrono::duration_cast<chrono::seconds>(endTime - startTime).count() << endl;
        }
    }

    return 0;
}