#include "stdafx.h"
#include "CppUnitTest.h"
#include "NQueen.h"
#include <vector>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitNQueen)
	{
	public:
		
		TEST_METHOD(TestKill)
		{
		    vector<vector<bool>> matrix = 
			{
				{ true, false, false },
			    { false, false, true },
			    { false, true, false }
			};

			Assert::IsFalse(checkIfKill(matrix));

			matrix = //row kill
			{
				{ true, false, true },
				{ false, false, false },
				{ false, true, false }
			};

			Assert::IsTrue(checkIfKill(matrix));

			matrix = //collumn kill
			{
				{ true, false, false },
				{ false, false, true },
				{ true, false, false }
			};

			Assert::IsTrue(checkIfKill(matrix));

			matrix = //diagonal kill
			{
				{ true, false, false },
				{ false, true, false },
				{ false, false, true }
			};

			Assert::IsTrue(checkIfKill(matrix));
		}

		TEST_METHOD(TestNQueen)
		{
			vector<vector<bool>> matrix =
			{
				{ false, false, false },
				{ false, false, false },
				{ false, false, false }
			};

			Assert::IsTrue(do_nQueen(matrix, 3, 0));

			int nQueen(0);
			for (size_t i = 0; i < matrix.size(); i++)
			{
				for (size_t j = 0; j < matrix.size(); j++)
				{
					if (matrix[i][j]) ++nQueen;
				}
			}

			Assert::IsTrue(nQueen == 3);
			Assert::IsFalse(checkIfKill(matrix));
		}
	};
}