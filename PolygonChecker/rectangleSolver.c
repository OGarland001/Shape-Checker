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

//function takes in a line, returning the line length
float findLength(LINE line) {
	POINT point1, point2;
	int x1, x2, y1, y2; //assuming x2 > x1, y2 > y1
	int length;
	x1 = line.pointA.x;
	y1 = line.pointA.y;
	x2 = line.pointB.x;
	y2 = line.pointB.y;


	length = sqrt((x2 - x1) ^ 2 + (y2 - y1) ^ 2);

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

//maybe Brodin Car and Eric work on this function together? - On Monday
void isValidRectangle()//paramter of rectangle struct? -see not in rectangleSolver.h for disucssion on this struct
{
	// 1. check if lines cross (only continue through function if lines dont cross)
	// 2. check slopes (only continue through function if valid slopes)
	// 3. assign name/location of each point on the rectangle 
	// 4. call car's function to setup the lines (cars function will call erics area and perimeter functions)
	//This order is just a suggestion we can change what steps need to occur later 
	
	//call setupValidRectanglePoints(POINT point1, POINT point2, POINT point3, POINT point4)
	//check if function return is false, if it is output not a rectangle 
	//If function return is true continue:

	//call a function (needs to be created) that will set a point to be the origin and then determine how
	//the next 3 points are layed out in relation to that point (also will determine if the lines will cross)
	//this function should have a return type of bool and will finish filling the point structs with proper location names 
	//(struct is in rectangleSolver.h) and the function will return false if the lines do cross (again tell the user that a rectangle cannot be created)

	//call Car's function to generate the lines (either pass each point or consider creating a rectangle struct)
}
