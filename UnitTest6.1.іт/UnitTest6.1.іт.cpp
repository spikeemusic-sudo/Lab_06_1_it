#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1_іт/Lab_06_1_іт.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab61
{
	TEST_CLASS(UnitTestLab61)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Тестовий масив з 5 елементів
			int a[5] = { 4, -3, 10, 5, 6 };

			// Від'ємні або непарні елементи тут: -3 та 5 (всього 2 елементи, сума = 2)
			int count = Count(a, 5);
			int sum = Sum(a, 5);

			// Перевірка кількості та суми
			Assert::AreEqual(2, count);
			Assert::AreEqual(2, sum);

			// Перевірка заміни елементів нулями
			ZeroElements(a, 5);
			Assert::AreEqual(0, a[1]); // -3 перетворилося на 0
			Assert::AreEqual(0, a[3]); // 5 перетворилося на 0
		}
	};
}