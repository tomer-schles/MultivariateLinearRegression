//
// Created by Tomer Schlesinger on 25/06/2016.
//

#ifndef TWO_VARIABLE_LINEAR_REGRESSION_H
#define TWO_VARIABLE_LINEAR_REGRESSION_H

#include <vector>
using namespace std;


vector<vector<double>> loadDataSet(string path, string seperator = ",");
double costFunction(double a, double b, vector<double> x, vector<double> y, vector<double> label);
double hypothesis(double a, double b, double x, double y);
vector<double> hypothesis(double a, double b, vector<double> x, vector<double> y);

// vector arithmetics

vector<double> operator-(vector<double> a, vector<double> b);
vector<double> operator+(vector<double> a, vector<double> b);
double operator*(vector<double> a, vector<double> b);
vector<double> operator*(vector<double> a, double scallar);
vector<double> operator*(double scallar, vector<double> a);

#endif //TWO_VARIABLE_LINEAR_REGRESSION_H


