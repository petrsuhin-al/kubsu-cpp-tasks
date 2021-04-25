//
// Created by Александр Петрушин on 25.04.2021.
//

#include <iostream>
#include "classic.h"

using namespace std;

void TestClassicMult() {
    vector<vector<double>> first = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    vector<vector<double>> second = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};

    auto solution = Classic(first, second);

    cout << "Classic matrix multiplication: " << endl;

    for (int i = 0; i < solution.size(); ++i) {
        for (int j = 0; j < solution[i].size(); j++) {
            cout << solution[i][j] << ' ';
        }

        cout << "\n";
    }
}

int main() {
    TestClassicMult();

    return 0;
}
