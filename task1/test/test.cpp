//
// Created by Alexander Petrushin on 25.04.2021.
//

#include <iostream>
#include "../classic.h"
#include "../blocks.h"

using namespace std;

void printMatrix(string title, vector<vector<double>> matrix) {
    cout << title << endl;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << ' ';
        }

        cout << "\n";
    }
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

    auto solution = Classic(first, second);

    printMatrix("Classic matrix multiplication:", solution);
}

void TestBlocksMult() {
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

    auto solution = Blocks(first, second);
    printMatrix("Blocks matrix multiplication:", solution);
//
//    const double matA[8*8] =
//            {
//                    1, 2, 3, 0, 0, 4, 5, 6,
//                    1, 2, 3, 0, 0, 4, 5, 6,
//                    1, 2, 3, 0, 0, 4, 5, 6,
//                    1, 2, 3, 0, 0, 4, 5, 6,
//                    1, 2, 3, 0, 0, 4, 5, 6,
//                    1, 2, 3, 0, 0, 4, 5, 6,
//                    1, 2, 3, 0, 0, 4, 5, 6,
//                    1, 2, 3, 1, 1, 4, 5, 6,
//            };
//
//    const double matB[8*8] =
//            {
//                    2, 2, 2, 2, 2, 2, 2, 2,
//                    3, 3, 3, 3, 3, 3, 3, 3,
//                    0, 0, 0, 0, 0, 0, 0, 0,
//                    4, 0, 0, 0, 0, 0, 0, 2,
//                    4, 0, 0, 0, 0, 0, 0, 2,
//                    0, 0, 0, 0, 0, 0, 0, 0,
//                    0, 0, 0, 0, 0, 0, 0, 0,
//                    1, 1, 1, 1, 1, 1, 1, 1,
//            };
//
//    double matC[8*8];
//    memset(matC, 0, sizeof(matC));
//
////    Blocks(matC, matA, matB, 8, 8);
//
//
//    cout << "Blocks matrix multiplication:" << endl;
//
//    for (int i = 0; i < 8*8; ++i) {
//        if (i % 8 == 0) {
//            cout << "\n";
//        }
//        cout << matC[i] << ' ';
//    }
}

int main() {
//    TestClassicMult();
    TestBlocksMult();

    return 0;
}
