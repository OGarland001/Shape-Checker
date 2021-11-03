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
	double angleA, angleB, angleC;
	int sqSideA, sqSideB, sqSideC;
	// A = cos-1( (b^2 + c^2 - a^2)/2bc )  Formula to find angleA
	// B = cos-1( (c^2 + a^2 - b^2)/2ca )  Formula to find angleB
	// C = cos-1( (a^2 + b^2 - c^2)/2ab )  Formula to find angleC
	sqSideA = sideA * sideA;
	sqSideB = sideB * sideB;
	sqSideC = sideC * sideC;

	angleA = acos((sqSideB + sqSideC - sqSideA) / (2 * sideB * sideC));
	angleB = acos((sqSideC + sqSideA - sqSideB) / (2 * sideC * sideA));
	angleC = acos((sqSideA + sqSideB - sqSideC) / (2 * sideA * sideB));

	printf("Angle A: %.2f\n", angleA);
	printf("Angle B: %.2f\n", angleB);
	printf("Angle C: %.2f\n", angleC);

}

