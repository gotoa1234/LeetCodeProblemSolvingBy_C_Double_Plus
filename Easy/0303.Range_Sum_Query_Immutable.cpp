#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace Solution303
{
#pragma region Paste to execute 
	/*
	vector<int> teemp = { -2, 0, 3, -5, 2, -1};
	Solution303::NumArray useClass(teemp);
	auto get = useClass.sumRange(2, 5);
	return 0;
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// nim 遊戲
	/// </summary>
	class NumArray
	{
#pragma region Model
	public:
#pragma endregion Model

#pragma region Main
	public:
		vector<int> _accumulation{};
		/// <summary>
		///          思路 : 利用數學特性，先把每一種可能累加起來
		///                  {-2, 0, 3, -5, 2, -1 }  轉化成 => { -2, -2, 1, -4, -2, -3} (當前 = 當前 + 前次)
		///                  當求 (2,5) 時 可以取這兩個值得出結果(-3) - (-2) = -1 ※看left 的前一個，如果left前一個沒有就是0只看right
		///       Runtime : 19 ms Beats 96.33 %
		///  Memory Usage : 17 MB Beats 82.47 %
		/// </summary>
		NumArray(vector<int>& nums) {
			int total = 0;
			for (auto num : nums) {
				total += num;
				_accumulation.push_back(total);
			}		
		}

		int sumRange(int left, int right) {
			if (left == 0)
				return _accumulation[right];
			return _accumulation[right] - _accumulation[left - 1];
		}
#pragma endregion Main

#pragma region TestData
	public:
		///// <summary>
		///// 測試資料1
		///// </summary>        
		//Range_Sum_Query_Immutable GetTestData001(void)
		//{
		//	Range_Sum_Query_Immutable result;
		//	result.n = 4;
		//	return result;//expect : false
		//};

		///// <summary>
		///// 測試資料2
		///// </summary>   
		//Range_Sum_Query_Immutable GetTestData002(void)
		//{
		//	Range_Sum_Query_Immutable result;
		//	result.n = 1;
		//	return result;//expect: true
		//};
#pragma endregion TestData
	};
}