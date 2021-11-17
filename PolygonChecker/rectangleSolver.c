#include "rectangleSolver.h"

//validate by receiving slope of side length 1 and side length 2 and checking for perpendicularity
bool setupValidRectanglePoints(LINE line1, LINE line2, LINE line3, LINE line4)
{
	bool valid = true;
	float slope1, slope2, slope3, slope4;

	//Use a helper function to convert points to slopes

	slope1 = findSlope(line1.pointA, line1.pointB);
	slope2 = findSlope(line2.pointA, line2.pointB);
	slope3 = findSlope(line3.pointA, line3.pointB);
	slope4 = findSlope(line4.pointA, line4.pointB);

	//Rectangle is a horizontal or vertical line
	if ((line1.pointA.x == line2.pointA.x == line3.pointA.x == line4.pointA.x ||
		line1.pointA.y == line2.pointA.y == line3.pointA.y == line4.pointA.y) && slope1 == slope2 == slope3 == slope4) {
		valid = false;
	}
	else {
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

			//Special case for rectangle built with horizontal/vertical lines (slope 0 and x2-x1 = 0 (undefined))
		if (slope1 == 0 && (line2.pointB.x - line2.pointA.x == 0 && line2.pointB.y != line2.pointA.y) && //slope1 & slope3 horizontal, slope2 and slope4 vertical
			slope3 == 0 && (line4.pointB.x - line4.pointA.x == 0 && line4.pointB.y != line4.pointA.y)) {
			valid = true;
		}

		if ((line1.pointB.x - line1.pointA.x == 0 && line1.pointA.y != line1.pointB.y) && slope2 == 0 //slope2 & slope4 horizontal, slope1 and slope3 vertical
			&& (line3.pointB.x - line3.pointA.x == 0 && line3.pointA.y != line3.pointB.y) && slope4 == 0) {
			valid = true;
			}
		}
	return valid;
}

//function takes in two points, returns the slope
float findSlope(POINT point1, POINT point2) {
	float x1, x2, y1, y2;

	float slope;
	//use float versions of points in order to find slope as a float

	x1 = (float)point1.x;
	y1 = (float)point1.y;
	x2 = (float)point2.x;
	y2 = (float)point2.y;

	//if x2-x1, slope is undefined (will use 0 instead)
	if ((x2 - x1) == 0) {
		slope = 0; //!!!setting undefined to 0 will have incorrect inputs if polygon is a line!!!
	}
	else {
		slope = (y2 - y1) / (x2 - x1);
	}
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
		angles[i] = atan2(points[i].y - pointcenter.y, points[i].x - pointcenter.x); //use of atan2 to calculate the angles from each point to the center
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
	int x1, x2, y1, y2, rise, run;
	int length;
	x1 = line.pointA.x;
	y1 = line.pointA.y;
	x2 = line.pointB.x;
	y2 = line.pointB.y;
	rise = y2 - y1;
	run = x2 - x1;

	length = sqrt(pow(run, 2) + pow(rise, 2));

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

	//return a newly created point 
	return tempNewPoint;
}

//This function takes in the 4 points and checks that they are not the same (meaning there is a change that the inputs could be a rectangle)
bool arePointsSame(POINT one, POINT two, POINT three, POINT four)
{
	//are any of the x y pairs the same?
	if (one.x == two.x && one.y == two.y ||
		one.x == three.x && one.y == three.y ||
		one.x == four.x && one.y == four.y ||
		two.x == three.x && two.y == three.y ||
		two.x == four.x && two.y == four.y ||
		three.x == four.x && three.y == four.y)
	{
		//one or more of the points are the same so we return true
		return true;
	}

	//none of the points are the same so we return false 
	return false;
}

