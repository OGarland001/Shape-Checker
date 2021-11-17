#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include <stdbool.h>


extern "C" char* analyzeTriangle(int, int, int);
extern "C" void AngleSolver(int, int, int);
<<<<<<< HEAD
extern "C" double CosineLawAngleA(double, double, double);
extern "C" double CosineLawAngleB(double, double, double);
extern "C" double CosineLawAngleC(double, double, double);
=======
extern "C" double CosineLawAngleA(int, int, int);
extern "C" double CosineLawAngleB(int, int, int);
extern "C" double CosineLawAngleC(int, int, int);
>>>>>>> 06adc0930ba44646799e810dea7ce78c540b6209
extern "C" struct POINT { int x, y; };	//extern point struct
extern "C" struct LINE { POINT pointA, pointB; };	//extern line struct
extern "C" bool setupValidRectanglePoints(LINE, LINE, LINE, LINE);
extern "C" float findRectanglePerimeter(LINE, LINE, LINE, LINE);
extern "C" float findRectangleArea(LINE, LINE);

extern "C" LINE * generateRectangle(POINT[]);
extern "C" POINT createPoint(int, int);
extern "C" bool arePointsSame(POINT, POINT, POINT, POINT);

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
		//A angle
		TEST_METHOD(InsideAngleATest1)
		{
			int sideA = 60;
			int sideB = 60;
			int sideC = 80;
			double Expected = 48.19;
			//proper Input, output 48.19
			double Result = CosineLawAngleA(sideA, sideB, sideC);
			Assert::AreEqual(Expected, Result);
		}
		TEST_METHOD(InsideAngleATest2)
		{
			//proper input, output 60
			double Result = CosineLawAngleA(60, 60, 60);
			Assert::AreEqual(60.0, Result);
		}
		TEST_METHOD(InsideAngleATest3)
		{
			//improper input
			double Result = CosineLawAngleA(-10, -2, 11);
			Assert::AreEqual(124.62, Result);
		}
		TEST_METHOD(InsideAngleATest4)
		{
			//proper input 27.27
			double Result = CosineLawAngleA(7, 12, 15);
			Assert::AreEqual(27.27, Result);
		}
		//B angle
		TEST_METHOD(InsideAngleBTest1)
		{
			//proper Input, output 48.19
			double Result = CosineLawAngleB(60, 60, 80);
			Assert::AreEqual(48.19, Result);
		}
		TEST_METHOD(InsideAngleBTest2)
		{
			//proper input, output 60
			double Result = CosineLawAngleB(60, 60, 60);
			Assert::AreEqual(60.0, Result);
		}
		TEST_METHOD(InsideAngleBTest3)
		{
			//improper input 96.52
			double Result = CosineLawAngleB(-10, -2, 11);
			Assert::AreEqual(170.53, Result);
		}
		TEST_METHOD(InsideAngleBTest4)
		{
			//proper input
			double Result = CosineLawAngleB(7, 12, 15);
			Assert::AreEqual(51.75, Result);
		}
		// C Angle
		TEST_METHOD(InsideAngleCTest1)
		{
			//proper Input, output 83.62
			double Result = CosineLawAngleC(60, 60, 80);
			Assert::AreEqual(83.62, Result);
		}
		TEST_METHOD(InsideAngleCTest2)
		{
			//proper input, output 60
			double Result = CosineLawAngleC(60, 60, 60);
			Assert::AreEqual(60.0, Result);
		}
		TEST_METHOD(InsideAngleCTest3)
		{
			//improper input error
			double Result = CosineLawAngleC(-10, -2, 11);
			Assert::AreEqual(115.15, Result);
		}
		TEST_METHOD(InsideAngleCTest4)
		{
			//proper input
			double Result = CosineLawAngleC(7, 12, 15);
			Assert::AreEqual(100.98, Result);
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
			Assert::IsTrue(setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]));


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

			Assert::IsTrue(setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]));

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

			Assert::IsFalse(setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]));

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

			Assert::IsFalse(setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]));

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

			Assert::IsFalse(setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]));
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


			Assert::IsFalse(setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]));
		}
		TEST_METHOD(setupValidRectanglePoints_7) //validate rectangle for a slanted square
		{
			LINE lines[4];

			lines[0].pointA.x = 3;
			lines[0].pointA.y = 3;
			lines[0].pointB.x = 4;
			lines[0].pointB.y = 1;

			lines[1].pointA.x = 4;
			lines[1].pointA.y = 1;
			lines[1].pointB.x = 2;
			lines[1].pointB.y = 0;

			lines[2].pointA.x = 2;
			lines[2].pointA.y = 0;
			lines[2].pointB.x = 1;
			lines[2].pointB.y = 2;

			lines[3].pointA.x = 1;
			lines[3].pointA.y = 2;
			lines[3].pointB.x = 3;
			lines[3].pointB.y = 3;


			Assert::IsTrue(setupValidRectanglePoints(lines[0], lines[1], lines[2], lines[3]));
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

		TEST_METHOD(generateRectangle_Returnlines)	//generateRectangle test (rectangle; random order)
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
<<<<<<< HEAD

=======
			
>>>>>>> 06adc0930ba44646799e810dea7ce78c540b6209
			//call function that takes points as an input
			LINE* Lines = generateRectangle(points);
			//points are rearranged and lines are created
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
		TEST_METHOD(generateRectangle_Returnlines2)	//generateRectangle test (quadrilateral; random order)
		{
			POINT points[4];
			POINT p;
			p.x = -4;
			p.y = -2;
			points[0] = p;
			p.x = 4;
			p.y = 4;
			points[1] = p;
			p.x = -5;
			p.y = -2;
			points[2] = p;
			p.x = 1;
			p.y = 6;
			points[3] = p;

			//call function that takes points as an input
			LINE* Lines = generateRectangle(points);
			//points are rearranged and lines are created
			Assert::AreEqual(-5, Lines[0].pointA.x);
			Assert::AreEqual(-2, Lines[0].pointA.y);
			Assert::AreEqual(-4, Lines[0].pointB.x);
			Assert::AreEqual(-2, Lines[0].pointB.y);
			Assert::AreEqual(-4, Lines[1].pointA.x);
			Assert::AreEqual(-2, Lines[1].pointA.y);
			Assert::AreEqual(4, Lines[1].pointB.x);
			Assert::AreEqual(4, Lines[1].pointB.y);
			Assert::AreEqual(4, Lines[2].pointA.x);
			Assert::AreEqual(4, Lines[2].pointA.y);
			Assert::AreEqual(1, Lines[2].pointB.x);
			Assert::AreEqual(6, Lines[2].pointB.y);
			Assert::AreEqual(1, Lines[3].pointA.x);
			Assert::AreEqual(6, Lines[3].pointA.y);
			Assert::AreEqual(-5, Lines[3].pointB.x);
			Assert::AreEqual(-2, Lines[3].pointB.y);
		}
		TEST_METHOD(generateRectangle_Returnlines3)	//generateRectangle test (duplicate)
		{
			POINT points[4];
			POINT p;
			p.x = 0;
			p.y = 0;
			points[0] = p;
			p.x = 0;
			p.y = 0;
			points[1] = p;
			p.x = 0;
			p.y = 0;
			points[2] = p;
			p.x = 0;
			p.y = 0;
			points[3] = p;

			//call function that takes points as an input
			LINE* Lines = generateRectangle(points);
			//points are rearranged and lines are created
			Assert::AreEqual(0, Lines[0].pointA.x);
			Assert::AreEqual(0, Lines[0].pointA.y);
			Assert::AreEqual(0, Lines[0].pointB.x);
			Assert::AreEqual(0, Lines[0].pointB.y);
			Assert::AreEqual(0, Lines[1].pointA.x);
			Assert::AreEqual(0, Lines[1].pointA.y);
			Assert::AreEqual(0, Lines[1].pointB.x);
			Assert::AreEqual(0, Lines[1].pointB.y);
			Assert::AreEqual(0, Lines[2].pointA.x);
			Assert::AreEqual(0, Lines[2].pointA.y);
			Assert::AreEqual(0, Lines[2].pointB.x);
			Assert::AreEqual(0, Lines[2].pointB.y);
			Assert::AreEqual(0, Lines[3].pointA.x);
			Assert::AreEqual(0, Lines[3].pointA.y);
			Assert::AreEqual(0, Lines[3].pointB.x);
			Assert::AreEqual(0, Lines[3].pointB.y);
		}
		TEST_METHOD(generateRectangle_Returnlines4)	//generateRectangle test (quadrilateral; large numbers; random order)
		{
			POINT points[4];
			POINT p;
			p.x = 123;
			p.y = 203;
			points[0] = p;
			p.x = -12;
			p.y = -23;
			points[1] = p;
			p.x = 234;
			p.y = -2;
			points[2] = p;
			p.x = -41;
			p.y = 250;
			points[3] = p;

			//call function that takes points as an input
			LINE* Lines = generateRectangle(points);
			//points are rearranged and lines are created
			Assert::AreEqual(-12, Lines[0].pointA.x);
			Assert::AreEqual(-23, Lines[0].pointA.y);
			Assert::AreEqual(234, Lines[0].pointB.x);
			Assert::AreEqual(-2, Lines[0].pointB.y);
			Assert::AreEqual(234, Lines[1].pointA.x);
			Assert::AreEqual(-2, Lines[1].pointA.y);
			Assert::AreEqual(123, Lines[1].pointB.x);
			Assert::AreEqual(203, Lines[1].pointB.y);
			Assert::AreEqual(123, Lines[2].pointA.x);
			Assert::AreEqual(203, Lines[2].pointA.y);
			Assert::AreEqual(-41, Lines[2].pointB.x);
			Assert::AreEqual(250, Lines[2].pointB.y);
			Assert::AreEqual(-41, Lines[3].pointA.x);
			Assert::AreEqual(250, Lines[3].pointA.y);
			Assert::AreEqual(-12, Lines[3].pointB.x);
			Assert::AreEqual(-23, Lines[3].pointB.y);
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