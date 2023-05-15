#include <iostream>
#include <unordered_map>
using namespace std;

namespace Solution268
{
#pragma region Paste to execute 
	/*
	#include "Easy\0268.Missing_Number.cpp"
	using namespace Solution268;

	int main()
	{

		Solution268::Missing_Number useClass;
		Solution268::Missing_Number::Missing_Number_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.missingNumber(getTestModel.nums);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 遺失的數值
	/// </summary>
	class Missing_Number
	{
#pragma region Model
	public:
		class Missing_Number_Model
		{
		public:
			vector<int> nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 : 散列的做法，效能沒有比較快，但同樣達到O(n)的結果，浪費效能再排序上
		///       Runtime :   24 ms Beats 43.4 %
		///  Memory Usage : 17.9 MB Beats 93.63 %
		/// </summary>
		int missingNumber(vector<int>& nums) 
		{
			for (int index = 0; index < nums.size(); index++)
			{
				while (nums[index] >= 0 &&
					nums[index] < nums.size() &&
					index != nums[index] &&
					nums[index] != nums[nums[index]])
				{
					swap(nums[index], nums[nums[index]]);
				}
			}

			for (int index = 0; index < nums.size(); index++)
			{
				if (nums[index] != index)
					return index;
			}
			return nums.size();
		}

		/// <summary>
		///          思路 : 利用題目的特性給定n 個數字，缺的必定是n中的某個數字。
		///                 因此利用索引從0 ~ n 如果有出現不匹配的數值就是答案
		///       Runtime :   15 ms Beats 90.63 %
		///  Memory Usage : 17.9 MB Beats 93.63 %
		/// </summary>
		int missingNumber_Right(vector<int>& nums)
		{
			int result = 0;
			for (int index = 0; index < nums.size(); index++) {
				result ^= (index + 1) ^ nums[index];
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Missing_Number_Model GetTestData001(void)
		{
			Missing_Number_Model result;
			result.nums = { 3,0,1 };
			return result;//expect : 2
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Missing_Number_Model GetTestData002(void)
		{
			Missing_Number_Model result;
			result.nums = { 0,1 };
			return result;//expect : 2
		};

		/// <summary>
		/// test 3
		/// </summary>   
		Missing_Number_Model GetTestData003(void)
		{
			Missing_Number_Model result;
			result.nums = { 9,6,4,2,3,5,7,0,1 };
			return result;//expect : 8
		};
#pragma endregion TestData
	};
}