//
// Created by Александр Петрушин on 25.04.2021.
//

#include "classic.h"
#include <vector>

using namespace std;

vector<vector<double>> Classic(vector<vector<double>> firstMatrix, vector<vector<double>> secondMatrix)
{
    vector<vector<double>> resultMatrix(firstMatrix.size());

    for (int i = 0; i < firstMatrix.size(); i++) {
        resultMatrix[i].resize(secondMatrix[0].size());

        for (int j = 0; j < secondMatrix[0].size(); j++) {
            resultMatrix[i][j] = 0;

            for (int k = 0; k < firstMatrix[i].size(); k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }

    return resultMatrix;
}
