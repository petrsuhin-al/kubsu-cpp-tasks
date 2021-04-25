//
// Created by Александр Петрушин on 25.04.2021.
//

#include <iostream>
#include "../classic.h"

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
    vector<vector<double>> first = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    vector<vector<double>> second = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};

    auto solution = Classic(first, second);

    printMatrix("Classic matrix multiplication:", solution);
}

int main() {
    TestClassicMult();

    return 0;
}
