#include "rectangleSolver.h"

//validate by receiving slope of side length 1 and side length 2 and checking for perpendicularity
bool setupValidRectanglePoints(int point1, int point2, int point3, int point4)
{
	bool valid = true;
	float slope1, slope2, slope3, slope4;
	//Use a helper function to convert points to slopes
	// 
	//Two lines which are perpendicular to each other are negative reciprocals, so their product would be -1
	//possibly convert to while/for loop
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

//function takes the points and ouputs four lines
LINE* generateRectangle(POINT points[])
{
	LINE* lines = malloc(4 * sizeof(LINE));

	int minx, maxy, maxx, miny;
	minx = points[0].x;
	maxy = points[0].y;
	maxx = points[0].x;
	miny = points[0].y;

	for (int i = 1; i < 4; i++) {
		if (minx > points[i].x) {
			minx = points[i].x;
		}
		if (maxy < points[i].y) {
			maxy = points[i].y;
		}
		if (maxx < points[i].x) {
			maxx = points[i].x;
		}
		if (miny > points[i].y) {
			miny = points[i].y;
		}
	}


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


int findRectanglePerimeter(int line1, int line2, int line3, int line4)
{
	int perimeter;
	perimeter = line1 + line2 + line3 + line4;
	return perimeter;
}

//Assuming line2 is directly adjacent to line1, these two lines should be height and width
int findRectangleArea(int line1, int line2)
{
	int area;
	area = line1 * line2;
	return area;
}