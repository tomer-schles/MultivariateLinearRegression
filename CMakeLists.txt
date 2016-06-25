cmake_minimum_required(VERSION 3.5)
project(MultivariateLinearRegression)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    twoVariableLinearRegression.cpp tess.h)

add_executable(MultivariateLinearRegression ${SOURCE_FILES})