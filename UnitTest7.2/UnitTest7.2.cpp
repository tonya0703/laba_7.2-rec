#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_7.2 рек/7.2 рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 5;
            const int k = 3;
            const int Low = -21;
            const int High = 20;

            int** a = new int* [n];
            for (int i = 0; i < n; ++i) {
                a[i] = new int[k];
            }

            CreateRows(a, n, k, Low, High, 0);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < k; ++j) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High, L"Value is not in the Range");
                }
            }
            for (int i = 0; i < n; ++i) {
                delete[] a[i];
            }
            delete[] a;

		}
	};
}
