#pragma once

#define MAXNAMELEN 35

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h.>
#include <string.h>


typedef struct Point {		//structure for points
	char pointName[MAXNAMELEN];
	int x, y;
}POINT;

typedef struct Line {		//structure for lines
	POINT pointA;
	POINT pointB;
}LINE;

//Validates rectangle points, returning a valid rectangle
bool setupValidRectanglePoints(LINE, LINE, LINE, LINE);
//This function outputs the perimeter of a polygon given 4 lines
float findRectanglePerimeter(LINE, LINE, LINE, LINE);
//This function outputs the area of a rectangle given width and height
float findRectangleArea(LINE, LINE);
//This function finds the slope given two points (undefined slopes are defined as 0)
float findSlope(POINT, POINT);
//This function calculates the length of a line
float findLength(LINE line);
//This function rearranges the points then forms 4 lines to generate a rectangle (no lines are crossed)
LINE* generateRectangle(POINT[]);
//This function takes in the x and y values for a point and generate a new "point"
POINT createPoint(int, int);
//This function takes in the 4 points and checks that they are not the same (meaning there is a change that the inputs could be a rectangle)
bool arePointsSame(POINT, POINT, POINT, POINT);

