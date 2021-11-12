#pragma once
#include <stdbool.h>
//analyze triangle to output which type of triangle
char* analyzeTriangle(int side1, int side2, int side3);
void AngleSolver(int, int, int);
//three different functions for the 3 different formulas to find the angles from the side lengths
double CosineLawAngleA(double, double, double);
double CosineLawAngleB(double, double, double);
double CosineLawAngleC(double, double, double);
//call triangle solver to solve triangle and run all the code related to the triangle solver code
void triangleSolver(void);
#define PI 3.14159
#define RadToDegAngle 180