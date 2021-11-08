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


