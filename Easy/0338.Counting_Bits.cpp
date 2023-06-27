#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace Solution338
{
#pragma region Paste to execute 
	/*
#include <unordered_map>
#include "Easy/0338.Counting_Bits.cpp"
using namespace Solution338;

int main()
{

	using namespace std;

	Solution338::Counting_Bits useClass;
	Solution338::Counting_Bits::Counting_Bits_Model getTestModel = useClass.GetTestData001();
	auto result1 = useClass.countBits(getTestModel.n);

	getTestModel = useClass.GetTestData002();
	auto result2 = useClass.countBits(getTestModel.n);
}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 計算bit數
	/// </summary>
	class Counting_Bits
	{
#pragma region Model
	public:
		class Counting_Bits_Model
		{
		public:
			int n;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :利用數學的規律解此題，在輸入為1的時候需進行2^0個以前的所有數值+1 (只有 [0])
		///                                      在輸入為2的時候需進行2^1個以前的所有數值+1 ([0], [1])
		///                二進位    輸入n   所需重複的數量
		///                    0        0
		///                   01        1 --- 2^0
		///                   10        2
		///                   11        3 --- 2^1
		///                  100        4
		///                  101        5
		///                  110        6  
		///                  111        7 --- 2^2 
		///                 1000        8   
		///       Runtime :  3 ms Beats 96.69 %
		///  Memory Usage :7.7 MB Beats	88.75 %
		/// </summary>
		vector<int> countBits(int n)
		{
            vector<int> result(n + 1, 0);			
			//1. 設定2進位
			int binary = 0;
			for (int index = 1; index <= n; binary++)
			{
				//2-1. 本次計算數
				int currentLength = pow(2, binary);
				for (int innerIndex = 0; 
					 innerIndex < currentLength && index <= n; 
					 innerIndex++, index++)
				{
					//2-2. +1
					result[index] = result[innerIndex] + 1;
				}
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Counting_Bits_Model GetTestData001(void)
		{
			Counting_Bits_Model result;
			result.n = 2;
			return result;//expect : [0,1,1]
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Counting_Bits_Model GetTestData002(void)
		{
			Counting_Bits_Model result;
			result.n = 5;
			return result;//expect: [0,1,1,2,1,2]
		};
#pragma endregion TestData
	};
}