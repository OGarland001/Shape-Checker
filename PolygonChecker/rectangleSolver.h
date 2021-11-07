#pragma once

#define MAXNAMELEN 35

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h.>

bool setupValidRectanglePoints();
float findRectanglePerimeter();
float findRectangleArea();
float findSlope();
float findLength(LINE line);
LINE* generateRectangle(POINT points[]);
void isValidRectangle();

typedef struct Point {		//structure for points
	char pointName[MAXNAMELEN];
	int x;
	int y;
}POINT;

typedef struct Line {		//structure for lines
	POINT pointA;
	POINT pointB;
}LINE;

//Discuss adding a rectangle struct to avoid passing 4 points in function parameters 

