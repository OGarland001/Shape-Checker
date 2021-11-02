#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			//Do this instead or new case? -- Owen
			//int userinput;

			//printf_s("Would you like to know the inside angles of the triangle? yes(1) or no(0)?");
			//scanf_s("%d", &userinput);
			//if (userinput == 1) {
			//	AngleSolver(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			//}

			break;
		case 2:
	/*		printf_s("Angles of a Triangle selected.");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			AngleSolver(triangleSidesPtr);*/

		case 3:

		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Angles of a Triangle");
	printf_s("3. Rectangle");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: \n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d. ", i + 1);
		scanf_s("%d\n", &triangleSides[i]);
	}
	return triangleSides;
}

int* getRectanglePoints(int* rectanglePoints)
{

}