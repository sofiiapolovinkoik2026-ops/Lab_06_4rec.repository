#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4rec/Lab_06_4rec.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRec
{
	TEST_CLASS(UnitTestRec)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int size = 5;
			double arr[size] = { 2.0, -15.0, 10.0, 3.0, -5.0 };

			// 1.1. Кількість елементів у діапазоні [1.0, 11.0] -> 3 елементи (2.0, 10.0, 3.0)
			Assert::AreEqual(3, CountInRangeRec(arr, size, 1.0, 11.0));

			// 1.2. Сума елементів після Max (Max = 10.0, після нього: 3.0 + (-5.0) = -2.0)
			Assert::AreEqual(-2.0, SumAfterMaxRec(arr, size), 0.0001);

			// 2. Перевірка рекурсивного сортування парних індексів (0, 2, 4) за спаданням модулів
			SortEvenIndicesByAbsDescRec(arr, size);
			Assert::AreEqual(10.0, arr[0]);
			Assert::AreEqual(-15.0, arr[1]); // Непарні індекси залишаються без змін
			Assert::AreEqual(-5.0, arr[2]);
			Assert::AreEqual(3.0, arr[3]);   // Непарні індекси залишаються без змін
			Assert::AreEqual(2.0, arr[4]);
		}
	};
}