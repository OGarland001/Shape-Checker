#pragma once

#define MAXNAMELEN 35

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h.>



typedef struct Point {		//structure for points
	char pointName[MAXNAMELEN];
	int x;
	int y;
	int pointcenter;
}POINT;

typedef struct Line {		//structure for lines
	POINT pointA;
	POINT pointB;
}LINE;

bool setupValidRectanglePoints(POINT, POINT, POINT, POINT);
float findRectanglePerimeter(LINE, LINE, LINE, LINE);
float findRectangleArea(LINE, LINE);
float findSlope(POINT, POINT);
float findLength(LINE line);
LINE* generateRectangle(POINT points[]);
