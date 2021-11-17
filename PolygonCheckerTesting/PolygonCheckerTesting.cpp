#include "pch.h"
#include "CppUnitTest.h"
//#include "..\PolygonChecker\triangleSolver.h"

#include <stdbool.h>
//#include "..\\PolygonChecker\\main.h"
//#include "..\\PolygonChecker\\triangleSolver.h"

//#include "..\PolygonChecker\rectangleSolver.h"

extern "C" char* analyzeTriangle(int, int, int);
extern "C" void AngleSolver(int, int, int);
extern "C" double CosineLawAngleA(int, int, int);
extern "C" double CosineLawAngleB(int, int, int);
extern "C" double CosineLawAngleC(int, int, int);
extern "C" struct POINT { int x, y; };	//extern point struct
extern "C" struct LINE { POINT pointA, pointB; };	//extern line struct
extern "C" bool setupValidRectanglePoints(LINE, LINE, LINE, LINE);
extern "C" float findRectanglePerimeter(LINE, LINE, LINE, LINE);
extern "C" float findRectangleArea(LINE, LINE);

extern "C" LINE* generateRectangle(POINT[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTesting
{
	TEST_CLASS(TypeOfTriangleFunctionality)
	{
	public:

		TEST_METHOD(TypeOfTriangleTest1)
		{
			//proper input, output isosceles
			//analyzeTriangle(60,60,80) 
			char* Result;
			Result = analyzeTriangle(60, 60, 80);
			Assert::AreEqual("Isosceles triangle", Result);

		}
		TEST_METHOD(TypeOfTriangleTest2)
		{
			//proper input, output equailateral triangle
			//analyzeTriangle(60,60,60) 
			char* Result;
			Result = analyzeTriangle(60, 60, 60);
			Assert::AreEqual("Equilateral triangle", Result);

		}
		TEST_METHOD(TypeOfTriangleTest3)
		{
			//improper input, output not triangle
			//analyzeTriangle(0,0,0) 
			char* Result;
			Result = analyzeTriangle(0, 0, 0);
			Assert::AreEqual("Not a triangle", Result);
		}
		TEST_METHOD(TypeOfTriangleTest4)
		{
			//improper input, output not triangle
			//analyzeTriangle(-10,-2,11) 
			char* Result;
			Result = analyzeTriangle(-10, -2, 11);
			Assert::AreEqual("Not a triangle", Result);

		}
		TEST_METHOD(TypeOfTriangleTest5)
		{
			//proper input, output scalene triangle
			//analyzeTriangle(7,12,15) 
			char* Result;
			Result = analyzeTriangle(7, 12, 15);
			Assert::AreEqual("Scalene triangle", Result);

		}

	};
	TEST_CLASS(TriangleInsideAngleFunctionality)
	{
	public:

		TEST_METHOD(InsideAngleATest1)
		{
			//proper Input, output 48.19
			double Result = CosineLawAngleA(60, 60, 80);
			Assert::AreEqual(48.19, Result);
		}
		TEST_METHOD(InsideAngleATest2)
		{

		}
		TEST_METHOD(InsideAngleATest3)
		{

		}
		TEST_METHOD(InsideAngleATest4)
		{

		}
		TEST_METHOD(InsideAngleATest5)
		{

		}
	
	};
	TEST_CLASS(FourPointsFunctionality)
	{
	public:
		TEST_METHOD(setupValidRectanglePoints_1) //validate rectangle for a square
		{
			LINE lines[4];

			lines[0].pointA.x = 1;
			lines[0].pointA.y = 1;
			lines[0].pointB.x = 1;
			lines[0].pointB.y = 2;

			lines[1].pointA.x = 1;
			lines[1].pointA.y = 2;
			lines[1].pointB.x = 2;
			lines[1].pointB.y = 2;

			lines[2].pointA.x = 2;
			lines[2].pointA.y = 2;
			lines[2].pointB.x = 2;
			lines[2].pointB.y = 1;

			lines[3].pointA.x = 2;
			lines[3].pointA.y = 1;
			lines[3].pointB.x = 1;
			lines[3].pointB.y = 1;

			bool valid = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(true, valid);
		}
		TEST_METHOD(setupValidRectanglePoints_2) //validate rectangle for a square with negative values
		{
			LINE lines[4];

			lines[0].pointA.x = -1;
			lines[0].pointA.y = -1;
			lines[0].pointB.x = -1;
			lines[0].pointB.y = -2;

			lines[1].pointA.x = -1;
			lines[1].pointA.y = -2;
			lines[1].pointB.x = -2;
			lines[1].pointB.y = -2;

			lines[2].pointA.x = -2;
			lines[2].pointA.y = -2;
			lines[2].pointB.x = -2;
			lines[2].pointB.y = -1;

			lines[3].pointA.x = -2;
			lines[3].pointA.y = -1;
			lines[3].pointB.x = -1;
			lines[3].pointB.y = -1;

			bool valid = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(true, valid);
		}

		TEST_METHOD(setupValidRectanglePoints_3) //validate rectangle for a parallelogram
		{
			LINE lines[4];

			lines[0].pointA.x = 1;
			lines[0].pointA.y = 1;
			lines[0].pointB.x = 2;
			lines[0].pointB.y = 4;

			lines[1].pointA.x = 2;
			lines[1].pointA.y = 4;
			lines[1].pointB.x = 5;
			lines[1].pointB.y = 1;

			lines[2].pointA.x = 5;
			lines[2].pointA.y = 1;
			lines[2].pointB.x = 6;
			lines[2].pointB.y = 4;

			lines[3].pointA.x = 6;
			lines[3].pointA.y = 4;
			lines[3].pointB.x = 1;
			lines[3].pointB.y = 1;

			bool valid = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(false, valid);
		}

		TEST_METHOD(setupValidRectanglePoints_4) //validate rectangle for a diagonal line
		{
			LINE lines[4];

			lines[0].pointA.x = 1;
			lines[0].pointA.y = 1;
			lines[0].pointB.x = 2;
			lines[0].pointB.y = 2;

			lines[1].pointA.x = 2;
			lines[1].pointA.y = 2;
			lines[1].pointB.x = 3;
			lines[1].pointB.y = 3;

			lines[2].pointA.x = 3;
			lines[2].pointA.y = 3;
			lines[2].pointB.x = 4;
			lines[2].pointB.y = 4;

			lines[3].pointA.x = 4;
			lines[3].pointA.y = 4;
			lines[3].pointB.x = 1;
			lines[3].pointB.y = 1;

			bool valid = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(false, valid);
		}

		TEST_METHOD(setupValidRectanglePoints_5) //validate rectangle for a horizontal line
		{
			LINE lines[4];

			lines[0].pointA.x = 1;
			lines[0].pointA.y = 1;
			lines[0].pointB.x = 2;
			lines[0].pointB.y = 1;

			lines[1].pointA.x = 2;
			lines[1].pointA.y = 1;
			lines[1].pointB.x = 3;
			lines[1].pointB.y = 1;

			lines[2].pointA.x = 3;
			lines[2].pointA.y = 1;
			lines[2].pointB.x = 4;
			lines[2].pointB.y = 1;

			lines[3].pointA.x = 4;
			lines[3].pointA.y = 1;
			lines[3].pointB.x = 1;
			lines[3].pointB.y = 1;

			bool valid = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(false, valid);
		}

		TEST_METHOD(setupValidRectanglePoints_6) //validate rectangle for a vertical line
		{
			LINE lines[4];

			lines[0].pointA.x = 1;
			lines[0].pointA.y = 1;
			lines[0].pointB.x = 1;
			lines[0].pointB.y = 2;

			lines[1].pointA.x = 1;
			lines[1].pointA.y = 2;
			lines[1].pointB.x = 1;
			lines[1].pointB.y = 3;

			lines[2].pointA.x = 1;
			lines[2].pointA.y = 3;
			lines[2].pointB.x = 1;
			lines[2].pointB.y = 4;

			lines[3].pointA.x = 1;
			lines[3].pointA.y = 4;
			lines[3].pointB.x = 1;
			lines[3].pointB.y = 1;

			bool valid = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(false, valid);
		}
		TEST_METHOD(setupValidRectanglePoints_7) //validate rectangle for a slanted rectangle
		{
			LINE lines[4];

			lines[0].pointA.x = 3;
			lines[0].pointA.y = 3;
			lines[0].pointB.x = 4;
			lines[0].pointB.y = 1;

			lines[1].pointA.x = 4;
			lines[1].pointA.y = 1;
			lines[1].pointB.x = 1;
			lines[1].pointB.y = -1;

			lines[2].pointA.x = 1;
			lines[2].pointA.y = -1;
			lines[2].pointB.x = 0;
			lines[2].pointB.y = 1;

			lines[3].pointA.x = 0;
			lines[3].pointA.y = 1;
			lines[3].pointB.x = 3;
			lines[3].pointB.y = 3;

			bool valid = setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(true, valid);
		}
		TEST_METHOD(findRectanglePerimeter1) //return perimeter for a 2x2 square
		{
			LINE lines[4];

			lines[0].pointA.x = 1;
			lines[0].pointA.y = 1;
			lines[0].pointB.x = 1;
			lines[0].pointB.y = 3;

			lines[1].pointA.x = 1;
			lines[1].pointA.y = 3;
			lines[1].pointB.x = 3;
			lines[1].pointB.y = 3;

			lines[2].pointA.x = 3;
			lines[2].pointA.y = 3;
			lines[2].pointB.x = 3;
			lines[2].pointB.y = 1;

			lines[3].pointA.x = 3;
			lines[3].pointA.y = 1;
			lines[3].pointB.x = 1;
			lines[3].pointB.y = 1;

			float perimeter = findRectanglePerimeter(lines[0], lines[1], lines[2], lines[3]);
			Assert::AreEqual(float(8), perimeter);
		}
		TEST_METHOD(findRectangleArea1) //return area for a 2x2 square
		{
			LINE lines[2];

			lines[0].pointA.x = 1;
			lines[0].pointA.y = 1;
			lines[0].pointB.x = 1;
			lines[0].pointB.y = 3;

			lines[1].pointA.x = 1;
			lines[1].pointA.y = 3;
			lines[1].pointB.x = 3;
			lines[1].pointB.y = 3;


			float area = findRectangleArea(lines[0], lines[1]);
			Assert::AreEqual(float(4), area);
		}


		TEST_METHOD(generateRectangle_Returnlines)	//sample generateRectangle test
		{
			POINT points[4];
			POINT p;
			p.x = 1;
			p.y = 2;
			points[0] = p;
			p.x = 4;
			p.y = 6;
			points[1] = p;
			p.x = 4;
			p.y = 2;
			points[2] = p;
			p.x = 1;
			p.y = 6;
			points[3] = p;

			LINE* Lines = generateRectangle(points);
			Assert::AreEqual(1, Lines[0].pointA.x);
			Assert::AreEqual(2, Lines[0].pointA.y);
			Assert::AreEqual(4, Lines[0].pointB.x);
			Assert::AreEqual(2, Lines[0].pointB.y);
			Assert::AreEqual(4, Lines[1].pointA.x);
			Assert::AreEqual(2, Lines[1].pointA.y);
			Assert::AreEqual(4, Lines[1].pointB.x);
			Assert::AreEqual(6, Lines[1].pointB.y);
			Assert::AreEqual(4, Lines[2].pointA.x);
			Assert::AreEqual(6, Lines[2].pointA.y);
			Assert::AreEqual(1, Lines[2].pointB.x);
			Assert::AreEqual(6, Lines[2].pointB.y);
			Assert::AreEqual(1, Lines[3].pointA.x);
			Assert::AreEqual(6, Lines[3].pointA.y);
			Assert::AreEqual(1, Lines[3].pointB.x);
			Assert::AreEqual(2, Lines[3].pointB.y);
		}
	};
}
