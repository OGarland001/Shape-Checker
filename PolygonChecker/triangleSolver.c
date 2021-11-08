#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

void AngleSolver(int sideA, int sideB, int sideC) {
	double RadianA, RadianB, RadianC, RadianAD;
	double angleA, angleB, angleC;


	angleA = CosineLawAngleA(sideA, sideB, sideC);
	angleB = CosineLawAngleB(sideA, sideB, sideC);
	angleC = CosineLawAngleC(sideA, sideB, sideC);

	//prints the angles to the user
	printf("Angle A: %.2f\n", angleA);
	printf("Angle B: %.2f\n", angleB);
	printf("Angle C: %.2f\n", angleC);

}

