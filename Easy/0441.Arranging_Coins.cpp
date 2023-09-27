#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution441
{
#pragma region Paste to execute 
	/*
	#include "Easy\0441.Arranging_Coins.cpp"
	using namespace Solution441;

	int main()
	{
		Solution441::Arranging_Coins useClass;
		Solution441::Arranging_Coins::Arranging_Coins_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.arrangeCoins(getTestModel.n);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.arrangeCoins(getTestModel.n);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 硬幣區間
	/// </summary>
	class Arranging_Coins
	{
#pragma region Model
	public:
		class Arranging_Coins_Model
		{
		public:
			int n;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 利用二分搜尋法，找出 0 ~ n 之間對應的區間
		///       Runtime :    0 ms Beats 100.0 %
		///  Memory Usage :	6.28 MB Beats 29.98 %
		/// </summary>
		int arrangeCoins(int n) {			
			long leftValue = 0;
		    long rightValue = n;
			long midValue = 0;
			long total = 0;
			while (leftValue <= rightValue)
			{
				midValue = leftValue + (rightValue - leftValue) / 2;
				total = midValue * (midValue + 1) / 2;
				if (total == n) 
					return midValue;

				if (total > n)
				{
					rightValue = midValue - 1;
				}
				else
				{
					leftValue = midValue + 1;
				}
			}
			return leftValue - 1;
			/*
		    0  1
			1  2  3
			2  4  5  6
			3  7  8  9 10
			4 11 12 13 14 15
			5 16 17 18 19 20 21
			*/
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Arranging_Coins_Model GetTestData001(void)
		{
			Arranging_Coins_Model result;
			result.n = 8;			
			return result;//expect : 3
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Arranging_Coins_Model GetTestData002(void)
		{
			Arranging_Coins_Model result;
			result.n = 5;
			return result;//expect : 2
		};

#pragma endregion TestData
	};
}