#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution561
{
#pragma region Paste to execute 
	/*
	#include "Easy\0561.Array_Partition.cpp"
	using namespace Solution561;

	int main()
	{
		Solution561::Array_Partition useClass;
		Solution561::Array_Partition::Array_Partition_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.arrayPairSum(getTestModel.nums);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.arrayPairSum(getTestModel.nums);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// Array 切割
	/// </summary>
	class Array_Partition
	{
#pragma region Model
	public:
		class Array_Partition_Model
		{
		public:
			vector<int>  nums;
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :表面上是所有元素做2個一組的排列組合，然後每個組合內的最小值加總，選出最大的
		///                實際上，先由小而大排序，然後2個一組將小的那個值累加即為最大結果		
		///       Runtime :   38 ms Beats 75.13 %
		///  Memory Usage :	28.5 MB Beats 30.72 %
		/// </summary>
		int arrayPairSum(vector<int>& nums) {
			int result = 0;
			sort(nums.begin(), nums.end());
			for (int index = 0; index < nums.size(); index += 2)
			{
				result += nums[index];
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Array_Partition_Model GetTestData001(void)
		{
			Array_Partition_Model result;
			result.nums = { 1, 4, 3, 2};
			return result;//expect : 4
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Array_Partition_Model GetTestData002(void)
		{
			Array_Partition_Model result;
			result.nums = { 6, 2, 6, 5, 1, 2 };
			return result;//expect : 9
		};

#pragma endregion TestData
	};
}