#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution414
{
#pragma region Paste to execute 
	/*
	#include "Easy\0414.Third_Maximum_Number.cpp"
	using namespace Solution414;

	int main()
	{

		Solution414::Third_Maximum_Number useClass;
		Solution414::Third_Maximum_Number::Third_Maximum_Number_Model getTestModel = useClass.GetTestData001();
		bool result = useClass.fizzBuzz(getTestModel.s, getTestModel.s);

		getTestModel = useClass.GetTestData002();
		bool result = useClass.fizzBuzz(getTestModel.s, getTestModel.s);

		getTestModel = useClass.GetTestData003();
		bool result = useClass.fizzBuzz(getTestModel.s, getTestModel.s);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 第三個最大數
	/// </summary>
	class Third_Maximum_Number
	{
#pragma region Model
	public:
		class Third_Maximum_Number_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 先排序，由後往前，找第三種數
		///       Runtime :   0 ms Beats 100 %
		///  Memory Usage : 9.1 MB Beats 79.15 %
		/// </summary>
		int thirdMax(vector<int>& nums) {
			//1. 先排序
			sort(nums.begin(), nums.end());

			int index = nums.size() - 1;
			int count = 1;			
			
			//2. 由後面往前找第三個distinct()的值
			for (index = index - 1; index >= 0 && count < 3; index--)
			{
				if (nums[index] != nums[index + 1])				
					count++;				
			}
			//3. 沒有就回傳最大的數，若有回傳題目的要求
			return count == 3 ? nums[index + 1] : nums[nums.size() - 1];
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Third_Maximum_Number_Model GetTestData001(void)
		{
			Third_Maximum_Number_Model result;
			result.nums = { 3,2,1 };
			return result;//expect :1
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Third_Maximum_Number_Model GetTestData002(void)
		{
			Third_Maximum_Number_Model result;
			result.nums = { 1 , 2 };
			return result;//expect :2
		};
		/// <summary>
		/// 測試資料2
		/// </summary>   
		Third_Maximum_Number_Model GetTestData003(void)
		{
			Third_Maximum_Number_Model result;
			result.nums = { 2,2,3,1 };
			return result;//expect : 1
		};
#pragma endregion TestData
	};
}