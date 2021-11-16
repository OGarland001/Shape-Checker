#include "pch.h"
#include "CppUnitTest.h"
<<<<<<< HEAD
#include <stdbool.h>
#include "..\\PolygonChecker\\main.h"
#include "..\\PolygonChecker\\triangleSolver.h"
#include "..\\PolygonChecker\\rectangleSolver.h"

=======
//#include "..\PolygonChecker\rectangleSolver.h"

extern "C" char* analyzeTriangle(int, int, int);
extern "C" void AngleSolver(int, int, int);
extern "C" double CosineLawAngleA(int, int, int);
extern "C" double CosineLawAngleB(int, int, int);
extern "C" double CosineLawAngleC(int, int, int);
extern "C" struct POINT { int x, y; };	//extern point struct
extern "C" struct LINE { POINT pointA, pointB; };	//extern line struct
extern "C" bool setupValidRectanglePoints(LINE, LINE, LINE, LINE);
extern "C" LINE* generateRectangle(POINT[]);
>>>>>>> 1318d75b95fcf5780d233d5796aab873f838ea05

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTesting
{
	TEST_CLASS(TypeOfTriangleFunctionality)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		
		}
	};
	TEST_CLASS(TriangleInsideAngleFunctionality)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
	TEST_CLASS(FourPointsFunctionality)
	{
	public:
		TEST_METHOD(setupValidRectanglePoints_SquareCheck) //validate rectangle for a square
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
