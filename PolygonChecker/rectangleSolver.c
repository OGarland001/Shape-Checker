#include "rectangleSolver.h"

//validate by receiving slope of side length 1 and side length 2 and checking for perpendicularity
bool setupValidRectanglePoints(POINT point1, POINT point2, POINT point3, POINT point4)
{
	bool valid = true;
	float slope1, slope2, slope3, slope4;
	//Use a helper function to convert points to slopes
	//Hardcode for now, potentially use for loop
	slope1 = findSlope(point1, point2);
	slope2 = findSlope(point2, point3);
	slope3 = findSlope(point3, point4);
	slope4 = findSlope(point4, point1);
	//Two lines which are perpendicular to each other are negative reciprocals, so their product would be -1
	//potentially convert to while/for loop
	if (slope1 * slope2 != -1) {
		valid = false;
	}
	if (slope2 * slope3 != -1) {
		valid = false;
	}
	if (slope3 * slope4 != -1) {
		valid = false;
	}
	if (slope4 * slope1 != -1) {
		valid = false;
	}
	return valid;
}

float findSlope(POINT point1, POINT point2) {
//TODO
}
//function takes the points and ouputs four lines
LINE* generateRectangle(POINT points[])
{
	LINE* lines = malloc(4 * sizeof(LINE));


	return lines;

}

float findLength(LINE line[]) {
//TODO
}
//function takes in lines, uses helper function findLength to get 4 lengths, then returns the sum
float findRectanglePerimeter(LINE line1, LINE line2, LINE line3, LINE line4)
{
	float perimeter, lLen1, lLen2, lLen3, lLen4;

	lLen1 = findLength(line1);
	lLen2 = findLength(line2);
	lLen3 = findLength(line3);
	lLen4 = findLength(line4);

	perimeter = lLen1 + lLen2 + lLen3 + lLen4;
	return perimeter;
}

//Assuming line2 is directly adjacent to line1, these two lines should be height and width
float findRectangleArea(LINE line1, LINE line2)
{
	float area, lLen1, lLen2;

	lLen1 = findLength(line1);
	lLen2 = findLength(line2);

	area = lLen1 * lLen2;
	return area;
}