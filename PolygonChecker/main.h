#pragma once
#include "rectangleSolver.h"

#define SIZEOFCOORDINATEARRAY 2
#define XARRAYINDEX 0
#define YARRAYINDEX 1

//This function prints out the welcome text
void printWelcome();
//This function prints out the selection menu and collect a valid selection 
int printShapeMenu();
//this function collects and checks all 3 side lengths of the triangle 
int* getTriangleSides(int* triangleSides);
//This function collects and checks all 4 corners coordinates for the rectangle 
POINT getRectanglePoints(int*);
//This function calls all the features associated with a rectangle 
void PerformCaseTwo(); 