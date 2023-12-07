#include <iostream>
#include <vector>
using namespace std;

namespace Solution724
{
#pragma region Paste to execute 
	/*
	#include "Easy\0724.Find_Pivot_Index.cpp"
	using namespace Solution724;
	using namespace std;

	Solution724::Find_Pivot_Index useClass;
	Solution724::Find_Pivot_Index::Find_Pivot_Index_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.myAtoi(getTestModel.x);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 查找樞軸索引
	/// </summary>
	class Find_Pivot_Index
	{
#pragma region Model
	public:
		class Find_Pivot_Index_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：先加總 => 遍歷索引，每次將總和 -當前索引值 ==  累計值 * 2  就是答案
		///      Runtime :   39 ms, faster than 52.65% of C++ online submissions for Find Pivot Index.
		/// Memory Usage : 31.2 MB,   less than 53.47% of C++ online submissions for Find Pivot Index.
		/// </summary>
		int pivotIndex(vector<int>& nums) {			
			int total{};
			//先計算加總
			for (auto& item : nums)
				total += item;

			//累計值
			int accumulate{};
			for (int index = 0; index < nums.size(); index++)
			{
				//依照題目，中間值索引不計算，但左右兩邊相等 (也就是*2)
				if (accumulate + accumulate == total - nums[index])
					return index;
				accumulate += nums[index];
			}
			return -1;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Find_Pivot_Index_Model GetTestData001(void)
		{
			Find_Pivot_Index_Model result;
			result.nums = { 1,7,3,6,5,6 };
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Find_Pivot_Index_Model GetTestData002(void)
		{
			Find_Pivot_Index_Model result;
			result.nums = { 1,2,3 };
			return result;
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Find_Pivot_Index_Model GetTestData003(void)
		{
			Find_Pivot_Index_Model result;
			result.nums = { 2,1,-1 };
			return result;
		};
#pragma endregion TestData
	};
}