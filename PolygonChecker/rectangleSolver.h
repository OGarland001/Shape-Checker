#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool setupValidRectanglePoints();
int findRectanglePerimeter();
int findRectangleArea();
LINE* generateRectangle(POINT points[]);

typedef struct Point {		//structure for points
	int x, y;
}POINT;

typedef struct Line {		//structure for lines
	POINT pointA;
	POINT pointB;
}LINE;