#include <iostream>
#include <vector>
using namespace std;

namespace Solution1480
{
#pragma region Paste to execute 
	/*
	#include "1480.Palindrome_Number.cpp"
	using namespace Solution1480;
	using namespace std;

	Solution1480::Running_Sum_of_1d_Array useClass;
	Solution1480::Running_Sum_of_1d_Array::Running_Sum_of_1d_Array_Model getTestModel = useClass.GetTestData001();
	vector<int> result = useClass.runningSum(getTestModel.nums);
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 一維陣列的數字總和
	/// </summary>
	class Running_Sum_of_1d_Array
	{
#pragma region Model
	public:
		class Running_Sum_of_1d_Array_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路：前一個索引是上一個索引的加總值，所以跳過第一個索引，後面逐步累加
		///      Runtime :   0 ms, faster than 100.00% of C++ online submissions for Running Sum of 1d Array.
		/// Memory Usage : 8.5 MB,   less than  75.23% of C++ online submissions for Running Sum of 1d Array.
		/// </summary>
		vector<int> runningSum(vector<int>& nums) {
			for (int index = 1; index < nums.size(); index++)
			{
				nums.at(index) += nums.at(index - 1);
			}
			return nums;
		};
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// 測試資料1
		/// </summary>        
		Running_Sum_of_1d_Array_Model GetTestData001(void)
		{
			Running_Sum_of_1d_Array_Model result;
			result.nums = { 1, 2, 3, 4 };
			return result;
		};

		/// <summary>
		/// 測試資料2
		/// </summary>   
		Running_Sum_of_1d_Array_Model GetTestData002(void)
		{
			Running_Sum_of_1d_Array_Model result;
			result.nums = { 1, 1, 1, 1, 1 };
			return result;
		};

		/// <summary>
		/// 測試資料3
		/// </summary>   
		Running_Sum_of_1d_Array_Model GetTestData003(void)
		{
			Running_Sum_of_1d_Array_Model result;
			result.nums = { 3,1,2,10,1 };
			return result;
		};
#pragma endregion TestData
	};
}