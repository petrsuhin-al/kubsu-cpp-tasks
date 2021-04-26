//
// Created by Александр Петрушин on 26.04.2021.
//

#ifndef ALS_GRADIENT_H
#define ALS_GRADIENT_H

#include <vector>
#include <functional>

using namespace std;

vector<double> GradientSolve(std::function<double(vector<double> )> , vector<double> , double , int );

#endif //ALS_GRADIENT_H
