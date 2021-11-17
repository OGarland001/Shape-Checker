#include "triangleSolver.h"
#include <math.h>
#include <stdio.h>

double CosineLawAngleA(double sideA, double sideB, double sideC) {
	double radA, Denominator, Numerator, Result;
	// this function finds the angle A using the rearranged formula of CosineLaw
	Numerator = (pow(sideB, 2) + pow(sideC, 2) - pow(sideA, 2));
	Denominator = (2 * sideB * sideC);
	radA = acos(Numerator / Denominator);
	Result = radA * (RadToDegAngle / PI);
	//added to round the result of the calculation for testing
	Result = round(Result * 100) / 100;
	return Result;

}
double CosineLawAngleB(double sideA, double sideB, double sideC) {
	double radB, Denominator, Numerator, Result;
	// this function finds the angle B using the rearranged formula of CosineLaw
	Numerator = (pow(sideA, 2) + pow(sideC, 2) - pow(sideB, 2));
	Denominator = (2 * sideA * sideC);
	radB = acos(Numerator / Denominator);
	Result = radB * (RadToDegAngle / PI);
	//added to round the result of the calculation for testing
	Result = round(Result * 100) / 100;
	return Result;

}
double CosineLawAngleC(double sideA, double sideB, double sideC) {
	double radC, Denominator, Numerator, Result;
	// this function finds the angle C using the rearranged formula of CosineLaw
	Numerator = (pow(sideB, 2) + pow(sideA, 2) - pow(sideC, 2));
	Denominator = (2 * sideB * sideA);
	radC = acos(Numerator / Denominator);
	Result = radC * (RadToDegAngle / PI);
	//added to round the result of the calculation for testing
	Result = round(Result * 100) / 100;
	return Result;


}

