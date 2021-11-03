#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool setupValidRectanglePoints();
float findRectanglePerimeter();
float findRectangleArea();
float findSlope();
float findLength(LINE line);
LINE* generateRectangle(POINT points[]);

typedef struct Point {		//structure for points
	int x, y;
}POINT;

typedef struct Line {		//structure for lines
	POINT pointA;
	POINT pointB;
}LINE;
int findRectanglePerimeter();
int findRectangleArea();
void generateRectangle();
