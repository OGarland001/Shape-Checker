#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	//This is following the triangle inequality theorem(to figure out if it is a possible triangle or not)
	if (((side1 + side2) > side3) && ((side3 + side2) > side1) && ((side3 + side1) > side2)) {

	 if (side1 == side2 && side1 == side3) {
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

	}
	else{
		result = "Not a triangle";

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

	//gives user idea of where the angles are from the side lengths they inputted
	printf("Angle A, is directly across from side A\n");
	printf("Angle B, is directly across from side B\n");
	printf("Angle C, is directly across from side C\n");


}





