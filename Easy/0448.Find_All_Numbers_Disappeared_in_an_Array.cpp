#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

namespace Solution448
{
#pragma region Paste to execute 
	/*
	#include "Easy\0448.Find_All_Numbers_Disappeared_in_an_Array.cpp"
	using namespace Solution448;

	int main()
	{
		Solution448::Find_All_Numbers_Disappeared_in_an_Array useClass;
		Solution448::Find_All_Numbers_Disappeared_in_an_Array::Find_All_Numbers_Disappeared_in_an_Array_Model getTestModel = useClass.GetTestData001();
		auto result = useClass.addStrings(getTestModel.num1);

		getTestModel = useClass.GetTestData002();
		auto result2 = useClass.addStrings(getTestModel.nums);
	}
	*/
#pragma endregion Paste to execute

	/// <summary>
	/// 找出消失的數值陣列
	/// </summary>
	class Find_All_Numbers_Disappeared_in_an_Array
	{
#pragma region Model
	public:
		class Find_All_Numbers_Disappeared_in_an_Array_Model
		{
		public:
			vector<int> nums;			
		};
#pragma endregion Model

#pragma region Main
	public:
		/// <summary>
		///          思路 :
		///       Runtime :
		///  Memory Usage :
		/// </summary>
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			vector<int> result{};
			sort(nums.begin(), nums.end());
			
			for (int index = 0; index < nums.size(); index++)
			{
				while (
					nums[index] < nums.size() &&
					nums[index] != index && 
					nums[index] != nums[nums[index] - 1])
				{
					swap(nums[index], nums[nums[index] - 1]);
				}
			}
			for (int index = 0; index < nums.size(); index++)
			{
				if (nums[index] != index + 1)
					result.push_back(index + 1);
			}
			return result;
		}
#pragma endregion Main

#pragma region TestData
	public:
		/// <summary>
		/// test 1
		/// </summary>        
		Find_All_Numbers_Disappeared_in_an_Array_Model GetTestData001(void)
		{
			Find_All_Numbers_Disappeared_in_an_Array_Model result;
			result.nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
			return result;//expect : { 5, 6}
		};
		/// <summary>
		/// test 2
		/// </summary>   
		Find_All_Numbers_Disappeared_in_an_Array_Model GetTestData002(void)
		{
			Find_All_Numbers_Disappeared_in_an_Array_Model result;
			result.nums = { 1, 1 };			
			return result;//expect :{2}
		};

		/// <summary>
		/// test 2
		/// </summary>   
		Find_All_Numbers_Disappeared_in_an_Array_Model GetTestData003(void)
		{
			Find_All_Numbers_Disappeared_in_an_Array_Model result;
			result.nums = {5, 4, 6, 7, 9, 3, 10, 9, 5, 6};
			return result;//expect :{1, 2, 8}
		};
		

#pragma endregion TestData
	};
}