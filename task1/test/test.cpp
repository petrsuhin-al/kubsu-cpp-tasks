//
// Created by Alexander Petrushin on 25.04.2021.
//

#include <iostream>
#include "../classic.h"
#include "../blocks.h"

using namespace std;

void printMatrix(string title, vector<vector<double>> matrix, chrono::steady_clock::time_point startTime, chrono::steady_clock::time_point endTime) {
    cout << title << endl;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ' ';
        }

        cout << endl;
    }

    cout << "\n" << "TIME: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " microseconds" << endl;
    cout << "\n\n";
}

void printFlattenMatrix(string title, double* flatMatrix, int size, chrono::steady_clock::time_point startTime, chrono::steady_clock::time_point endTime) {
    cout << title << endl;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << flatMatrix[i * size + j] << ' ';
        }

        cout << endl;
    }

    cout << "\n" << "TIME: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() << " microseconds" << endl;
    cout << "\n\n";
}

void TestClassicMult() {
    vector<vector<double>> first = {
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 1, 1, 4, 5, 6}
    };
    vector<vector<double>> second = {
            {2, 2, 2, 2, 2, 2, 2, 2},
            {3, 3, 3, 3, 3, 3, 3, 3},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {4, 0, 0, 0, 0, 0, 0, 2},
            {4, 0, 0, 0, 0, 0, 0, 2},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1}
    };

    chrono::steady_clock::time_point startTime = chrono::steady_clock::now();
    auto solution = Classic(first, second);
    chrono::steady_clock::time_point endTime = chrono::steady_clock::now();

    printMatrix("Classic matrix multiplication:", solution, startTime, endTime);
}

void TestVectorBlocksMult() {
    vector<vector<double>> first = {
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 0, 0, 4, 5, 6},
            {1, 2, 3, 1, 1, 4, 5, 6}
    };
    vector<vector<double>> second = {
            {2, 2, 2, 2, 2, 2, 2, 2},
            {3, 3, 3, 3, 3, 3, 3, 3},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {4, 0, 0, 0, 0, 0, 0, 2},
            {4, 0, 0, 0, 0, 0, 0, 2},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1}
    };

    chrono::steady_clock::time_point startTime = chrono::steady_clock::now();
    auto solution = VectorBlocks(first, second);
    chrono::steady_clock::time_point endTime = chrono::steady_clock::now();

    printMatrix("Vector blocks matrix multiplication:", solution, startTime, endTime);
}

void TestBlocksMult() {
    int rowCount = 8;
    int itemsCount = rowCount * rowCount;

    double solutionMatrix[64];

    const double first[64] = {
            1, 2, 3, 0, 0, 4, 5, 6,
            1, 2, 3, 0, 0, 4, 5, 6,
            1, 2, 3, 0, 0, 4, 5, 6,
            1, 2, 3, 0, 0, 4, 5, 6,
            1, 2, 3, 0, 0, 4, 5, 6,
            1, 2, 3, 0, 0, 4, 5, 6,
            1, 2, 3, 0, 0, 4, 5, 6,
            1, 2, 3, 1, 1, 4, 5, 6
    };
    const double second[64] = {
            2, 2, 2, 2, 2, 2, 2, 2,
            3, 3, 3, 3, 3, 3, 3, 3,
            0, 0, 0, 0, 0, 0, 0, 0,
            4, 0, 0, 0, 0, 0, 0, 2,
            4, 0, 0, 0, 0, 0, 0, 2,
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1
    };

    chrono::steady_clock::time_point startTime = chrono::steady_clock::now();
    Blocks(solutionMatrix, first, second, rowCount, rowCount);
    chrono::steady_clock::time_point endTime = chrono::steady_clock::now();

    printFlattenMatrix("Blocks matrix multiplication:", solutionMatrix, rowCount, startTime, endTime);
}

int main() {
    TestClassicMult();
    TestVectorBlocksMult();
    TestBlocksMult();

    return 0;
}
