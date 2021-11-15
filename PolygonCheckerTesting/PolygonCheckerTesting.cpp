#include "pch.h"
#include "CppUnitTest.h"
extern "C" char* analyzeTriangle(int, int, int);
extern "C" void AngleSolver(int, int, int);
extern "C" double CosineLawAngleA(int, int, int);
extern "C" double CosineLawAngleB(int, int, int);
extern "C" double CosineLawAngleC(int, int, int);
extern "C" bool setupValidRectanglePoints(LINE, LINE, LINE, LINE);




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTesting
{
	TEST_CLASS(PolygonCheckerTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};
}
