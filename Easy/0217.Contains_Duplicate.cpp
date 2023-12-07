#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

namespace Solution217
{
#pragma region Paste to execute 
	/*
	#include "Easy\0217.Contains_Duplicate.cpp"
	using namespace Solution217;
	using namespace std;

	Solution217::Contains_Duplicate useClass;
	Solution217::Contains_Duplicate::Contains_Duplicate_Model getTestModel = useClass.GetTestData001();
	bool result = useClass.containsDuplicate(getTestModel.nums);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 包含重複項
	/// </summary>
	class Contains_Duplicate
	{
#pragma region Model
	public:
		class Contains_Duplicate_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 先利用排序，然後在遍歷，即可找出結果 ※排序花費：O(nlogn) + 遍歷花費：O(N)
		///       Runtime : 120 ms Beats 98.16 %
		///  Memory Usage :57.2 MB Beats 81.32 %
		/// </summary>
		bool containsDuplicate(vector<int>& nums) 
		{
			sort(nums.begin(), nums.end());
			for (int index = 1; index < nums.size(); index++)
			{
				if (nums[index] == nums[index - 1])
					return true;
			}
			return false;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Contains_Duplicate_Model GetTestData001(void)
		{
			Contains_Duplicate_Model result;
			result.nums = { 1,2,3,1 };			
			return result;// expect : true
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Contains_Duplicate_Model GetTestData002(void)
		{
			Contains_Duplicate_Model result;
			result.nums = { 1,2,3,4 };
			return result;// expect : false
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Contains_Duplicate_Model GetTestData003(void)
		{
			Contains_Duplicate_Model result;
			result.nums = { 1,1,1,3,3,4,3,2,4,2 };
			return result;// expect : true
		};
#pragma endregion TestData
	};
}