#include "rectangleSolver.h"

//validate by receiving slope of side length 1 and side length 2 and checking for perpendicularity
bool setupValidRectanglePoints(POINT point1, POINT point2, POINT point3, POINT point4)
{
	bool valid = true;
	float slope1, slope2, slope3, slope4;

	//Use a helper function to convert points to slopes

	slope1 = findSlope(point1, point2);
	slope2 = findSlope(point2, point3);
	slope3 = findSlope(point3, point4);
	slope4 = findSlope(point4, point1);
	//Two lines which are perpendicular to each other are negative reciprocals, so their product would be -1

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

//function takes in two points, returns the slope
float findSlope(POINT point1, POINT point2) {
	int x1, x2, y1, y2;

	x1 = point1.x;
	y1 = point1.y;
	x2 = point2.x;
	y2 = point2.y;

	float slope = (y2 - y1) / (x2 - x1);

	return slope;

}
//function takes the points and ouputs four lines
LINE* generateRectangle(POINT points[])
{
	LINE* lines = malloc(4 * sizeof(LINE));

	//get center of 4 points
	POINT pointcenter;
	pointcenter.x = 0;
	pointcenter.y = 0;
	for (int i = 0; i < 4; i++) {
		pointcenter.x += points[i].x;
		pointcenter.y += points[i].y;
	}
	pointcenter.x /= 4;
	pointcenter.y /= 4;

	//get angles
	double angles[4];
	for (int i = 0; i < 4; i++) {
		angles[i] = atan2(points[i].y - pointcenter.y, points[i].x - pointcenter.x);
	}

	//sort points
	int minIndex;
	for (int i = 0; i < 3; i++) {
		minIndex = i;
		for (int j = i + 1; j < 4; j++) {
			if (angles[j] < angles[minIndex]) {		//comparing elements at index i and j
				minIndex = j;
			}
		}
		double temp = angles[minIndex];		//swapping the angle array
		angles[minIndex] = angles[i];
		angles[i] = temp;

		POINT p = points[minIndex];		//swapping corresponding point array
		points[minIndex] = points[i];
		points[i] = p;
	}

	//generate 4 lines to form shape
	for (int i = 0; i < 4; i++) {
		LINE line;
		line.pointA = points[i];

		if (i == 3) {
			line.pointB = points[0];
		}
		else {
			line.pointB = points[i + 1];
		}
		lines[i] = line;
	}
	return lines;
}

//function takes in a line, returning the line length
float findLength(LINE line) {
	POINT point1, point2;
	int x1, x2, y1, y2; //
	int length;
	x1 = line.pointA.x;
	y1 = line.pointA.y;
	x2 = line.pointB.x;
	y2 = line.pointB.y;

	length = abs(sqrt((x2 - x1) ^ 2 + (y2 - y1) ^ 2));

	return length;

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

//This function takes in the x and y values for a point and generate a new "point"
POINT createPoint(int xValue, int yValue)
{
	POINT tempNewPoint;
	//take the input x and y values and store them in the new point
	tempNewPoint.x = xValue;
	tempNewPoint.y = yValue;
	//store undefined as the points location as we do not know the points location right away
	strncpy_s("undefined", MAXNAMELEN, tempNewPoint.pointName, MAXNAMELEN);
	//return a newly created point 
	return tempNewPoint;
}

