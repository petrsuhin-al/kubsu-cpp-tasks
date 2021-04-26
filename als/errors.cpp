//
// Created by Александр Петрушин on 26.04.2021.
//

#include "errors.h"
#include <vector>
#include <cmath>

using namespace std;

double MAE(vector<double> v1, vector<double> v2)
{
    double sum = 0;

    for (int i = 0; i < v1.size(); i++) {
        sum += fabs(v1[i] - v2[i]);
    }

    return sum / v1.size();
}

double MSE(vector<double> v1, vector<double> v2)
{
    double sum = 0;

    for (int i = 0; i < v1.size(); i++) {
        double value = v1[i] - v2[i];
        sum += value * value;
    }

    return sum / v1.size();
}