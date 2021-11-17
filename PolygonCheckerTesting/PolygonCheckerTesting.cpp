#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>
//#include "..\PolygonChecker\rectangleSolver.h"

extern "C" char* analyzeTriangle(int, int, int);
extern "C" void AngleSolver(int, int, int);
extern "C" double CosineLawAngleA(int, int, int);
extern "C" double CosineLawAngleB(int, int, int);
extern "C" double CosineLawAngleC(int, int, int);
extern "C" struct POINT { int x, y; };	//extern point struct
extern "C" struct LINE { POINT pointA, pointB; };	//extern line struct
extern "C" LINE* generateRectangle(POINT[]);
extern "C" POINT createPoint(int, int);
extern "C" bool arePointsSame(POINT, POINT, POINT, POINT);


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

		TEST_METHOD(PointCreationFunctionality_1923535and1838045932INPUTED_Pointxis1923535Pointyis1838045932OUTPUTED)
		{
			//This is testing the point creation functionality from inputed coordiantes where both coordinates are very large

			//Test case example inputs from "user"
			int xCoordinate = 1923535;
			int yCoordinate = 1838045932;

			//Call the function given the "user" input
			POINT returnedPoint = createPoint(xCoordinate, yCoordinate);

			//check to see if a "point" was properly formed 
			Assert::AreEqual(xCoordinate, returnedPoint.x);
			Assert::AreEqual(yCoordinate, returnedPoint.y);
		}
		TEST_METHOD(PointCreationFunctionality_0and0INPUTED_Pointxis0Pointyis0OUTPUTED)
		{
			//This is testing the point creation functionality from inputed coordiantes where both coordinates are zero

			//Test case example inputs from "user"
			int xCoordinate = 0;
			int yCoordinate = 0;

			//Call the function given the "user" input
			POINT returnedPoint = createPoint(xCoordinate, yCoordinate);

			//check to see if a "point" was properly formed 
			Assert::AreEqual(xCoordinate, returnedPoint.x);
			Assert::AreEqual(yCoordinate, returnedPoint.y);
		}
		TEST_METHOD(PointCreationFunctionality_neg212733andneg234839471INPUTED_Pointxisneg212733Pointyisneg234839471OUTPUTED)
		{
			//This is testing the point creation functionality from inputed coordiantes where both coordinates are very small

			//Test case example inputs from "user"
			int xCoordinate = -212733;
			int yCoordinate = -234839471;

			//Call the function given the "user" input
			POINT returnedPoint = createPoint(xCoordinate, yCoordinate);

			//check to see if a "point" was properly formed 
			Assert::AreEqual(xCoordinate, returnedPoint.x);
			Assert::AreEqual(yCoordinate, returnedPoint.y);
		}

		TEST_METHOD(DuplicatePointsFunctionality_NoDuplicatesINPUTED_falseOUTPUTED)
		{
			//This is testing the duplicate point check where no duplicates are entered
			
			//Test case example points
			POINT one, two, three, four;
			one.x = 1;
			one.y = 2;
			two.x = 3;
			two.y = 4;
			three.x = 5;
			three.y = 6;
			four.x = 7;
			four.y = 8;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsFalse(functionOutput);
		}
		TEST_METHOD(DuplicatePointsFunctionality_AllDuplicatesINPUTED_trueOUTPUTED)
		{
			//This is testing the duplicate point check where all points are duplicates

			//Test case example points
			POINT one, two, three, four;
			one.x = 2;
			one.y = 2;
			two.x = 2;
			two.y = 2;
			three.x = 2;
			three.y = 2;
			four.x = 2;
			four.y = 2;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsTrue(functionOutput);
		}
		TEST_METHOD(DuplicatePointsFunctionality_Point1and2sameINPUTED_trueOUTPUTED)
		{
			//This is testing the duplicate point check where points 1 and 2 are duplicates

			//Test case example points
			POINT one, two, three, four;
			one.x = 1;
			one.y = 2;
			two.x = 1;
			two.y = 2;
			three.x = 5;
			three.y = 6;
			four.x = 7;
			four.y = 8;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsTrue(functionOutput);
		}
		TEST_METHOD(DuplicatePointsFunctionality_Point1and3sameINPUTED_trueOUTPUTED)
		{
			//This is testing the duplicate point check where points 1 and 3 are duplicates

			//Test case example points
			POINT one, two, three, four;
			one.x = 1;
			one.y = 2;
			two.x = 3;
			two.y = 4;
			three.x = 1;
			three.y = 2;
			four.x = 7;
			four.y = 8;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsTrue(functionOutput);
		}	
		TEST_METHOD(DuplicatePointsFunctionality_Point1and4sameINPUTED_trueOUTPUTED)
		{
			//This is testing the duplicate point check where points 1 and 4 are duplicates

			//Test case example points
			POINT one, two, three, four;
			one.x = 1;
			one.y = 2;
			two.x = 3;
			two.y = 4;
			three.x = 5;
			three.y = 6;
			four.x = 1;
			four.y = 2;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsTrue(functionOutput);
		}	
		TEST_METHOD(DuplicatePointsFunctionality_Point2and3sameINPUTED_trueOUTPUTED)
		{
			//This is testing the duplicate point check where points 2 and 3 are duplicates

			//Test case example points
			POINT one, two, three, four;
			one.x = 1;
			one.y = 2;
			two.x = 3;
			two.y = 4;
			three.x = 3;
			three.y = 4;
			four.x = 7;
			four.y = 8;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsTrue(functionOutput);
		}	
		TEST_METHOD(DuplicatePointsFunctionality_Point2and4sameINPUTED_trueOUTPUTED)
		{
			//This is testing the duplicate point check where points 2 and 4 are duplicates

			//Test case example points
			POINT one, two, three, four;
			one.x = 1;
			one.y = 2;
			two.x = 3;
			two.y = 4;
			three.x = 5;
			three.y = 6;
			four.x = 3;
			four.y = 4;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsTrue(functionOutput);
		}	
		TEST_METHOD(DuplicatePointsFunctionality_Point3and4sameINPUTED_trueOUTPUTED)
		{
			//This is testing the duplicate point check where points 3 and 4 are duplicates

			//Test case example points
			POINT one, two, three, four;
			one.x = 1;
			one.y = 2;
			two.x = 3;
			two.y = 4;
			three.x = 5;
			three.y = 6;
			four.x = 5;
			four.y = 6;

			//Call the function given the example points
			bool functionOutput = arePointsSame(one, two, three, four);

			//Check to see if the function outputed correct answer 
			Assert::IsTrue(functionOutput);
		}	
	};
}
