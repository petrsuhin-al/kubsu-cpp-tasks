//
// Created by Александр Петрушин on 26.04.2021.
//

#include <vector>
#include <functional>
#include <iostream>
#include <fstream>

#include "linear_regression.h"
#include "gradient.h"
#include "errors.h"
//#include "matplotlibcpp.h"

using namespace std;

std::function<double(double)> Eval(vector<double> input, vector<double> output, vector<double> start_params)
{
    auto function = [](double v, vector<double> params) {
        return params[0] * (v * v) + params[1] * v + params[2];
    };

    auto minized = [input, output, function](vector<double> params) {
        vector<double> result(input.size());

        for (int i = 0; i < input.size(); i++) {
            result[i] = function(input[i], params);
        }

        return MSE(result, output);
    };

    auto best_params = GradientSolve((std::function<double(vector<double>)>)minized, start_params, 0.01, 1000);

    return [best_params, function](double v) {
        return function(v, best_params);
    };
}

int main()
{
    vector<double> input = {1.25, 1.5, 1.75, 2, 2.25, 2.5, 2.75, 3};
    vector<double> output = {5.21, 4.196, 3.759, 3.672, 4.592, 4.621, 5.758, 7.173, 9.269};

    int size = input.size();

    auto evalFunc = Eval(input, output, {1, 1, 1});
    auto regression = LinearRegression(input, output);

    vector<double> nonLinearRegressionOut(size), linearRegressionOut(size);

    for (int i = 0; i < size; i++) {
        nonLinearRegressionOut[i] = evalFunc(input[i]);
        linearRegressionOut[i] = regression(input[i]);
    }

    cout << "MSE for non-linear regression = " << MSE(output, nonLinearRegressionOut) << endl;
    cout << "MSE for linear regression = " << MSE(output, linearRegressionOut) << endl;

//    matplotlibcpp::figure_size(1200, 780);
//    matplotlibcpp::named_plot("target", input);
//    matplotlibcpp::named_plot("linear", out2);
//    matplotlibcpp::named_plot("linear", out1);
//    matplotlibcpp::title("Sample figure");
//    matplotlibcpp::legend();
//    matplotlibcpp::save("./basic.png");

    return 0;
}