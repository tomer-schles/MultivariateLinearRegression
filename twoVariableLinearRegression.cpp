#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "twoVariableLinearRegression.h"

using namespace std;

int main() {
    vector<double> x = {1,2,3,4,5};
    vector<double> y = {1,2,3,4,5};
    vector<double> label = x*5 + y * 6.4;

    auto ds = loadDataSet(".\\data\\ex1data1.txt");

    while (true){
        double a,b;
        cout << "Choose a: ";
        cin >> a;
        cout << endl << "Choose b: ";
        cin >> b;
        cout << endl << "Cost funtion: " << costFunction(a,b,x,y,label) << endl;
    }

    return 0;
}
// Intro to DataScience, 2 variable linear regression by Tomer Schlesinger
// Gvaaim Lesson with Yooda Or at Hakfar Hayarok

// The hypothesis function is in the form of: a*x + b*y = label
// The cost function is: costFunction = SumOF ((hypothesis(a,b,x,y) - label)**2)

// Some vector arithmetic

vector<double> operator-(vector<double> a, vector<double> b){
    vector<double> v;
    for(auto itrA=a.begin(), itrB=b.begin() ; itrA != a.end() ; ++itrA, ++itrB){
        v.push_back(*itrA-*itrB);
    }
    return v;
}
vector<double> operator+(vector<double> a, vector<double> b){
    vector<double> v;
    for(auto itrA=a.begin(), itrB=b.begin() ; itrA != a.end() ; ++itrA, ++itrB){
        v.push_back(*itrA+*itrB);
    }
    return v;
}
double operator*(vector<double> a, vector<double> b){
    double sum = 0.0;
    for(auto itrA=a.begin(), itrB=b.begin() ; itrA != a.end() ; ++itrA, ++itrB){
        sum += *itrA * *itrB;
    }
    return sum;
}


vector<double> operator*(vector<double> a, double scallar){
    vector<double> v;
    for (auto x : a){
        v.push_back(x*scallar);
    }
    return v;
}
vector<double> operator*(double scallar, vector<double> a) {
    return a*scallar;
}


double hypothesis(double a, double b, double x, double y) {
    return x*a+y*b;
}
vector<double> hypothesis(double a, double b, vector<double> x, vector<double> y){
    vector<double> v;
    for(auto itrX=x.begin(), itrY=y.begin() ; itrX != x.end() ; ++itrX, ++itrY){
        v.push_back(hypothesis(a,b,*itrX,*itrY));
    }
    return v;
}

double costFunction(double a, double b, vector<double> x, vector<double> y, vector<double> label){
    auto delta = hypothesis(a,b, x,y)-label;
    return (delta * delta)/(2*x.size());
}

vector<vector<double>> loadDataSet(string path, string seperator){
    vector<vector<double>> ds;
    ifstream datasetFile (path);
    string line;

    if (!datasetFile.is_open()) throw runtime_error("Unable to load dataset");

    while ( getline (datasetFile,line) )
    {

        int idx = 0;
        int vectorIdx = 0;
        while (idx < line.length()){
            if (vectorIdx >= ds.size()) {
                ds.push_back(vector<double>());
            }
            ds.at(idx).push_back(stod(line.substr(idx,line.find(seperator, idx))));
            idx = line.find(seperator, idx)+1;
            ++vectorIdx;
        }


        cout << line << '\n';
    }
    datasetFile.close();
}


