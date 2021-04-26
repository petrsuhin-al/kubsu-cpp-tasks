//
// Created by Александр Петрушин on 26.04.2021.
//

#include "gradient.h"
#include <vector>
#include <functional>
#include "gradient.h"

using namespace std;

//typedef double vec2float (vector<double>);

vector<double> Gradient(std::function<double(vector<double> )> f, vector<double> start, double eps = 0.001)
{
    int size = start.size();

    double p1, p2, m1, m2, tmp;

    vector<double> gradient(size);

    for(int i = 0; i < size; i++) {
        tmp = start[i];

        start[i] += eps;
        p1 = f(start);
        start[i] += eps;
        p2 = f(start);

        start[i] = tmp - eps;
        m1 = f(start);
        start[i] += tmp - 2 * eps;
        m2 = f(start);

        gradient[i] = (m2 - 8 * m1 + 8 * p1 - p2)/(12 * eps);

        start[i] = tmp;
    }

    return gradient;
}


vector<double> GradientSolve(std::function<double(vector<double> )> f, vector<double> start, double lr = 0.01, int iter = 1000)
{
    int size = start.size();

    for(int i = 0;i < iter; i++) {
        Gradient(f, start);

        for (int j =0; j< size;j++) {
            start[j] -= start[j]*lr;
        }
    }

    return start;
}
