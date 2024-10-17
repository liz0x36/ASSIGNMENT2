#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>

extern "C" int getArea(int*, int*);
extern "C" int getPerimeter(int*, int*);
extern "C" void setLength(int, int*);
extern "C" void setWidth(int, int*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// 1 unit test each for perimeter and area
// 3 for length and width. normal, negative, zero?

namespace UnitTests{
	TEST_CLASS(UnitTests){
	public:
		TEST_METHOD(perimeterTest_length4width5_return18){
			int actualPerimeter, length = 4, width = 5;
			actualPerimeter = getPerimeter(&length, &width);
			Assert::AreEqual(18, actualPerimeter);
		}
		TEST_METHOD(areaTest_length2width4_return8) {
			int actualArea, length = 2, width = 4;
			actualArea = getArea(&length, &width);
			Assert::AreEqual(8, actualArea);
		}
		TEST_METHOD(setLengthTest1_length4_returnValidInput) {
			int testLength = 4;
			setLength(4, &testLength);
			Assert::AreEqual(4, testLength);
		}
		TEST_METHOD(setLengthTest2_length100_returnInvalidInput) {
			int testLength = 10;
			setLength(100, &testLength);
			Assert::AreEqual(10, testLength);
		}
		TEST_METHOD(setLengthTest3_lengthNegative7_returnInvalidInput) {
			int testLength = 10;
			setLength(-7, &testLength);
			Assert::AreEqual(10, testLength);
		}
		TEST_METHOD(setWidthTest1_width6_returnValidInput) {
			int testWidth = 6;
			setWidth(6, &testWidth);
			Assert::AreEqual(6, testWidth);
		}
		TEST_METHOD(setWidthTest2_width100_returnInvalidInput) {
			int testWidth = 15;
			setWidth(100, &testWidth);
			Assert::AreEqual(15, testWidth);
		}
		TEST_METHOD(setWidthTest3_widthNegative4_returnInvalidInput) {
			int testWidth = 5;
			setWidth(-4, &testWidth);
			Assert::AreEqual(5, testWidth);
		}
	};
}
