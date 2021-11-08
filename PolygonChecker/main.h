#pragma once
#include "rectangleSolver.h"

#define SIZEOFCOORDINATEARRAY 2
#define XARRAYINDEX 0
#define YARRAYINDEX 1

void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
//This function collects and checks all 4 corners coordinates for the rectangle 
POINT getRectanglePoints(int*);