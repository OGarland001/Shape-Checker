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
			//call a function to perform all actions of case 1
			triangleSolver();
			break;
		case 2:
			//call a function to perform all actions of case 2
			PerformCaseTwo();
			break;
		case 0:
			//the users wants the quit so dont loop anymore 
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

//This function prints out the welcome text
void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

//This function prints out the selection menu and collect a valid selection 
int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	//collect the users selection and check that it is valid
	printf_s("Enter number: ");
	if (scanf_s("%d", &shapeChoice) == 0)
	{
		shapeChoice = -1;
		while (getchar() != '\n'); //clean leftover "bad" data from stdin buffer 
	}
	return shapeChoice;
}

//this function collects and checks all 3 side lengths of the triangle 
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

//this function calls all the features associated with a triangle 
void triangleSolver(void) {

	//gets sides from user
	printf_s("Triangle selected.\n");
	int triangleSides[3] = { 0, 0, 0 };
	int* triangleSidesPtr = getTriangleSides(triangleSides);

	//analyzeTriangle and output the type
	char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
	printf_s("%s\n", result);

	//calculates only triangles that have been given a triangle type
	if (result != "Not a triangle") {
		AngleSolver(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
	}

}

//This function collects and checks all 4 corners coordinates for the rectangle 
POINT getRectanglePoints()
{
	int enteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//collect the point from the user 
	//(if the user enters more than 2 numbers the program will interpret that the user is entering the upcoming points corrdinates)
	for (int index = XARRAYINDEX; index < SIZEOFCOORDINATEARRAY; index++)
	{
		bool shouldContinue = true;
		do
		{
			//check to see if the user entered a number if they did collect it if not collect the point again
			if (scanf_s("%d", &enteredCoordinates[index]) == 0)
			{
				printf("Invalid input try again\n");
				printf_s("Please re-enter the coordinates of the corner on the rectangle in the form of x y:\n");
				while (getchar() != '\n'); //clean leftover "bad" data from stdin buffer 
			}
			//the input is not bad so we can continue 
			else
			{
				shouldContinue = false;
			}
		} while (shouldContinue == true);
		
	}
	//formulate and return the point 
	POINT newPoint = createPoint(enteredCoordinates[XARRAYINDEX], enteredCoordinates[YARRAYINDEX]);
	return newPoint;
}

//this function calls all the features associated with a rectangle 
void PerformCaseTwo()
{
	//tell the user that the selected the rectangle functionality 
	printf_s("Rectangle selected.\n");

	//collect a corners coordinates
	//int firstEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a corner on the rectangle in the form of x y:\n");
	POINT point1 = getRectanglePoints();

	//collect a different corners coordiantes 
	//int secondEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
	POINT point2 = getRectanglePoints();

	//collect a different corners coordiantes 
	//int thirdEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
	POINT point3 = getRectanglePoints();

	//collect a different corners coordiantes 
	//int fourthEnteredCoordinates[SIZEOFCOORDINATEARRAY] = { 0, 0 };
	//tell the user to enter a point 
	printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
	POINT point4 = getRectanglePoints();

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
			float slope1, slope2, slope3, slope4;
			slope1 = findSlope(lines[0].pointA, lines[0].pointB);
			slope2 = findSlope(lines[1].pointA, lines[1].pointB);
			slope3 = findSlope(lines[2].pointA, lines[2].pointB);
			slope4 = findSlope(lines[3].pointA, lines[3].pointB);
			if (slope1 == slope2 == slope3 == slope4 ) {
				printf("The polygon is a line, a line does not have a perimeter");
			}
			else {
				printf("The polygon is not a rectangle \nThe perimeter is: %d \n", perimeter);
			}
		}
	}
	//there are duplicated points so tell the user that they cannot have duplicate points 
	else
	{
		printf("You cannot have duplicated points, please try again with 4 unique points\n");
	}
}

