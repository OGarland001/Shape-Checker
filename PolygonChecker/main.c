#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

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
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			
			int userinput;
			//prompt user if they would like to know the inside angles of the triangle
			printf_s("Would you like to know the inside angles of the triangle? yes(1) or no(0)?");
			scanf_s("%d", &userinput);
			//if selected yes then call the angle solver function to show the angles
			if (userinput == 1) {
				AngleSolver(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}

			break;
		case 2:
			//tell the user that the selected the rectangle functionality 
			printf_s("Rectangle selected.\n");

			//collect a corners coordinates
			int firstEnteredCoordinates[2] = { 0, 0 };
			//tell the user to enter a point 
			printf_s("Please enter the coordinates of a corner on the rectangle in the form of x y:\n");
			int* entered1stRectanglePoints = getRectanglePoints(firstEnteredCoordinates);

			//collect a different corners coordiantes 
			int secondEnteredCoordinates[2] = { 0, 0 };
			//tell the user to enter a point 
			printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
			int* entered2ndRectanglePoints = getRectanglePoints(secondEnteredCoordinates);

			//collect a different corners coordiantes 
			int thirdEnteredCoordinates[2] = { 0, 0 };
			//tell the user to enter a point 
			printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
			int* entered3rdRectanglePoints = getRectanglePoints(thirdEnteredCoordinates);

			//collect a different corners coordiantes 
			int fourthEnteredCoordinates[2] = { 0, 0 };
			//tell the user to enter a point 
			printf_s("Please enter the coordinates of a different corner on the rectangle in the form of x y:\n");
			int* entered4thRectanglePoints = getRectanglePoints(fourthEnteredCoordinates);

			//are inputs duplicats
			// rearrange points 
			// generate 4 lines 
			// is it a rectangle? output no - show perimeter || yes - ouptut area && perimeter  
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

//This function collects and checks all 4 corners coordinates for the rectangle 
int* getRectanglePoints(int* rectanglePoint)
{
	//collect the point from the user 
	//(if the user enters more than 2 numbers the program will interpret that the user is entering the upcoming points corrdinates)
	for (int index = 0; index < 2; index++)
	{
		//check to see if the user entered a number if they did collect it if not end the program
		if (scanf_s("%d", &rectanglePoint[index]) == 0)
		{
			printf("Invalid input");
			exit(1); //Brodin:In the future I will change this so it will just return back to the menu loop rather than exiting the program 
		}
	}
	return rectanglePoint;
}