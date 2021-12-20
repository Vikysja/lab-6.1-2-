#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest612
{
	TEST_CLASS(UnitTest612)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int c[n] = { 87, 52, 65, 30, 46, 23, 24, 70, 33, 76 };

			int sum = 0;
			int count = 0;

			int expectedSum = 0 + 52 + 65 + 30 + 46 + 23 + 24 + 70 + 0 + 76;

			Processing(c, n, sum, count, 0);

			Assert::AreEqual(expectedSum, sum);
		}
	};
}
