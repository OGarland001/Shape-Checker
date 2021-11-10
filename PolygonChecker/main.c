#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"



int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			triangleSolver();
			break;
		case 2:
			//call a function to perform all actions of case 2
			PerformCaseTwo();
			break;
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
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	if (scanf_s("%d", &shapeChoice) == 0)
	{
		shapeChoice = -1;
		while (getchar() != '\n'); //clean leftover "bad" data from stdin buffer 
	}
	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle in order of ABC: \n");
	for (int i = 0; i < 3; i++)
	{
		bool shouldContinue = true;
		do {
			if (scanf_s("%d", &triangleSides[i]) == 0)
			{
				printf("Invalid input try again\n");
				printf("Please re-enter the side length again\n");
				while (getchar() != '\n');

			}
			else {
				shouldContinue = false;
			}

		} while (shouldContinue == true);

	}
	return triangleSides;
}

void triangleSolver(void) {

	printf_s("Triangle selected.\n");
	int triangleSides[3] = { 0, 0, 0 };
	int* triangleSidesPtr = getTriangleSides(triangleSides);

	char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
	printf_s("%s\n", result);


	if (result != "Not a triangle") {
		AngleSolver(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
	}

}

//This function collects and checks all 4 corners coordinates for the rectangle 
POINT getRectanglePoints(int* rectanglePoint)
{
	//collect the point from the user 
	//(if the user enters more than 2 numbers the program will interpret that the user is entering the upcoming points corrdinates)
	for (int index = XARRAYINDEX; index < SIZEOFCOORDINATEARRAY; index++)
	{
		//check to see if the user entered a number if they did collect it if not end the program
		if (scanf_s("%d", &rectanglePoint[index]) == 0)
		{
			printf("Invalid input\n");
			exit(1);
		}
	}
	//formulate and return the point 
	POINT newPoint = createPoint(rectanglePoint[XARRAYINDEX], rectanglePoint[YARRAYINDEX]);
	return newPoint;
}

//this function calls all the features associated with a rectangle 
void PerformCaseTwo()
{
	//tell the user that the selected the rectangle functionality 
	printf_s("Rectangle selected.\n");

	//collect a corners coordinates
	int firstEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a corner on the rectangle in the form of x y:\n");
	POINT point1 = getRectanglePoints(firstEnteredCoordinates);

	//collect a different corners coordiantes 
	int secondEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
	POINT point2 = getRectanglePoints(secondEnteredCoordinates);

	//collect a different corners coordiantes 
	int thirdEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
	POINT point3 = getRectanglePoints(thirdEnteredCoordinates);

	//collect a different corners coordiantes 
	int fourthEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
	POINT point4 = getRectanglePoints(fourthEnteredCoordinates);

	//check to see if there are any duplicated points
	bool areDuplicatePoints = arePointsSame(point1, point2, point3, point4);

	//If there are no duplicates give the user the output
	if (areDuplicatePoints == false)
	{
		POINT points[4];		// call generateRectangle function
		points[0] = point1;
		points[1] = point2;
		points[2] = point3;
		points[3] = point4;
		LINE* lines = generateRectangle(points);

		//validate rectangle based on points
		bool validRectangle = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);

		int perimeter = findRectanglePerimeter(lines[0], lines[1], lines[2], lines[3]);
		// is it a rectangle? output yes - ouptut area && perimeter 
		if (validRectangle == true)
		{
			int area = findRectangleArea(lines[0], lines[1]);
			printf("The polygon is a rectangle \nThe perimeter is: %d \nThe area is %d", perimeter, area);
		}
		// is it a rectangle? output no - show perimeter 
		else
		{
			printf("The polygon is not a rectangle \nThe perimeter is: %d \n", perimeter);
		}
	}
	else
	{
		printf("You cannot have duplicated points, please try again with 4 unique points\n");
	}
}

