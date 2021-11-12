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

bool setupValidRectanglePoints(LINE, LINE, LINE, LINE);
float findRectanglePerimeter(LINE, LINE, LINE, LINE);
float findRectangleArea(LINE, LINE);
float findSlope(POINT, POINT);
float findLength(LINE line);
LINE* generateRectangle(POINT points[]);
//This function takes in the x and y values for a point and generate a new "point"
POINT createPoint(int, int);
//This function takes in the 4 points and checks that they are not the same (meaning there is a change that the inputs could be a rectangle)
bool arePointsSame(POINT, POINT, POINT, POINT);

