#include "stdafx.h"
#include "CppUnitTest.h"
#include "../RationalLib/Rational.h"
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::string;

namespace RationalTest {
	TEST_CLASS(RationalTest) {
	public:
		TEST_METHOD(TestConstructor) {
			Rational x;
			Rational result(0, 1);
			Assert::IsTrue(x == result);

			x = Rational(1);
			result = Rational(1, 1);
			Assert::IsTrue(x == result);
		}

		TEST_METHOD(TestLeastCommonDenominator) {
			Rational x(1, 2);
			Rational y(2, 3);
			long result = Rational::calcLeastCommonDenominator(x, y);
			Assert::IsTrue(result == 6);
		}

		TEST_METHOD(TestGreatestCommonDivisor) {
			int result = Rational::calcGreatestCommonDivisor(54, 24);
			Assert::IsTrue(result == 6);
		}

		TEST_METHOD(TestLeastCommonMultiple) {
			int result = Rational::calcLeastCommonMultiple(4, 6);
			Assert::IsTrue(result == 12);
			result = Rational::calcLeastCommonMultiple(2, 4);
			Assert::IsTrue(result == 4);
		}

		TEST_METHOD(TestToString) {
			Rational x(1, 2);
			string expectedString = "1/2";
			Assert::AreEqual(x(), expectedString);
		}

		TEST_METHOD(TestReduce) {
			Rational x(2, 4);
			Rational y(1, 2);
			Assert::IsTrue(x == y);
			x = Rational(2, 6);
			y = Rational(1, 3);
			Assert::IsTrue(x == y);
		}

		TEST_METHOD(TestPostfixIncrement) {
			Rational x(1, 2);
			Rational y(3, 2);
			x = x++;
			Assert::IsTrue(x == y);
		}

		TEST_METHOD(TestPostfixDecrement) {
			Rational x(3, 2);
			Rational y(1, 2);
			x = x--;
			Assert::IsTrue(x == y);
		}

		TEST_METHOD(TestPrefixIncrement) {
			Rational x(1, 2);
			Rational y(3, 2);
			++x;
			Assert::IsTrue(x == y);
		}

		TEST_METHOD(TestPrefixDecrement) {
			Rational x(3, 2);
			Rational y(1, 2);
			--x;
			Assert::IsTrue(x == y);
		}

		TEST_METHOD(TestPlusEquals) {
			Rational x(1, 2);
			Rational y(1, 2);
			Rational expected(1, 1);
			Rational actual = x += y;
			Assert::IsTrue(actual == expected);

			x = Rational(1, 2);
			y = Rational(1, 4);
			expected = Rational(3, 4);
			actual = x += y;
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMinusEquals) {
			Rational x(1, 1);
			Rational y(1, 1);
			Rational expected(0, 1);
			Rational actual = x -= y;
			Assert::IsTrue(actual == expected);

			x = Rational(1, 4);
			y = Rational(1, 2);
			expected = Rational(1, 4);
			actual = x -= y;
			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(TestMultiplyEquals) {
			Rational x(2, 1);
			Rational y(2, 1);
			Rational result(4, 1);
			Rational actual = x *= y;
			Assert::IsTrue(actual == result);
		}

		TEST_METHOD(TestDivideEquals) {
			Rational x(4, 1);
			Rational y(2, 1);
			Rational result(2, 1);
			Rational actual = x /= y;
			Assert::IsTrue(actual == result);
		}

		TEST_METHOD(TestCastToDouble) {
			Rational x(1, 2);
			Assert::AreEqual(double(x), .5);
		}

		TEST_METHOD(TestAssignment) {
			Rational x(3, 2);
			Rational y(1, 2);
			x = y;
			Assert::IsTrue(x == y);
		}

		TEST_METHOD(TestAdd) {
			Rational x(1, 2);
			Rational y(1, 2);
			Rational result(1, 1);
			Assert::IsTrue(x + y == result);

			x = Rational(1, 2);
			y = Rational(1, 4);
			result = Rational(3, 4);
			Assert::IsTrue(x + y == result);
		}

		TEST_METHOD(TestSubtract) {
			Rational x(1, 1);
			Rational y(1, 1);
			Rational result(0, 1);
			Assert::IsTrue(x - y == result);

			x = Rational(1, 2);
			y = Rational(1, 4);
			result = Rational(1, 4);
			Assert::IsTrue(x - y == result);
		}

		TEST_METHOD(TestMultiply) {
			Rational x(2, 1);
			Rational y(2, 1);
			Rational result(4, 1);
			Assert::IsTrue(x * y == result);
		}

		TEST_METHOD(TestDivide) {
			Rational x(4, 1);
			Rational y(2, 1);
			Rational result(2, 1);
			Assert::IsTrue(x / y == result);
		}

		TEST_METHOD(TestGreaterThan) {
			Rational x(1, 2);
			Rational y(1, 4);
			Assert::IsTrue(x > y);
		}

		TEST_METHOD(TestLessThan) {
			Rational x(1, 2);
			Rational y(1, 4);
			Assert::IsTrue(y < x);
		}

		TEST_METHOD(TestGreaterThanOrEquals) {
			Rational x(1, 2);
			Rational y(1, 4);
			Assert::IsTrue(x > y);

			x = Rational(1, 2);
			y = Rational(1, 2);
			Assert::IsTrue(x >= y);
		}

		TEST_METHOD(TestLessThatOrEquals) {
			Rational x(1, 2);
			Rational y(1, 4);
			Assert::IsTrue(y < x);

			x = Rational(1, 2);
			y = Rational(1, 2);
			Assert::IsTrue(x >= y);
		}

		TEST_METHOD(TestBooleanEquals) {
			Rational x(1, 2);
			Rational y(1, 2);
			Assert::IsTrue(x == y);
		}

		TEST_METHOD(TestBooleanNotEquals) {
			Rational x(1, 3);
			Rational y(1, 2);
			Assert::IsTrue(x != y);
		}

		TEST_METHOD(TestExponential) {

		}

		TEST_METHOD(TestStreamInsertion) {

		}

		TEST_METHOD(TestStreamExtraction) {

		}
	};
}
